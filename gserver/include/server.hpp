#pragma once
#include <cstdlib>  // using getenv for username and password
#include <vector>
#include <openssl/sha.h>
#include "asio.hpp"
#include "clientspool.hpp"
#include "mess.hpp"
#include "json.hpp"



class Server {
    public:
        Server(unsigned short);

        // configure and start the server
        bool start();

        // disconnect and close
        bool stop();

    private:
        ClientsPool *cpool = nullptr;
        unsigned short port;

        // listen for any incomming connection
        void listen();

        // if client acknowledged, else if panel: solve endpoint requested
        void process_connection(std::shared_ptr<tcp::socket>);
        
        
        std::string sha256(const std::string&);
        
        bool login_to_server(std::string, std::string);

        // TCP
        asio::io_context io_context;
        tcp::acceptor acceptor;

};

