#include "uix/main.hpp"


void gpanel::GMainWindow::refresh() { this->login(); }


void gpanel::GMainWindow::logout() {
    // reset previous creds
    this->server_creds.ip = "";
    this->server_creds.username = "";
    this->server_creds.password = "";
    this->server_creds.port = 0;

    // clear login from
    this->ui->login_server_ip->setText("");
    this->ui->login_server_username->setText("");
    this->ui->login_server_password->setText("");
    this->ui->login_server_port->setValue(4040);

    // navigate to
    this->ui->home_pages->setCurrentIndex(0);
}

void gpanel::GMainWindow::login() {
    // collect data if in login form not refresh
    if (this->ui->home_pages->currentIndex() == 0) {
        this->server_creds.ip = this->ui->login_server_ip->text().toStdString();
        this->server_creds.port = this->ui->login_server_port->value();
        this->server_creds.username = this->ui->login_server_username->text().toStdString();
        this->server_creds.password = this->ui->login_server_password->text().toStdString();
    }

    // list server
    gpanel::ls_server(this->server_creds, [this](const picojson::array response){

        // check if it holds errors
        if (response.size() > 0) {
            if (response[0].is<picojson::object>()) {
                picojson::object first_object = response[0].get<picojson::object>();
                
                if (first_object["type"].is<std::string>()) {
                    if (first_object["type"].get<std::string>() == "error") {
                        
                        std::string msg;

                        if (first_object["msg"].is<std::string>()) {
                            msg = first_object["msg"].get<std::string>();
                        } else {
                            msg = "unknown error!";
                        }

                        this->ui->login_msg_label->setText(QString(msg.c_str()));

                        return;
                    }
                }
            }
        }

        //clear previous
        this->current_clients.clear();
        this->ui->connected_clients->clear();

        // set the new
        this->current_clients = response;

        // show in UI
        this->populate();

        // navigate to
        this->ui->home_pages->setCurrentIndex(1);
    });
}

void gpanel::GMainWindow::connect2g() {
    QTreeWidgetItem *item = this->ui->connected_clients->currentItem();

    if (!item) {
        return;
    }

    unsigned char index = item->data(0, Qt::UserRole).toInt();

    if (!this->current_clients[index].is<picojson::object>()) {
        logging::log_print("invalid client info!");
        return;
    }

    picojson::object client = this->current_clients[index].get<picojson::object>();

    if (!client["uid"].is<std::string>()) {
        logging::log_print("invalid ui!", 2);
        return;
    }

    const std::string uid = client["uid"].get<std::string>();

    // since we are dealing with (I guess) less than 100 item this should be good
    if (!this->connected_uids.empty()) {
        for (const auto &item : this->connected_uids) {
            if (uid == item) {
                logging::log_print("already connected to '" + uid + "'", 1);
                return;
            }
        }
    }

    Tab *tab = new Tab(nullptr, &this->server_creds, uid, client);    
    connect(
        tab->api, &API::connected,
        this, &GMainWindow::connected
    );
    connect(
        tab->api, &API::error_to_connect,
        this, &GMainWindow::error_to_connect
    );
    connect(
        tab, &Tab::disconnected,
        this, &GMainWindow::remove_tab
    );
    tab->init();
}

void gpanel::GMainWindow::error_to_connect(QString msg) {
    logging::log_print(msg.toStdString(), 2);
}

void gpanel::GMainWindow::connected(QWidget *tab, QString title, QString uid) {
    if (tab) {
        this->connected_uids.push_back(uid.toStdString());
        qobject_cast<Tab*>(tab)->index = this->new_tab(tab, title);
        this->refresh();
    }
}
