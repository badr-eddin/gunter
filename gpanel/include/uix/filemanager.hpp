#pragma once

#include <QTreeWidgetItem>

#include "ui/filemanager.hpp"
#include "uix/twindow.hpp"

#include "utils.hpp"


namespace gpanel {

    class FileManager : public TabWindow {
        public:
            FileManager(QWidget*, gpanel::exeq_sign_t);
            ~FileManager();
            
            private:
            Ui::FM *ui;
            std::map<const std::string, uint8_t> headers;
            picojson::object files_map;

            void list_files();
            void path_backward();
            void path_forward();
            void populate(const std::string);
            void navigate_from_item(QTreeWidgetItem*);

            void set_headers(picojson::array);
            template <typename T> T read_by_header(picojson::array, const std::string);

            void nav_to_path(std::string);

    };

}
