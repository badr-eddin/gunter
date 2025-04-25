#include "server.hpp"


void ClientsPool::disconnect(std::string guid) {
    
    if (this->connected_duos.find(guid) != this->connected_duos.end()) {
        // close the cpanel connection
        this->connected_duos[guid]->connection->close();

        // remove the item 
        this->connected_duos.erase(guid);

        if (this->connected_clients.find(guid) != this->connected_clients.end()) {
            // close the client connection
            this->connected_clients[guid]->connection->close();

            // remove the item
            this->connected_clients.erase(guid);

            logging::log_print("a panel disconnected from: " + guid);

        }
    }
}

void ClientsPool::connect(std::string guid, panel_t *cpanel) {
    // check if the uid exists and not connected
    if (this->connected_clients.find(guid) == this->connected_clients.end()) {
        // close the connection
        cpanel->connection->close();
    }
    // if not close the panel's connection 
    else {
        std::shared_ptr<tcp::socket> xcl = this->connected_clients[guid]->connection;

        this->async_read_write_g2p(xcl, cpanel->connection, guid);

        logging::log_print(
            cpanel->connection->remote_endpoint().address().to_string() + 
            "->" +
            xcl->remote_endpoint().address().to_string()
        ); 

        this->connected_duos[guid] = cpanel;
    }
}

void ClientsPool::list(tcp::socket &client) {
    picojson::array connected;
    
    for (const auto &item : this->connected_clients) {
        // if the client is connected to a certain gpanel, it should not be listed
        if (this->connected_duos.find(item.first) != this->connected_duos.end()) {
            continue;
        }

        picojson::object client_obj = item.second->client;
        client_obj["uid"] = picojson::value(item.second->uid);
        client_obj["timestamp"] = picojson::value(item.second->time);
        connected.push_back(picojson::value(client_obj));
    }

    // dump JSON to string
    std::string response = picojson::value(connected).serialize();

    // send
    if (!send(client, response)) {
        logging::log_print("error at endpoints/list 0 bytes sent!", 2);
    } else {
        logging::log_print("connected items listed");
    }
}
