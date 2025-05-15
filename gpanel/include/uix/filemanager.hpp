#pragma once

#include <QTreeWidgetItem>
#include <QInputDialog>
#include "ui/filemanager.hpp"
#include "uix/twindow.hpp"
#include "uix/dialogs.hpp"

#include "utils.hpp"


namespace gpanel {

    class FileManager : public TabWindow {
        private:
            Ui::FM *ui;
            InputDialog *inp_dialog;
            std::map<const std::string, uint8_t> headers;
            picojson::object files_map;

            void refresh();
            void list_files();
            void fm_new(const std::string);
            void fm_new_file();
            void fm_new_folder();
            void fm_paste();
            void fm_cut();
            void fm_copy();
            void fm_delete();

            void path_backward();
            void path_forward();
            void populate(picojson::array);
            void navigate_from_item(QTreeWidgetItem*);

            void set_headers(picojson::array);
            template <typename T> T read_by_header(picojson::array, const std::string);

            void nav_to_path(std::string);
        public:
            FileManager(QWidget*);
            ~FileManager();

    };

}
