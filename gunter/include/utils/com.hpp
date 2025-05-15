#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iomanip>

#include "json.hpp"
#include "utils.hpp"
#include "defcmd.hpp"

namespace com {
    /*
    type + message + timestamp -> json
    */
    std::string make_response(std::string type, std::string msg);
    std::string get_last_win_error();
}

