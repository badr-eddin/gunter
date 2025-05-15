#include "core/client_api.hpp"


gpanel::API::API(QObject*parent) 
    : io_context(new asio::io_context()), 
        connection(new tcp::socket(*io_context)), 
        work_guard(asio::make_work_guard(*io_context)),
        QObject(parent) {
            
    this->thread_context = new ASIOThread(this->io_context, nullptr);
}

void gpanel::API::init(QWidget*parent, server_creds_t *creds, const std::string uid) {
    this->creds = creds;
    this->uid = uid;
    this->parent_w = parent;
}

gpanel::API::~API() {
    this->io_context->stop();
    this->thread_context->quit();
    this->thread_context->wait();
    this->connection->close();
    logging::log_print("connection '" + this->uid + "' terminated!");
}


void gpanel::API::connect2() {
    if (!this->connection) {
        return;
    }

    asio::error_code err_code;

    tcp::endpoint endpoint(
        asio::ip::make_address(
            this->creds->ip, err_code
        ), 
        this->creds->port
    );

    if(err_code) {
        emit this->error_to_connect(QString::fromStdString(err_code.message()));
    }

    // try to connect to server
    std::vector<tcp::endpoint> endpoints = { endpoint };

    asio::async_connect(*(this->connection), endpoints, 
        [this](const asio::error_code& ec, const tcp::endpoint&) {
            if (!ec) {
                // make a request
                picojson::object obj_request;

                obj_request["username"] = picojson::value(this->creds->username);
                obj_request["password"] = picojson::value(this->creds->password);
                obj_request["path"] = picojson::value(Codes::CONNECT_ENDP);
                obj_request["uid"] = picojson::value(this->uid);

                const std::string raw_request = picojson::value(obj_request).serialize() + Codes::MESSAGE_TERMINATOR;

                // send the request
                asio::async_write(*(this->connection), asio::buffer(raw_request), 
                    [this](const asio::error_code &ec, std::size_t) {
                        // if no error and the connection still open, means connection made
                        this->__connected = !ec || this->connection->is_open();
            
                        if (ec) {
                            emit this->error_to_connect(QString::fromStdString(ec.message()));
                        }
                        else {
                            std::string title = this->uid;
                            picojson::object cl = this->get_client();
                            
                            if (cl["username"].is<std::string>()) {
                                title = cl["username"].get<std::string>();

                                if (cl["tag"].is<std::string>()) {
                                    title += "@" + cl["tag"].get<std::string>();
                                }
                            }
                            logging::log_print("connected to '" + this->uid + "'");
                            
                            emit this->connected(
                                this->parent_w, QString::fromStdString(title), 
                                QString::fromStdString(this->uid)
                            );
                        }
                    }
                );
            } 
            else {
                this->__connected = false;
                emit this->error_to_connect(QString::fromStdString(ec.message()));
            }
        }
    );

    // run context thread
    this->thread_context->start();    
}

void gpanel::API::handle_error(const asio::error_code&ec, exeq_callback_t callback) {
    callback(
        response_t("{\"msg\": \"" + ec.message() + "\", \"type\": \"error\"}")
    );

    // if an error occured, update 'connected' flag
    this->__connected = ec != asio::error::eof && ec != asio::error::broken_pipe && this->connection->is_open();
}

void gpanel::API::exeq(const std::string msg, const exeq_callback_t& callback) {
    if (this->__connected) {
        this->messages.push(std::pair(msg, callback));

        // start if not started executed 
        if (!this->started) {
            this->start();
        }
    } else {
        logging::log_print("attempt to send commands, but not connected", 1);
        emit this->disconnected();
    }

}

void gpanel::API::start() {
    // if empty or not connected then abort
    if (!this->__connected) {
        logging::log_print("not connected!", 2);
        this->started = false;
        emit this->disconnected();
        return;
    }

    if (this->messages.empty()) {
        this->started = false;
        return;
    }

    if (!this->thread_context->isRunning()) {
        logging::log_print("io context not running!", 2);
        return;
    }

    // set started to true anyway
    this->started = true;

    // pull next in queue and pop
    std::shared_ptr<message_q_t> next_ptr = std::make_shared<message_q_t>(this->messages.front());

    // later, maybe make this line execute after a success receive
    this->messages.pop();

    // async write
    std::string msg = next_ptr->first + Codes::MESSAGE_TERMINATOR;

    asio::async_write(*(this->connection), asio::buffer(msg), [this, next_ptr](const asio::error_code &ec, size_t sent) {
        if (!ec) {
            // keep track of sent bytes 
            this->total_bytes_sent += sent;

            // read response
            auto buffer = std::make_shared<asio::streambuf>();

            asio::async_read_until(*(this->connection), *buffer, Codes::MESSAGE_TERMINATOR, 
                [buffer, next_ptr, this](const asio::error_code& ec, std::size_t rcvd){
                    if (!ec) {
                        // keep track of received bytes
                        this->total_bytes_received += rcvd;

                        std::istream is(buffer.get());
                        std::string response;
                        std::getline(is, response, Codes::MESSAGE_TERMINATOR);
                        next_ptr->second(response_t(response));
                    } 
                    else {
                        this->handle_error(ec, next_ptr->second);
                    }
            
                    this->start();
                }
        );

        } else {            
            this->handle_error(ec, next_ptr->second);
        }

        // if couldn't send start again, otherwise the recv will recusre
        this->start();
    });
}


unsigned short gpanel::API::count() { return this->messages.size(); }
size_t gpanel::API::bsent() { return this->total_bytes_sent; }
size_t gpanel::API::breceived() { return this->total_bytes_received; }

void gpanel::API::set_client(picojson::object cl) { this->client = cl; }

picojson::object gpanel::API::get_client() { return this->client; }


// ensure that the io context runs on separate thread + extend it lifetime
gpanel::ASIOThread::ASIOThread(asio::io_context* ctx, QObject* parent = nullptr) : QThread(parent), io_context(ctx),
  work_guard(asio::make_work_guard(*ctx)) {}

void gpanel::ASIOThread::run()  {
    io_context->run();
}
