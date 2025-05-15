#pragma once

#include <QBrush>
#include <Qt>

#include "utils/ui.hpp"
#include "utils/theme.hpp"
#include "json.hpp"

#include "core/client_api.hpp"
#include "uix/filemanager.hpp"
#include "uix/system.hpp"
#include "uix/tracer.hpp"
#include "uix/client_panel.hpp"
#include "ui/tab.hpp"


#define BTN_ACTIVE "background:rgba(48, 66, 107, 0.5);"
#define BTN_NACTIVE "background: transparent;"


namespace gpanel {
    class Tab : public QWidget {
        Q_OBJECT
        
        signals:
            void disconnected(unsigned char);

        private:
            Ui::Tab *ui;
            gpanel::ClientPanel *panel;
            bool win_status[6] = {0, 0, 0, 0, 0, 0};

            void on_api_exeq_requested(const QString, gpanel::exeq_callback_t);
            void on_api_disconnected();
            
        public:
            // even if 0 is a valid index but it points to home, so it is invalid
            // assuming that number of tabs wont go beyond 'unsigned char' (256 tab)
            unsigned char index = 0;
            API *api;
            
            Tab(QWidget*, server_creds_t*, const std::string, picojson::object);
            ~Tab();

            void init();
            void win_btn_clicked();
            void open_client_tab();
    };
}
