#include "uix/client_panel.hpp"


gpanel::ClientPanel::ClientPanel(QWidget*parent) : QWidget(parent), ui(new Ui::TPanel) {
    this->ui->setupUi(this);
    this->close();

    if (parent)
        this->move(
            QPoint(
                parent->width() + 2,
                parent->height() - this->height() - 2
            )
        );

    connect(
        this->ui->cl_kill, &QPushButton::clicked,
        [this](){ this->send_cmd(G_KILL); }
    );

    connect(
        this->ui->cl_hibern, &QPushButton::clicked,
        [this](){ this->send_cmd(G_UNPLUG); }
    );
} 

void gpanel::ClientPanel::set_info(picojson::object *client) {
    if ((*client)["username"].is<std::string>() && (*client)["tag"].is<std::string>()) {
        this->ui->cl_fname->setText(QString::fromStdString(
            (*client)["username"].get<std::string>() + "@" + (*client)["tag"].get<std::string>()
        ));
    }

    if ((*client)["ip"].is<std::string>() && (*client)["port"].is<double>()) {
        this->ui->cl_address->setText(QString::fromStdString(
            (*client)["ip"].get<std::string>() + "@" + std::to_string((int)(*client)["port"].get<double>())
        ));
   }

    if ((*client)["version"].is<std::string>()) {
        this->ui->cl_version->setText(QString::fromStdString((*client)["version"].get<std::string>()));
    }

    if ((*client)["timestamp"].is<double>()) {
        this->ui->cl_ctime->setText(QString::fromStdString(
            from_timestamp((*client)["timestamp"].get<double>())
        ));
    }
}

void gpanel::ClientPanel::send_cmd(const std::string cmd) {
    gpanel::message_t msg;
    msg.set_command(cmd);
    emit this->api_exeq(QString::fromStdString(msg.dump()), [this](response_t response) {
        logging::log_print(response.as<std::string>(), response.log_level());
        emit this->deattached();
    });
}
