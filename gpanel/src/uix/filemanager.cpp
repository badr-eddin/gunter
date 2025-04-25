#include "uix/filemanager.hpp"


gpanel::FileManager::FileManager(QWidget *parent, gpanel::exeq_sign_t exeq_cb) : TabWindow(parent, exeq_cb), ui(new Ui::FM) {    
    QWidget *widget = new QWidget();
    this->ui->setupUi(widget);
    this->setWidget(widget);
    this->resize(500, 300);
    this->setWindowTitle("File Explorer");
    
    this->list_files();
    
    connect(
        this->ui->fm_refresh, &QPushButton::clicked,
        this, &gpanel::FileManager::list_files
    );

    connect(
        this->ui->fm_files_list, &QTreeWidget::itemDoubleClicked,
        this, &gpanel::FileManager::navigate_from_item
    );

    connect(
        this->ui->fm_backward, &QPushButton::clicked,
        this, &gpanel::FileManager::path_backward
    );

    this->ui->fm_copy->setIcon(uiutils::get_icon("fileman/copy.svg"));
    this->ui->fm_cut->setIcon(uiutils::get_icon("fileman/cut.svg"));
    this->ui->fm_paste->setIcon(uiutils::get_icon("fileman/paste.svg"));
    this->ui->fm_delete->setIcon(uiutils::get_icon("fileman/delete.svg"));
    this->ui->fm_new_file->setIcon(uiutils::get_icon("fileman/new-file.svg"));
    this->ui->fm_new_folder->setIcon(uiutils::get_icon("fileman/new-folder.svg"));
    this->ui->fm_refresh->setIcon(uiutils::get_icon("fileman/refresh.svg"));
    this->ui->fm_backward->setIcon(uiutils::get_icon("fileman/go-backward.svg"));
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
    msg["path"] = picojson::value(path);

    this->exeq(msg.dump(), [this](const std::string response){ this->populate(response); });

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

void gpanel::FileManager::populate(const std::string list_str) {
    this->ui->fm_files_list->clear();
    this->files_map.clear();

    picojson::object response_js = parse_json(list_str);

    if (response_js.empty())
        return;

    if (!response_js["msg"].is<std::string>()) {
        // TODO: log
        return;
    }

    picojson::array files = parse_json<picojson::array>(response_js["msg"].get<std::string>()); 

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
        item->setText(1, QString::fromStdString(this->read_by_header<std::string>(file, "size")));
        item->setText(2, QString::fromStdString(this->read_by_header<std::string>(file, "modified")));

        if (this->read_by_header<std::string>(file, "type") == "folder")
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

    this->exeq(msg.dump(), [this](const std::string response){ 
        picojson::object response_js = parse_json(response);

        if (response_js.empty())
            // TODO: log: unable to get valid path
            return;

        // check if path exist
        if (!response_js["msg"].is<std::string>()) {
            return;
        }

        const std::string path = response_js["msg"].get<std::string>();

        this->nav_to_path(path); 
    });
}


gpanel::FileManager::~FileManager() {
    delete this->ui;
}
