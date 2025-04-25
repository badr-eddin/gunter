#include "server.hpp"

void Server::process_connection(std::shared_ptr<tcp::socket> client) {
    // 0 recv the request (json)
    // std::string raw_request = recv(*client);
    picojson::object request = parse_json(recv(*client));

    // 1. solve
    if (request["username"].is<std::string>() && request["tag"].is<std::string>()) {
        // 1.1 indentification struct  
        auto endpoint = client->remote_endpoint();
        
        request["ip"] = picojson::value(endpoint.address().to_string());
        request["port"] = picojson::value(static_cast<double>(endpoint.port()));

        client_t *client_obj = new client_t({
            get_uid((unsigned short)Params::UID_SIZE),  // uid
            client,  // connection
            get_time(),
            request
        });

        // 1.2 authenticate
        asio::write(*client, asio::buffer(std::string(Codes::ACK)));

        logging::log_print(
            "client connected: " 
            + request["username"].get<std::string>() 
            + "@"
            + request["tag"].get<std::string>()
        );

        // 1.3 store the connection 
        this->cpool->insert(client_obj);

        return;
    } 

    else if (
        request["path"].is<std::string>() && 
        request["password"].is<std::string>() && 
        request["username"].is<std::string>()
    ) {
        // 1.1 login
        if (this->login_to_server(request["password"].get<std::string>(), request["username"].get<std::string>())) {
            std::string req_endp = request["path"].get<std::string>();

            if (!req_endp.compare(Codes::LIST_ENDP)) {
                // list connected clients as json
                this->cpool->list(*client);

                return;
            } 
            
            else if (!req_endp.compare(Codes::CONNECT_ENDP) && request["uid"].is<std::string>()) {
                // get the uid
                std::string req_uid = request["uid"].get<std::string>();

                // make a panel struct
                Panel *panel = new Panel({client, get_time()});

                // try to connect the two connections
                this->cpool->connect(req_uid, panel);

                return;
            }

            else if (!req_endp.compare(Codes::DISCONNECT_ENDP) && request["uid"].is<std::string>()) {
                this->cpool->disconnect(request["uid"].get<std::string>());
            } 
            
            else {
                send(*client, "[{\"msg\": \"route not found!\", \"type\": \"error\"}]");
            }

        } 
        
        else {
            send(*client, "[{\"msg\": \"login failed!\", \"type\": \"error\"}]");
        }
    }
    
    else {
        send(*client, "[{\"msg\": \"invalid request!\", \"type\": \"error\"}]");
    }
    // otherwise close the connection
    client->close();
}


void ClientsPool::join(std::shared_ptr<tcp::socket> src, std::shared_ptr<tcp::socket> dst, std::string uid){
    auto buffer = std::make_shared<asio::streambuf>();

    // read from `src` to `buffer` until `terminated` 
    asio::async_read_until(*src, *buffer, Codes::MESSAGE_TERMINATOR, [=, this](const asio::error_code &ec, std::size_t brecv){
        if (!ec) {
            asio::async_write(*dst, asio::buffer(buffer->data(), brecv), [=, this](const asio::error_code &ec, std::size_t bsent) {
                if (!ec) {
                    // recurse
                    this->join(src, dst, uid);
                }
                else {
                    this->disconnect(uid);
                    logging::log_print("join/write: " + std::string(ec.message()), 2);
                }
            });
        }
        else {
            this->disconnect(uid);
            logging::log_print("join/read: " + std::string(ec.message()), 2);
        }
    });
}

void ClientsPool::async_read_write_g2p(std::shared_ptr<tcp::socket> gunter, std::shared_ptr<tcp::socket> cpanel, std::string uid) {
    // read one byte from cpanel to gunter
    join(cpanel, gunter, uid);

    // read one byte from gunter to cpanel
    join(gunter, cpanel, uid);
}

void ClientsPool::close_all() {
    // automatically closing the clients closes the panels attached too
    
    for (const auto &item : this->connected_clients) {
        item.second->connection->close();
    }
}


std::string Server::sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);

    std::stringstream ss;

    for (unsigned char c : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    return ss.str();
}

bool Server::login_to_server(std::string request_password, std::string request_username) {
    // implement more accurate and efficient login system
    const char* password = std::getenv("G_PASSWORD");
    bool same_usern = (request_username == std::getenv("G_USERNAME"));

    return (password ? this->sha256(request_password) == password : false) && same_usern;
}
