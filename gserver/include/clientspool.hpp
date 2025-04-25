/*defines a structure to store the clients along side with it info*/
#pragma once
#define DEBUG


#include <map>
#include <memory>
#include "utils.hpp"
#include "defs.hpp"
#include "asio.hpp"
#include "json.hpp"
#include "logging.hpp"

using asio::ip::tcp;


typedef struct Client {
    std::string uid = "<unknown>";

    std::shared_ptr<tcp::socket> connection;
    
    double time = 0;

    picojson::object client;
} client_t;

typedef struct Panel {
    std::shared_ptr<tcp::socket> connection;
    double time = 0;
} panel_t;


class ClientsPool {
    public:
        // register new client  (generate the uid here, redirect it)
        std::string insert(client_t*);  // -> uid

        // return connected clients (json)
        void list(tcp::socket&);

        // connect client to control panel
        void connect(std::string, panel_t*);

        // disconnect xpanel from xclient
        void disconnect(std::string);

        // close all the connectiosn
        void close_all();


    private:
        // all the connected clients
        std::map<std::string, client_t*> connected_clients;

        // client uid -> panel
        std::map<std::string, panel_t*> connected_duos;

        // async read/write from/to client/panel
        void async_read_write_g2p(std::shared_ptr<tcp::socket>, std::shared_ptr<tcp::socket>, std::string);
        void join(std::shared_ptr<tcp::socket>, std::shared_ptr<tcp::socket>, std::string);
};