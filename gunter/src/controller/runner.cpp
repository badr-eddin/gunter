#include "controller/runner.hpp"


std::string runner::run_command(std::string command, picojson::object args) {

    if (command == PWD) {
        return fs::current_work_dir();
    }

    else if (command == CD) {
        if (args["path"].is<std::string>()) {
            return fs::change_dir(args["path"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'path'!");
    }

    else if (command == LS) {
        std::string path = "./";

        if (args["path"].is<std::string>()) {
            path = args["path"].get<std::string>();
        }

        return fs::list_dir(path);
    }
    
    else if (command == RMDIR) {
        if (args["path"].is<std::string>()) {
            return fs::delete_dir(args["path"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'path'!");
    }
    else if (command == MKDIR) {
        if (args["name"].is<std::string>()) {
            return fs::create_dir(args["name"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'name'!");
    }

    else if (command == CP_DIR) {
        if (args["src"].is<std::string>() && args["dst"].is<std::string>()) {
            return fs::copy_dir(args["src"].get<std::string>(), args["src"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'src' or 'dst'!");
    }

    else if (command == MV_DIR) {
        if (args["src"].is<std::string>() && args["dst"].is<std::string>()) {
            return fs::move_dir(args["src"].get<std::string>(), args["src"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'src' or 'dst'!");
    }

    else if (command == RMFILE) {
        if (args["path"].is<std::string>()) {
            return fs::delete_file(args["path"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'path'!");
    }

    else if (command == MKFILE) {
        if (args["name"].is<std::string>()) {
            return fs::create_file(args["name"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'name'!");
    }

    else if (command == FIND) {
        if (args["rule"].is<std::string>() && args["root"].is<std::string>()) {
            return fs::find_file(args["rule"].get<std::string>(), args["root"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'rule' | 'root' !");
    } 

    else if (command == SHUTDOWN) {
        unsigned int timeout = 0;

        if(args["timeout"].is<double>()) {
            timeout = args["timeout"].get<double>();
        }

        return gsystem::control::shutdown(timeout);
    }
    
    else if (command == REBOOT) {
        unsigned int timeout = 0;

        if(args["timeout"].is<double>()) {
            timeout = args["timeout"].get<double>();
        }

        return gsystem::control::reboot(timeout);
    }

    else if (command == ABORT_SH || command == ABORT_RB) {
        return gsystem::control::abort_shutdown_reboot();
    }

    else if (command == LOCK_WS) {
        unsigned int timeout = 0;

        if(args["timeout"].is<double>()) {
            timeout = args["timeout"].get<double>();
        }

        return gsystem::control::lock_workstation(timeout);
    }

    else if (command == READ_ENV) {
        if (args["key"].is<std::string>()) {
            return gsystem::control::read_env(args["key"].get<std::string>());
        } 
        return com::make_response("error", "missing arguemnts 'key'!");
    }

    else if (command == READ_AENV) {
        return gsystem::control::read_all_env();
    }

    else if (command == DUMP_CB) {
        return gsystem::control::dump_clipboard();
    }
    
    else {
        return com::make_response("error", "command not recognized!");
    }

    return com::make_response("error", "command not recognized!");

}