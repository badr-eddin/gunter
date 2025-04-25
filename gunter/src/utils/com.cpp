#include "utils/com.hpp"

std::string com::make_response(std::string type, std::string msg) {
    picojson::object response;

    response["msg"] = picojson::value(msg == "?" ? com::get_last_win_error() : msg);
    response["type"] = picojson::value(type);
    response["timestamp"] = picojson::value(get_time());

    return picojson::value(response).serialize();
}

std::string com::get_last_win_error() {
    DWORD error = GetLastError();
    
     // Return a default message if no error occurred
    if (error == 0) return "no error";

    char* message_buffer = nullptr;

    size_t size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, error, 0, (LPSTR)&message_buffer, 0, nullptr
    );

    std::string error_message;

    if (size > 0) {
        // Convert to std::string
        error_message = message_buffer;

        // Trim trailing spaces, newlines, etc.
        error_message.erase(error_message.find_last_not_of(" \n\r\t") + 1);

        // Free allocated buffer
        LocalFree(message_buffer);
    } else {
        error_message = "unknown error. Error code: " + std::to_string(error);
    }

    return error_message;
}