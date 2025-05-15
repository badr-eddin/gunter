#pragma once
#include <queue>
#include <functional>
#include <string>

#include <QThread>
#include <QObject>
#include <QString>

#define DEBUG

#include "core/server_api.hpp"
#include "utils/message.hpp"

#include "asio.hpp"
#include "mess.hpp"
#include "json.hpp"

#include "logging.hpp"

// TODO: read address & credentials from a settings file


namespace gpanel {
    using exeq_callback_t = std::function<void(response_t)>;
    
    class ASIOThread : public QThread {
        public:
            ASIOThread(asio::io_context*, QObject*);
        
        protected:
            void run() override;
        
        private:
            asio::io_context* io_context;
            asio::executor_work_guard<asio::io_context::executor_type> work_guard;
    };

    class API : public QObject {
        Q_OBJECT

        signals:
            void error_to_connect(QString);
            void connected(QWidget*, QString, QString);
            void disconnected();
            
        public:
            picojson::object client;

            // init the api with a static uid
            explicit API(QObject*parnet=nullptr);

            ~API();

            void init(QWidget*, server_creds_t*, const std::string);

            // try to connect to a client with its uid
            void connect2();

            // queued wrapper for common/send and receive
            void exeq(const std::string, const exeq_callback_t&);  // a1 -> command, a2 -> callback

            // pop a message from queue, send it, wait for response, invoke `callback` and recurse
            void start();

            void set_client(picojson::object);

            picojson::object get_client();
        
            // enumeration
            unsigned short count(); // count messages in the queue
            size_t bsent();
            size_t breceived();
    
        private:
            std::string uid;
            server_creds_t *creds;

            size_t total_bytes_sent = 0;
            size_t total_bytes_received = 0;

            bool __connected = false;
            bool started = false;

            using message_q_t = std::pair<const std::string, exeq_callback_t>;

            std::queue<message_q_t> messages;

            asio::io_context *io_context;

            std::shared_ptr<tcp::socket> connection = nullptr;

            ASIOThread *thread_context;
            
            asio::executor_work_guard<asio::io_context::executor_type> work_guard;

            // store callback in class scope to maintain it existence during async ops
            exeq_callback_t callback;

            QWidget *parent_w;

            void handle_error(const asio::error_code&, exeq_callback_t);

    };
}
