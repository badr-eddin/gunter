#pragma once
#ifndef C_UTILS_HPP
#define C_UTILS_HPP

#include <cstdlib>
#include <chrono>
#include <random>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

#include "json.hpp"
#include "logging.hpp"

// generate unique id
inline std::string get_uid(unsigned short length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255); // Generate full byte (0x00 - 0xFF)

    std::ostringstream uuid;
    uuid << std::hex << std::setw(2) << std::setfill('0');

    for (int i = 0; i < length / 2; ++i) {
        uuid << std::setw(2) << dis(gen); // Ensure 2-digit hex format
    }
    return uuid.str();
}


template <typename T>
inline T parse_json(std::string text) {
    picojson::value v;

    std::string err = picojson::parse(v, text);
    
    // check if there was a parsing error
    if (!err.empty()) {
        logging::log_print("error parsing json: " + err, 2);

        return T();
    }

    if (v.is<T>()) {
        return v.get<T>();
    } else {
        logging::log_print("parsed json does not match expected type!", 1);
        return T();
    }
}


inline picojson::object parse_json(std::string text) {
    return parse_json<picojson::object>(text);
}

inline double get_time() {    
    // get current time from system clock
    auto now = std::chrono::system_clock::now();
    
    // Convert to time_t
    auto duration = now.time_since_epoch();
    
    double timestamp = std::chrono::duration_cast<std::chrono::duration<double>>(duration).count();
    
    return timestamp;
}

inline std::string from_timestamp(double timestamp) {
    time_t time = static_cast<time_t>(timestamp);
    tm *tm_time = localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(tm_time, "%d/%m/%Y %H:%M");
    return oss.str();
}

#endif
