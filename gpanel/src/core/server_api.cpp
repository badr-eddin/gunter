#include "core/server_api.hpp"

void gpanel::ls_server(server_creds_t &creds, std::function<void(const picojson::array)> callback) {
    // create new client
    asio::error_code err_code;
    asio::io_context ioc;
    tcp::socket socket(ioc);
    tcp::endpoint endpoint(asio::ip::make_address(creds.ip, err_code), creds.port);


    auto abort = [&socket, callback](const std::string msg) {
        // close the client
        socket.close();

        // invoke the `callback`
        picojson::array response;
        picojson::object obj;

        obj["type"] = picojson::value("error");
        obj["msg"] = picojson::value(msg);

        response.push_back(picojson::value(obj));
        
        callback(response);
    };

    if (err_code) {
        abort(err_code.message());
        return;
    }

    auto read = [&socket, callback, abort](const asio::error_code& ec, std::string response) {
        if (!ec) {
            callback(parse_json<picojson::array>(response));
            socket.close();
        } 
        else {
            abort(ec.message());
        }
    };

    auto wrote = [&socket, read, abort](const asio::error_code& ec, std::size_t) {
        if (!ec) {
            // read response
            auto buffer = std::make_shared<asio::streambuf>();

            asio::async_read_until(socket, *buffer, Codes::MESSAGE_TERMINATOR, [read, buffer](const asio::error_code& ec, std::size_t){
                std::istream is(buffer.get());
                std::string response;
                std::getline(is, response, Codes::MESSAGE_TERMINATOR);
                read(ec, response);
            });
        }
        else {
            abort(ec.message());
        }
    };
    
    auto connected = [&socket, creds, abort, wrote](const asio::error_code& ec, const tcp::endpoint&) {
        if (!ec) {

            // send request
            picojson::object request_obj;
            
            request_obj["username"] = picojson::value(creds.username);
            request_obj["password"] = picojson::value(creds.password);
            request_obj["path"] = picojson::value(Codes::LIST_ENDP);

            std::string request = picojson::value(request_obj).serialize();

            // ensure that the message terminated
            request += Codes::MESSAGE_TERMINATOR;

            asio::async_write(socket, asio::buffer(request), wrote);
        }
        else {
            abort(ec.message());
        }
    };

    std::vector<tcp::endpoint> endpoints = { endpoint };

    asio::async_connect(socket, endpoints, connected);

    ioc.run();
}
