#pragma once

#include "json.hpp"
#include "mess.hpp"
#include "defs.hpp"
#include "utils.hpp"

#include <vector>


namespace gpanel {
    typedef struct ServerCredentials {
        std::string ip;
        std::string username;
        std::string password;

        unsigned short port;

    } server_creds_t;

    void ls_server(server_creds_t&, std::function<void(const picojson::array)>);
}
