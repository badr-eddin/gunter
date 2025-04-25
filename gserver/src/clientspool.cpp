#include "clientspool.hpp"


std::string ClientsPool::insert(client_t *gunter) {
    // ensure that the uid is unique
    while (this->connected_clients.find(gunter->uid) != this->connected_clients.end()) {
        gunter->uid = get_uid((unsigned short)Params::UID_SIZE);
    }

    this->connected_clients[gunter->uid] = gunter;

    logging::log_print("new client added.");

    // return the uid
    return std::string(gunter->uid);
}
