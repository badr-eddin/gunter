#pragma once

#include "mess.hpp"
#include "controller/runner.hpp"

#define LOG(x) std::cout << x << "\n"


typedef struct Credentials
{
    std::string ip = "127.0.0.1";
    std::string user = "<unknown>";
    std::string tag = "<unknown>";

    unsigned int port = 4444;
    unsigned int timeout = 5;  // sec

} credentials_t;



typedef class Gunter {
    protected:
        asio::io_context io_context;
        asio::ip::tcp::socket socket;
        credentials_t credentials;

    public:
        Gunter(const credentials_t&);

        // try to connect to the server forever until it acknowledged
        void connect();
        void disconnect();
        void reconnect(int);  // timeout
        void reconnect();

    private:
        // once connected, request acknowledgment
        void connected();

        // run forever, block receive a command, execute it and send output
        void serve();


} gunter_client_t;
