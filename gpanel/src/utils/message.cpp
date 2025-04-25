#include "utils/message.hpp"


void gpanel::GMessage::set_command(const std::string cmd) {
    this->_obj_message["command"] = picojson::value(cmd);
}

template <typename T>
picojson::value gpanel::GMessage::value(T vl) { return picojson::value(vl); }

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

