#include <windows.h>
#include <iostream>

int main() {
    HINSTANCE hDLL = LoadLibrary("gunter.dll");
    if (!hDLL) {
        std::cerr << "Failed to load DLL!" << std::endl;
        return 1;
    }

    std::cout << "DLL loaded successfully. Client should be running now.\n";

    // Keep the DLL loaded (optional)
    std::cin.get();

    FreeLibrary(hDLL);
    return 0;
}

