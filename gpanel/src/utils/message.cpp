#include "utils/message.hpp"
#include "utils.hpp"


void gpanel::GMessage::set_command(const std::string cmd) {
    this->_obj_message["command"] = picojson::value(cmd);
}

picojson::value& gpanel::GMessage::operator[](const std::string& key) {
    // Ensure "args" is a picojson::object before modifying
    if (!this->_obj_message["args"].is<picojson::object>()) {
        this->_obj_message["args"] = picojson::value(picojson::object());
    }

    picojson::object& args = this->_obj_message["args"].get<picojson::object>();

    // Return the value corresponding to the key in the args object
    return args[key];
}

std::string gpanel::GMessage::dump() {
    return picojson::value(this->_obj_message).serialize();
}


gpanel::GResponse::GResponse(std::string response_str) {
    this->response = parse_json(response_str);
}

bool gpanel::GResponse::empty() { return this->response.empty(); }

unsigned char gpanel::GResponse::log_level() {
    unsigned char level = 0;

    if (!this->response["type"].is<std::string>())
        return 0;

    if (this->response["type"].get<std::string>() == "warn")
        level = 1;

    if (this->response["type"].get<std::string>() == "error")
        level = 2;

    return level;
}

time_t gpanel::GResponse::time() {
    if (this->response["timestamp"].is<double>())
        return static_cast<time_t>(this->response["timestamp"].get<double>());

    return 0;
}
