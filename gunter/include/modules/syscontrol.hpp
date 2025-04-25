#pragma once

#include <windows.h>
#include <string>
#include "utils/com.hpp"


namespace gsystem {    
    namespace control{
        void list_processes();
        void kill_process();
        void start_process();
        
        void read_registry();
        void write_registry();
        void delete_registry();
    
        void screenshot();
    
        std::string read_env(std::string);

        std::string reboot(unsigned int);
        std::string shutdown(unsigned int);
        std::string shutdown(unsigned int, bool);

        std::string abort_shutdown_reboot();

    
        std::string lock_workstation(unsigned int);
    }
}