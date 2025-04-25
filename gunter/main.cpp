#include "controller/client.hpp"
#include <iostream>

#define __G_VERSION "0.0.1"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <IP> <PORT>" << std::endl;
        return 1;
    }

    std::string ip = argv[1];
    int port = std::stoi(argv[2]);

    credentials_t creds({
        ip,
        "gunter",
        "xp",
        port,
        10
    });

    gunter_client_t client(creds);
    client.connect();

    return 0;
}

