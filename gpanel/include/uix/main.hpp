#pragma once
#include <QWidget>
#include <QTabBar>
#include <QTimer>
#include <Qt>

#include <list>

#include "ui/main_window.hpp"
#include "uix/tab.hpp"
#include "core/server_api.hpp"


namespace gpanel {
    class  GMainWindow : public QWidget, public EventListener {
        public:
            GMainWindow();
            ~GMainWindow();

            void new_tab(QWidget*, const std::string);

            void on_error_to_connect(const std::string);
            void on_connected(QWidget*tab, const std::string title, const std::string uid);

        private:
            picojson::array current_clients;
            server_creds_t server_creds;
            unsigned short home_index = 0;
            std::list<std::string> connected_uids;

            Ui::MainWindow *ui;
            QTabBar *tabbar = nullptr;

            void login();
            void logout();
            void connect2g();
            void refresh();
            
            void populate();

            void setup_tab_bar();
            void setup_main_window();
            void setup_icons();
            void setup_signals();

            void tab_bar_clicked(unsigned short);

            void mw_exit();
            void mw_minimize();
            void mw_restore();
    };
}
