#pragma once

#include "json.hpp"

namespace gpanel
{
    typedef class GMessage {
        public:
            void set_command(const std::string);

            picojson::value& operator[](const std::string& key);

            std::string dump();

            template <typename T>
            static picojson::value value(T);


        private:
            picojson::object _obj_message;

    } message_t;
}

