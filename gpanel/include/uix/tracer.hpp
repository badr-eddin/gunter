#pragma once
#include <QStyledItemDelegate>
#include "ui/tracer.hpp"
#include "uix/twindow.hpp"


namespace gpanel {
    class Tracer : public TabWindow {
        public:
            Tracer(QWidget*);
            ~Tracer();

        private:
            Ui::Tracer *ui;

            void on_env_item_changed(QTreeWidgetItem*);
            void on_env_dbl_click(QTreeWidgetItem*, int);
            void on_tab_changed(unsigned char);
            void dump_target();
            void populate(picojson::object);         
    };
}
