#pragma once

#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

// define log levels and their corresponding colors
namespace logging {
    inline std::string get_ftime() {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return std::string(buffer);
    }

    // function to log messages with color and optional file redirection, 0 -> info | 1 -> warning | 2 -> error, define DEBUG to enable logging
    inline void log_print(const std::string& message, unsigned char level = 0, const std::string& log_file = "") {
        #if defined(DEBUG)

        // define color codes for each log level
        const std::string RESET = "\033[0m";
        const std::string BLUE = "\033[34m";   // Info
        const std::string YELLOW = "\033[33m"; // Warning
        const std::string RED = "\033[31m";    // Error

        // get the current time
        std::string time = get_ftime();

        // determine the log level prefix and color
        std::string levelPrefix;
        std::string color;

        switch (level) {
            case 0:
                levelPrefix = "[INFO]   ";
                color = BLUE;
                break;
            case 1:
                levelPrefix = "[WARNING]";
                color = YELLOW;
                break;
            case 2:
                levelPrefix = "[ERROR]  ";
                color = RED;
                break;
            default:
                levelPrefix = "[UNKNOWN]";
                color = RESET;
                break;
        } 

        // format the log message
        std::string logMessage = levelPrefix + " " + time + " " + message;

        // print to console with color
        std::cout << color << logMessage << RESET << std::endl;

        // optionally write to a file
        if (!log_file.empty()) {
            std::ofstream file(log_file, std::ios::app); // append mode
            if (file.is_open()) {
                file << logMessage << std::endl;
                file.close();
            } else {
                std::cerr << "failed to open log file: " << log_file << std::endl;
            }
        }
        #endif
    }
}

#endif
