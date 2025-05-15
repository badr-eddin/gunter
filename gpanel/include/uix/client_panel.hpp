#pragma once
#include "ui/tab_panel.hpp"
#include "utils.hpp"
#include "core/client_api.hpp"
#include "utils/message.hpp"
#include "defcmd.hpp"


namespace gpanel {
    class ClientPanel : public QWidget {
        Q_OBJECT

        signals:
            void api_exeq(const QString, exeq_callback_t);
            void deattached();

        public:
            ClientPanel(QWidget*);
            void set_info(picojson::object*);

        private:
            Ui::TPanel *ui;

            void send_cmd(const std::string);
    };
}