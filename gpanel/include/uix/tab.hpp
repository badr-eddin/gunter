#pragma once

#include <QBrush>
#include <Qt>

#include "utils/ui.hpp"
#include "utils/theme.hpp"
#include "json.hpp"

#include "core/client_api.hpp"
#include "uix/filemanager.hpp"
#include "ui/tab.hpp"


#define TAB_EXEQ_CB_ARG std::bind(&gpanel::Tab::exeq, this, std::placeholders::_1, std::placeholders::_2)

namespace gpanel {
    class Tab : public QWidget, public API{
        public:
            Tab(QWidget*, server_creds_t*, const std::string);
            ~Tab();

            void init();
            QWidget* get_widget() override;

        private:
            EventListener *listener = nullptr;
            picojson::object client;
            Ui::Tab *ui;
    };
}
