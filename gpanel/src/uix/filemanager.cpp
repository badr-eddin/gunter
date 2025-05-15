#include "uix/filemanager.hpp"


gpanel::FileManager::FileManager(QWidget *parent) : TabWindow(parent), ui(new Ui::FM), inp_dialog(new InputDialog(this)) {
    this->setup<Ui::FM>(this->ui, "File Explorer");
    this->inp_dialog->close();
        
    connect(
        this->ui->fm_refresh, &QPushButton::clicked,
        this, &gpanel::FileManager::refresh
    );

    connect(
        this->ui->fm_files_list, &QTreeWidget::itemDoubleClicked,
        this, &gpanel::FileManager::navigate_from_item
    );

    connect(
        this->ui->fm_backward, &QPushButton::clicked,
        this, &gpanel::FileManager::path_backward
    );

    connect(
        this->ui->fm_new_file, &QPushButton::clicked,
        this, &gpanel::FileManager::fm_new_file
    );

    connect(
        this->ui->fm_new_folder, &QPushButton::clicked,
        this, &gpanel::FileManager::fm_new_folder
    );

    this->ui->fm_copy->setIcon(uiutils::get_icon("fileman/copy.svg"));
    this->ui->fm_cut->setIcon(uiutils::get_icon("fileman/cut.svg"));
    this->ui->fm_paste->setIcon(uiutils::get_icon("fileman/paste.svg"));
    this->ui->fm_delete->setIcon(uiutils::get_icon("fileman/delete.svg"));
    this->ui->fm_new_file->setIcon(uiutils::get_icon("fileman/new-file.svg"));
    this->ui->fm_new_folder->setIcon(uiutils::get_icon("fileman/new-folder.svg"));
    this->ui->fm_refresh->setIcon(uiutils::get_icon("fileman/refresh.svg"));
    this->ui->fm_backward->setIcon(uiutils::get_icon("fileman/go-backward.svg"));

    this->list_files();
}


void gpanel::FileManager::path_backward() {
    std::string path = this->ui->path->text().toStdString();

    if (path.empty()) return;

    // if it ends with \ remove it
    if (path.back() == '\\' || path.back() == '/') path.pop_back();

    size_t pos = path.find_last_of("/\\");

    if (pos != std::string::npos) { path = path.substr(0, pos); }

    this->nav_to_path(path);
}

void gpanel::FileManager::navigate_from_item(QTreeWidgetItem*item) {
    // if no item just ignore
    if (!this->files_map[item->text(0).toStdString()].is<picojson::array>()) return;

    // get file object
    picojson::array file = this->files_map[item->text(0).toStdString()].get<picojson::array>();

    if (read_by_header<std::string>(file, "type") == "folder") {
        this->nav_to_path(read_by_header<std::string>(file, "fullpath"));
    }
}

void gpanel::FileManager::nav_to_path(std::string path) {
    if (path.back() == '\\' || path.back() == '/') path.pop_back();

    this->ui->path->setText(QString::fromStdString(path));

    // list files
    message_t msg;

    msg.set_command(LS);
    msg["path"] = msg.value(path);

    emit this->api_exeq(
        QString::fromStdString(msg.dump()), 
        [this](response_t response){ 
            if (!response.log_level()) {
                this->populate(response.as<picojson::array>()); 
            }
            else {
                logging::log_print(response.as<std::string>(), response.log_level());
            }
        }
    );

}

void gpanel::FileManager::set_headers(picojson::array hdrs) {
    uint8_t index = 1;

    this->headers.clear();

    for (const picojson::value &item : hdrs) {
        this->headers[item.get<std::string>()] = item.is<std::string>() ? index++ : 0;
    }

    this->ui->fm_files_list->header()->setDefaultSectionSize(150);
}

template <typename T> T 
gpanel::FileManager::read_by_header(picojson::array item, const std::string header) {
    if (!this->headers.empty() && !item.empty() && !header.empty()) {
        auto it = this->headers.find(header);

        if (it != this->headers.end()) {
            uint8_t index = it->second;
    
            // 0 means not found or not string
            if (0 < index < item.size()) {
                if (item[index-1].is<T>()) return item[index-1].get<T>();
            }
        }
    }

    return T();

}

void gpanel::FileManager::populate(picojson::array files) {
    this->ui->fm_files_list->clear();
    this->files_map.clear();

    if (files.empty()) {
        return;
    }

    // populate
    bool is_it_first = true;

    QString name("");

    for (const picojson::value &file_v : files) {
        // if not an array ignore, TODO: maybe log that later
        if (!file_v.is<picojson::array>()) continue;

        picojson::array file = file_v.get<picojson::array>();

        // the first item indicates the headers (keys)
        if (is_it_first) {
            is_it_first = false;

            // store current headers
            this->set_headers(file);

            continue;
        }

        QTreeWidgetItem *item = new QTreeWidgetItem();
        name = QString::fromStdString(this->read_by_header<std::string>(file, "name"));

        item->setText(0, name);
        bool isfolder = this->read_by_header<std::string>(file, "type") == "folder";
        std::string ss = isfolder ? "-" : std::to_string((unsigned int)this->read_by_header<double>(file, "size")) + "B";
        item->setText(1, QString::fromStdString(ss));
        item->setText(2, QString::fromStdString(this->read_by_header<std::string>(file, "modified")));

        if (isfolder)
            item->setIcon(0, uiutils::get_icon("fileman/folder.svg"));
        else
            item->setIcon(0, uiutils::get_icon("fileman/file.svg"));

        this->ui->fm_files_list->addTopLevelItem(item);

        this->files_map[name.toStdString()] = picojson::value(file);
    }
}

void gpanel::FileManager::list_files() {
    gpanel::message_t msg;

    // get current path
    msg.set_command(PWD);

    emit this->api_exeq(QString::fromStdString(msg.dump()), [this](response_t response){
        if (response.empty()) {
            logging::log_print("invalid response!", 2);
            return;
        }

        if (response.log_level()) {
            logging::log_print(response.as<std::string>(), response.log_level());
            return;
        }

        // check if path exist
        const std::string path = response.as<std::string>();

        if (path.empty()) {
            logging::log_print("unable to get valid path!", 2);
            return;
        }

        this->nav_to_path(path); 
    });
}

void gpanel::FileManager::refresh() {
    std::string current_gui_path = this->ui->path->text().toStdString();

    if (!current_gui_path.empty()) {
        this->nav_to_path(current_gui_path);
    } else {
        this->list_files();
    }
}

void gpanel::FileManager::fm_new_folder() {
    this->fm_new(MKDIR);
}

void gpanel::FileManager::fm_new_file() {
    this->fm_new(MKFILE);
}

void gpanel::FileManager::fm_new(const std::string method) {
    auto on_enter = [this, method](std::string fname) {
        gpanel::message_t msg;
        msg.set_command(method);
        msg["name"] = msg.value(fname);

        emit this->api_exeq(QString::fromStdString(msg.dump()), [this](response_t response) {
            logging::log_print(response.as<std::string>(), response.log_level());
            this->refresh();
        });
    };
    
    this->inp_dialog->connect(this->inp_dialog, &InputDialog::on_success, on_enter);
    this->inp_dialog->request_input(qobject_cast<QPushButton*>(sender())->pos(), "name");
}


gpanel::FileManager::~FileManager() {
    delete this->ui;
}
