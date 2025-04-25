#pragma once


namespace system {
    namespace info
    {
        void read_env();
        
        void enum_cpu();
        void enum_ram();
        void enum_os();
        void enum_disk();
        void enum_motherboard();
        void enum_network();
        
        void sysinfo();
    }
    

}