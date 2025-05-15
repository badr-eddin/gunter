#include "uix/main.hpp"

gpanel::GMainWindow::GMainWindow() : QWidget(nullptr), ui(new Ui::MainWindow) {
    this->setup_main_window();
    this->setup_tab_bar();
    
    this->setup_signals();
    this->setup_icons();


    // in order to use exeq_callback_t in signals/slots it must be register by qt
    qRegisterMetaType<gpanel::exeq_callback_t>("exeq_callback_t");
}

gpanel::GMainWindow::~GMainWindow() {
    delete this->ui;
}


void gpanel::GMainWindow::setup_tab_bar() {
    this->tabbar = new QTabBar();
    this->tabbar->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    this->ui->tabs_frame->layout()->addWidget(this->tabbar);

    // add default home tab
    this->tabbar->addTab("Home");
}

void gpanel::GMainWindow::setup_main_window() {
    if (!this->ui) {
        return;
    }

    this->ui->setupUi(this);

    // remove the default window decoration
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    
}

void gpanel::GMainWindow::setup_icons() {
    this->ui->close_window->setIcon(uiutils::get_icon("actions/close.svg"));
    this->ui->restore_window->setIcon(uiutils::get_icon("actions/restore.svg"));
    this->ui->minimize_window->setIcon(uiutils::get_icon("actions/minimize.svg"));
    this->ui->login2server->setIcon(uiutils::get_icon("actions/login.svg"));
    this->ui->home_connect->setIcon(uiutils::get_icon("actions/connect.svg"));
    this->ui->home_refresh->setIcon(uiutils::get_icon("actions/refresh.svg"));
    this->ui->home_logout->setIcon(uiutils::get_icon("actions/logout.svg"));
}

void gpanel::GMainWindow::setup_signals() {
    this->connect(
        this->ui->close_window, &QPushButton::clicked,
        this, &GMainWindow::mw_exit
    );

    this->connect(
        this->ui->minimize_window, &QPushButton::clicked,
        this, &GMainWindow::mw_minimize
    );

    this->connect(
        this->ui->restore_window, &QPushButton::clicked,
        this, &GMainWindow::mw_restore
    );

    this->connect(
        this->ui->login2server, &QPushButton::clicked,
        this, &GMainWindow::login
    );

    this->connect(
        this->ui->home_refresh, &QPushButton::clicked,
        this, &GMainWindow::refresh
    );

    this->connect(
        this->ui->home_logout, &QPushButton::clicked,
        this, &GMainWindow::logout
    );

    this->connect(
        this->ui->home_connect, &QPushButton::clicked,
        this, &GMainWindow::connect2g
    );

    this->connect(
        this->tabbar, &QTabBar::tabBarClicked,
        this, &GMainWindow::tab_bar_clicked
    );
}

 
void gpanel::GMainWindow::tab_bar_clicked(unsigned short index) {
    this->ui->tabs->setCurrentIndex(index);
}

unsigned char gpanel::GMainWindow::new_tab(QWidget*widget, QString title) {
    this->ui->tabs->addWidget(widget);
    unsigned char index = this->tabbar->addTab(title);
    this->tabbar->setCurrentIndex(index);
    this->ui->tabs->setCurrentIndex(index);
    return index;
}

void gpanel::GMainWindow::remove_tab(unsigned char index) {
    if (index > 0) {
        QWidget *widget = this->ui->tabs->widget(index);
        this->ui->tabs->removeWidget(widget);
        this->tabbar->removeTab(index);
        if (widget) delete widget;
        // navigate to home
        this->ui->tabs->setCurrentIndex(0);
        this->tabbar->setCurrentIndex(0);
    }
}

void gpanel::GMainWindow::populate() {
    if (!this->ui || !this->current_clients.size()) {
        return;
    }

    // extract headers
    QStringList h_labels;

    for (const auto &[key, _] : this->current_clients[0].get<picojson::object>()) {
        h_labels.append(QString::fromStdString(key));
    }

    this->ui->connected_clients->setHeaderLabels(h_labels);

    // populate
    unsigned short index = 0;
    unsigned short obj_index = 0;

    for (const auto &item : this->current_clients) {
        if (!item.is<picojson::object>()) {
            continue;
        }

        picojson::object oitem = item.get<picojson::object>();

        QTreeWidgetItem *uitem = new QTreeWidgetItem();

        index = 0;

        for (const auto &[_, value] : oitem) {
            std::string qvalue;

            if (value.is<std::string>())
                qvalue = value.get<std::string>();

            else if (value.is<double>())
                qvalue = std::to_string((int)value.get<double>());
            
            else if (value.is<bool>())
                qvalue = value.get<bool>() ? "true" : "false";

            uitem->setText(index, QString::fromStdString(qvalue));

            index++;
        }

        uitem->setData(0, Qt::UserRole, obj_index++);

        this->ui->connected_clients->addTopLevelItem(uitem);
    }
}


void gpanel::GMainWindow::mw_exit() {
    this->close();
}

void gpanel::GMainWindow::mw_minimize() {
    this->showMinimized();
}

void gpanel::GMainWindow::mw_restore() {
    if (this->isMaximized())
        this->showNormal();
    else
        this->showMaximized();
}
