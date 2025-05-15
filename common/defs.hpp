#pragma once

#ifndef DEFS_HPP
#define DEFS_HPP

enum class Params : std::size_t {
    DATA_LEN_SIZE = 8,
    ACK_CODE_SIZE = 3,
    UID_SIZE = 16
};

namespace Codes {
    constexpr const char* ACK = "200";
    constexpr const char* KILL = "999";
    constexpr const char* LIST_ENDP = "/list";
    constexpr const char* CONNECT_ENDP = "/connect";
    constexpr const char* DISCONNECT_ENDP = "/disconnect";
    constexpr const char MESSAGE_TERMINATOR = '\0';
}

#endif