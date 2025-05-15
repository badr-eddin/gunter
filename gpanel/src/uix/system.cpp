#include "uix/system.hpp"


gpanel::GSystem::GSystem(QWidget*parent)
     : TabWindow(parent), ui(new Ui::System) {

    this->setup<Ui::System>(this->ui, "System");
    
    connect(
        this->ui->sysc_shutdown, &QPushButton::clicked,
        [this]() {
            gpanel::message_t msg;
            msg.set_command(SHUTDOWN);
            msg["timeout"] = msg.value<double>(10);

            this->api_exeq(
                QString::fromStdString(msg.dump()),
                [](response_t response){
                    logging::log_print(response.as<std::string>(), response.log_level());
                }
            );
        }
    );
    connect(
        this->ui->sysc_reboot, &QPushButton::clicked,
        [this]() {
            gpanel::message_t msg;
            msg.set_command(REBOOT);
            msg["timeout"] = msg.value<double>(10);

            this->api_exeq(
                QString::fromStdString(msg.dump()),
                [](response_t response){
                    logging::log_print(response.as<std::string>(), response.log_level());
                }
            );
        }
    );
    connect(
        this->ui->sysc_areboot, &QPushButton::clicked,
        [this]() {
            gpanel::message_t msg;
            msg.set_command(ABORT_RB);

            this->api_exeq(
                QString::fromStdString(msg.dump()),
                [](response_t response){
                    logging::log_print(response.as<std::string>(), response.log_level());
                }
            );
        }
    );
    connect(
        this->ui->sysc_ashutdown, &QPushButton::clicked,
        [this]() {
            gpanel::message_t msg;
            msg.set_command(ABORT_SH);

            this->api_exeq(
                QString::fromStdString(msg.dump()),
                [](response_t response){
                    logging::log_print(response.as<std::string>(), response.log_level());
                }
            );
        }
    );

}

gpanel::GSystem::~GSystem() {
    delete this->ui;
}
