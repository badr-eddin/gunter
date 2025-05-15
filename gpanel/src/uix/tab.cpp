#include "uix/tab.hpp"

// add to server a method like websockets to inform cpanels whenever a client checks in
gpanel::Tab::Tab(QWidget *parent, server_creds_t *creds, const std::string uid, picojson::object client) 
    : QWidget(parent), ui(new Ui::Tab), api(new API(this)), panel(new gpanel::ClientPanel(this)) {

    this->ui->setupUi(this);
    this->api->init(this, creds, uid);
    this->ui->windows->setBackground(QBrush(Qt::transparent));

    connect(
        this->ui->win_file_exp, &QPushButton::clicked,
        this, &gpanel::Tab::win_btn_clicked
    );

    connect(
        this->ui->win_system, &QPushButton::clicked,
        this, &gpanel::Tab::win_btn_clicked
    );

    connect(
        this->ui->win_tracer, &QPushButton::clicked,
        this, &gpanel::Tab::win_btn_clicked
    );

    connect(
        this->ui->client_panel, &QPushButton::clicked,
        this, &gpanel::Tab::open_client_tab
    );

    connect(
        this->panel, &ClientPanel::api_exeq,
        this, &gpanel::Tab::on_api_exeq_requested
    );

    connect(this->panel, &ClientPanel::deattached, [this](){ emit this->disconnected(this->index); });
    
    connect(this->api, &API::disconnected, this, &Tab::on_api_disconnected);
    
    this->api->set_client(client);
}

gpanel::Tab::~Tab() {
    if (this->ui) delete this->ui;
    if (this->api) delete this->api;
    if (this->panel) delete this->panel;
    logging::log_print("tab closed !");
}


void gpanel::Tab::on_api_disconnected() {
    // TODO: open a dialog to ask for confirmation to close the tab
    emit this->disconnected(this->index);
}

void gpanel::Tab::on_api_exeq_requested(const QString cmd, gpanel::exeq_callback_t cb) {
    this->api->exeq(cmd.toStdString(), cb);
}   

void gpanel::Tab::win_btn_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());
    unsigned int index = button->property("index").toUInt();

    TabWindow *win = nullptr;

    if (this->win_status[index]) { return; }

    switch(index) {
        case 0:
            win = new FileManager(nullptr);
            break;
        case 2:
            win = new GSystem(nullptr);
            break;
        case 4:
            win = new Tracer(nullptr);
            break;
    }

    // allowing only one window at a time
    if (win) {
        this->win_status[index] = 1; 
        this->ui->windows->addSubWindow(win);
        button->setStyleSheet(BTN_ACTIVE);

        win->connect(
            win, &TabWindow::close_requested,
            [this, index=index, button](){
                button->setStyleSheet(BTN_NACTIVE);
                this->win_status[index] = 0;
            }
        );

        win->connect(
            win, &TabWindow::api_exeq,
            this, &Tab::on_api_exeq_requested
        );

        win->show();
    }
}

void gpanel::Tab::init() {
    this->api->connect2();
    this->panel->set_info(&this->api->client);
}

void gpanel::Tab::open_client_tab() {
    if (this->panel->isHidden()) {
        this->panel->show();
        this->panel->raise();
        this->ui->client_panel->setStyleSheet(BTN_ACTIVE);
    } else {
        this->panel->close();
        this->ui->client_panel->setStyleSheet(BTN_NACTIVE);
    }
}
