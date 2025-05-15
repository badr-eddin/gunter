#pragma once
#include <cstdint>
#include "json.hpp"

namespace gpanel
{
    typedef class GMessage {
        public:
            void set_command(const std::string);

            picojson::value& operator[](const std::string& key);

            std::string dump();

            template <typename T>
            static picojson::value value(T vl) { return picojson::value(vl); }


        private:
            picojson::object _obj_message;

    } message_t;

    typedef class GResponse {
        public:
            GResponse(std::string);

            template<typename T> T as() {
                if (this->response["msg"].is<T>()) {
                    return this->response["msg"].get<T>();
                }
            
                else if (this->response["msg"].is<std::string>()) {
                    return parse_json<T>(this->response["msg"].get<std::string>());
                }
            
                else {
                    return T();
                }
            }
            unsigned char log_level();
            time_t time();
            bool empty();

        private:
            picojson::object response;
    } response_t;

}
