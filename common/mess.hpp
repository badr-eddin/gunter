#pragma once

#ifndef MESS_HPP
#define MESS_HPP

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include "asio.hpp"
#include "defs.hpp"
#include "utils.hpp"
#include <vector>
#include <string>
#include <iostream>


using asio::ip::tcp;


inline std::string ack(tcp::socket &client, bool) {
    // reserve
    std::vector<char> buffer(static_cast<std::size_t>(Params::ACK_CODE_SIZE));

    // read
    asio::read(client, asio::buffer(buffer));

    std::string code(buffer.begin(), buffer.end());

    // compare
    return code;
}

inline bool ack(tcp::socket &client) {
    return (ack(client, true).compare(Codes::ACK) == 0);
}

inline size_t send(tcp::socket &client, const std::string &data) {
    try {
        size_t bytes_sent;

        // add message terminator
        std::string message = data + Codes::MESSAGE_TERMINATOR;

        // TODO: encrypt data

        // send data
        bytes_sent = asio::write(client, asio::buffer(message));

        return bytes_sent;
        
    } catch (std::system_error &e) {
        return 0;
    }
}

inline std::string recv(tcp::socket &client) {
    try {        
        // create a buffer
        asio::streambuf buffer;

        // read until a null terminator
        asio::read_until(client, buffer, Codes::MESSAGE_TERMINATOR);

        // convert the stream buffer to string
        std::istream is(&buffer);
        std::string data;
        // string the mesage terminator / it will cause error in json parsing
        std::getline(is, data, Codes::MESSAGE_TERMINATOR);
        
        // TODO: decrypt received data

        return data;

    } catch (const std::system_error &e) {
        return "";
    }
}


#endif
