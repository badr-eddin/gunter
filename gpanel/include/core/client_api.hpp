#pragma once
#include <queue>
#include <functional>
#include <string>

#include <QThread>
#define DEBUG

#include "core/server_api.hpp"

#include "asio.hpp"
#include "mess.hpp"
#include "json.hpp"

#include "logging.hpp"

// TODO: read address & credentials from a settings file


namespace gpanel {
    using connect_cb_t = std::function<void(const std::string)>;

    class ASIOThread : public QThread {
        public:
            ASIOThread(asio::io_context*, QObject*);
        
        protected:
            void run() override;
        
        private:
            asio::io_context* io_context;
            asio::executor_work_guard<asio::io_context::executor_type> work_guard;
    };

    class EventListener {
        public:
            EventListener();
            ~EventListener();
            virtual void on_error_to_connect(const std::string) = 0;
            virtual void on_connected(QWidget*tab, const std::string title, const std::string uid) = 0;
    };

    typedef class API : public QObject {
        private:
            std::string uid;
            picojson::object client;

            server_creds_t *creds;

            bool connected = false;
            bool started = false;

            using message_q_t = std::pair<const std::string, connect_cb_t>;

            std::queue<message_q_t> messages;

            asio::io_context *io_context;

            std::shared_ptr<tcp::socket> connection = nullptr;

            ASIOThread *thread_context;
            
            asio::executor_work_guard<asio::io_context::executor_type> work_guard;

            // store callback in class scope to maintain it during async ops
            connect_cb_t callback;

            EventListener *listener = nullptr;

        public:
            // init the api with a static uid
            API(server_creds_t*, const std::string);

            ~API();

            // try to connect to a client with its uid
            void connect2();

            // queued wrapper for common/send and receive
            void exeq(const std::string, gpanel::connect_cb_t);  // a1 -> command, a2 -> callback

            // pop a message from queue, send it, wait for response, invoke `callback` and recurse
            void start();

            void set_listener(EventListener *l);
            void set_client(picojson::object);

            picojson::object get_client();
        
            // enumeration
            unsigned short count(); // count messages in the queue

            // must be overriden
            virtual QWidget* get_widget() = 0;

    } api_t;
}
