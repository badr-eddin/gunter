#include "uix/tab.hpp"


gpanel::Tab::Tab(QWidget *parent, server_creds_t *creds, const std::string uid) 
    : QWidget(parent), ui(new Ui::Tab), API(creds, uid) {

    this->ui->setupUi(this);

    this->ui->windows->setBackground(QBrush(Qt::transparent));

    TabWindow *win = new FileManager(nullptr, TAB_EXEQ_CB_ARG);
    
    this->ui->windows->addSubWindow(win);
}

gpanel::Tab::~Tab() {
    delete this->ui;
}


void gpanel::Tab::init() {
    this->connect2();
}


QWidget* gpanel::Tab::get_widget() { return this; }
