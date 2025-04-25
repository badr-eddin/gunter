#include "server.hpp"


Server::Server(unsigned short port) : io_context(), acceptor(io_context) {
    this->port = port;
    this->cpool = new ClientsPool();
}

bool Server::start() {
    try {
        logging::log_print("starting server on port " + std::to_string(this->port));

        // make an endpoint
        tcp::endpoint endpoint(tcp::v4(), port);

        acceptor.open(endpoint.protocol());

        // make server reusable
        acceptor.set_option(asio::socket_base::reuse_address(true));

        // bind address
        acceptor.bind(endpoint);

        // listen to any incomming connections
        acceptor.listen(asio::socket_base::max_listen_connections); 

        // custom treatement to incoming connections
        this->listen();

        // finally run the server
        io_context.run();

        return true;

    } catch(const std::exception &e) {
        logging::log_print("couldn't start server, " + std::string(e.what()), 2);
        return false;
    }
}

bool Server::stop() {
    // graceufully close

    // close all the connections
    this->cpool->close_all();

     // cancel all operations on the io_context
     if (this->io_context.stopped()) {
        this->io_context.restart(); // restart if it was stopped
    }

    this->io_context.stop();

    // Close the acceptor to prevent new connections
    this->acceptor.close();
    
    return true;
}

void Server::listen() {
    logging::log_print("listening for any incoming connections ...");
    

    // make a smart pointer of a socket
    std::shared_ptr<tcp::socket> client = std::make_shared<tcp::socket>(this->io_context);

    this->acceptor.async_accept(*client, [this, client](asio::error_code err_c){
        if(!err_c) {
            auto endpoint = client->remote_endpoint();

            logging::log_print(
                "connection from: " + 
                endpoint.address().to_string() + 
                ":" + 
                std::to_string(endpoint.port())
            );

            asio::post(this->io_context, [this, client]() {
                // async process connection
                this->process_connection(client);
            });
        } else {
            logging::log_print("failed to accept connection: " + err_c.message());
        }

        // immediately start accepting new connections
        this->listen();
    });

}
