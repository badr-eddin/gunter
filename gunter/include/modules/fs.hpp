#pragma once

#include "utils.hpp"
#include "windows.h"

#include <string>
#include <cstdio>

namespace fs {
    std::string change_dir(std::string);
    std::string current_work_dir();
    
    std::string list_dir(std::string, std::string);
    std::string list_dir(std::string);
    
    std::string create_file(std::string);
    std::string create_dir(std::string);

    std::string delete_file(std::string);
    std::string delete_dir(std::string);
    
    std::string copy_dir(std::string, std::string);
    std::string copy_file(std::string, std::string);
    
    std::string move_dir(std::string, std::string);
    std::string move_file(std::string, std::string);

    std::string find_file(std::string, std::string); // filename/rule, root directory
}
