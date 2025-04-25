#include "modules/syscontrol.hpp"

void privilege() {
    HANDLE token;
    TOKEN_PRIVILEGES privileges;
    
    // Enable shutdown privileges
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token)) {
        LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
        privileges.PrivilegeCount = 1;
        privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        AdjustTokenPrivileges(token, FALSE, &privileges, 0, NULL, NULL);
        CloseHandle(token);
    }
}

std::string gsystem::control::read_env(std::string key) {
    const char* value = std::getenv(key.c_str());
    return com::make_response(value ? "info" : "error", value ? value : "<unknown>");
}


std::string gsystem::control::reboot(unsigned int timeout) {
    return gsystem::control::shutdown(timeout, true);
}

std::string gsystem::control::shutdown(unsigned int timeout) {
    return gsystem::control::shutdown(timeout, false);
}

std::string gsystem::control::shutdown(unsigned int timeout, bool reboot) {
    privilege();

    // If the function succeeds, the return value is nonzero.
    if (InitiateSystemShutdownA(
        NULL,  // network, in this case shutdown the local computer
        NULL, // display message
        timeout,   // delay
        TRUE, // applications with unsaved changes are to be forcibly closed
        reboot  // restart the computer if set to true 
    )) {
        return com::make_response("info", "shutdown/reboot scheduled in " + std::to_string(timeout) + "sec.");
    } else {
        return com::make_response("error", "?");
    }
}

std::string gsystem::control::abort_shutdown_reboot() {
    //If the function succeeds, the return value is nonzero.
    privilege();

    if(!AbortSystemShutdownA(NULL)) {
        return com::make_response("error", "?");
    }

    return com::make_response("error", "shutdown/reboot aborted.");
}


std::string gsystem::control::lock_workstation(unsigned int timeout) {
    Sleep(timeout);

    if(!LockWorkStation()) {
        return com::make_response("error", "?");
    }
    return com::make_response("info", "computer locked.");
}
