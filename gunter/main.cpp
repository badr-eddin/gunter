#include "controller/client.hpp"
#include <iostream>

#define __G_VERSION "0.0.1"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <IP> <PORT>" << std::endl;
        return 1;
    }

    std::string ip(argv[1]);
    unsigned int port = std::stoi(argv[2]);

    credentials_t creds({
        ip,
        argv[3],
        "xp",
        port,
        10
    });

    gunter_client_t client(creds);
    client.connect();

    return 0;
}

