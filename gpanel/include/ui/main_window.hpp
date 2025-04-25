/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QFrame *central_widget;
    QGridLayout *gridLayout_5;
    QFrame *header;
    QHBoxLayout *horizontalLayout_13;
    QFrame *tabs_frame;
    QHBoxLayout *_3;
    QFrame *window_control_buttons;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *minimize_window;
    QPushButton *restore_window;
    QPushButton *close_window;
    QFrame *body;
    QGridLayout *gridLayout_2;
    QStackedWidget *tabs;
    QWidget *home_page;
    QGridLayout *gridLayout_3;
    QStackedWidget *home_pages;
    QWidget *login;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QFrame *login_form;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *login_remember_creds;
    QPushButton *login2server;
    QLineEdit *login_server_username;
    QLineEdit *login_server_password;
    QLineEdit *login_server_ip;
    QSpinBox *login_server_port;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QLabel *login_msg_label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *clients;
    QVBoxLayout *verticalLayout;
    QFrame *home_actions;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *home_connect;
    QPushButton *home_refresh;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *home_logout;
    QTreeWidget *connected_clients;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(861, 550);
        MainWindow->setMinimumSize(QSize(0, 400));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        central_widget = new QFrame(MainWindow);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        central_widget->setFrameShape(QFrame::Shape::StyledPanel);
        central_widget->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_5 = new QGridLayout(central_widget);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        header = new QFrame(central_widget);
        header->setObjectName(QString::fromUtf8("header"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy);
        header->setMinimumSize(QSize(0, 29));
        header->setMaximumSize(QSize(16777215, 29));
        header->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        header->setFrameShape(QFrame::Shape::NoFrame);
        header->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_13 = new QHBoxLayout(header);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        tabs_frame = new QFrame(header);
        tabs_frame->setObjectName(QString::fromUtf8("tabs_frame"));
        tabs_frame->setMinimumSize(QSize(25, 25));
        tabs_frame->setCursor(QCursor(Qt::ArrowCursor));
        _3 = new QHBoxLayout(tabs_frame);
        _3->setSpacing(2);
        _3->setObjectName(QString::fromUtf8("_3"));
        _3->setContentsMargins(2, 2, 0, 0);

        horizontalLayout_13->addWidget(tabs_frame);

        window_control_buttons = new QFrame(header);
        window_control_buttons->setObjectName(QString::fromUtf8("window_control_buttons"));
        sizePolicy.setHeightForWidth(window_control_buttons->sizePolicy().hasHeightForWidth());
        window_control_buttons->setSizePolicy(sizePolicy);
        window_control_buttons->setFrameShape(QFrame::Shape::NoFrame);
        window_control_buttons->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_12 = new QHBoxLayout(window_control_buttons);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(1, 2, 2, 2);
        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        minimize_window = new QPushButton(window_control_buttons);
        minimize_window->setObjectName(QString::fromUtf8("minimize_window"));
        minimize_window->setMinimumSize(QSize(25, 25));
        minimize_window->setMaximumSize(QSize(25, 25));
        minimize_window->setCursor(QCursor(Qt::PointingHandCursor));
        minimize_window->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        minimize_window->setIconSize(QSize(22, 22));

        horizontalLayout_12->addWidget(minimize_window);

        restore_window = new QPushButton(window_control_buttons);
        restore_window->setObjectName(QString::fromUtf8("restore_window"));
        restore_window->setMinimumSize(QSize(25, 25));
        restore_window->setMaximumSize(QSize(25, 25));
        restore_window->setCursor(QCursor(Qt::PointingHandCursor));
        restore_window->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        restore_window->setIconSize(QSize(22, 22));

        horizontalLayout_12->addWidget(restore_window);

        close_window = new QPushButton(window_control_buttons);
        close_window->setObjectName(QString::fromUtf8("close_window"));
        close_window->setMinimumSize(QSize(25, 25));
        close_window->setMaximumSize(QSize(25, 25));
        close_window->setCursor(QCursor(Qt::PointingHandCursor));
        close_window->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        close_window->setIconSize(QSize(24, 24));

        horizontalLayout_12->addWidget(close_window);


        horizontalLayout_13->addWidget(window_control_buttons);


        gridLayout_5->addWidget(header, 0, 0, 1, 2);

        body = new QFrame(central_widget);
        body->setObjectName(QString::fromUtf8("body"));
        body->setFrameShape(QFrame::Shape::NoFrame);
        body->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(body);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tabs = new QStackedWidget(body);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        home_page = new QWidget();
        home_page->setObjectName(QString::fromUtf8("home_page"));
        gridLayout_3 = new QGridLayout(home_page);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        home_pages = new QStackedWidget(home_page);
        home_pages->setObjectName(QString::fromUtf8("home_pages"));
        login = new QWidget();
        login->setObjectName(QString::fromUtf8("login"));
        gridLayout_6 = new QGridLayout(login);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(331, 127, QSizePolicy::Policy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(259, 250, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 0, 1, 1);

        login_form = new QFrame(login);
        login_form->setObjectName(QString::fromUtf8("login_form"));
        sizePolicy.setHeightForWidth(login_form->sizePolicy().hasHeightForWidth());
        login_form->setSizePolicy(sizePolicy);
        login_form->setFrameShape(QFrame::Shape::NoFrame);
        login_form->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(login_form);
        gridLayout_4->setSpacing(8);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(4, 4, 4, 4);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        login_remember_creds = new QCheckBox(login_form);
        login_remember_creds->setObjectName(QString::fromUtf8("login_remember_creds"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(login_remember_creds->sizePolicy().hasHeightForWidth());
        login_remember_creds->setSizePolicy(sizePolicy1);
        login_remember_creds->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout->addWidget(login_remember_creds);

        login2server = new QPushButton(login_form);
        login2server->setObjectName(QString::fromUtf8("login2server"));
        login2server->setMinimumSize(QSize(60, 25));
        login2server->setCursor(QCursor(Qt::PointingHandCursor));
        login2server->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        login2server->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(login2server);


        gridLayout_4->addLayout(horizontalLayout, 6, 1, 1, 3);

        login_server_username = new QLineEdit(login_form);
        login_server_username->setObjectName(QString::fromUtf8("login_server_username"));
        login_server_username->setMinimumSize(QSize(0, 28));
        login_server_username->setMaximumSize(QSize(16777215, 28));
        login_server_username->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

        gridLayout_4->addWidget(login_server_username, 2, 2, 1, 2);

        login_server_password = new QLineEdit(login_form);
        login_server_password->setObjectName(QString::fromUtf8("login_server_password"));
        login_server_password->setMinimumSize(QSize(0, 28));
        login_server_password->setMaximumSize(QSize(16777215, 28));
        login_server_password->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        login_server_password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_4->addWidget(login_server_password, 3, 2, 1, 2);

        login_server_ip = new QLineEdit(login_form);
        login_server_ip->setObjectName(QString::fromUtf8("login_server_ip"));
        login_server_ip->setMinimumSize(QSize(80, 28));
        login_server_ip->setMaximumSize(QSize(16777215, 28));
        login_server_ip->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

        gridLayout_4->addWidget(login_server_ip, 1, 2, 1, 1);

        login_server_port = new QSpinBox(login_form);
        login_server_port->setObjectName(QString::fromUtf8("login_server_port"));
        login_server_port->setMinimumSize(QSize(50, 28));
        login_server_port->setMaximumSize(QSize(60, 28));
        login_server_port->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        login_server_port->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        login_server_port->setMinimum(100);
        login_server_port->setMaximum(65535);
        login_server_port->setValue(4444);

        gridLayout_4->addWidget(login_server_port, 1, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(verticalSpacer_4, 0, 2, 1, 1);

        label = new QLabel(login_form);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 2, 4, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(verticalSpacer_5, 7, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(verticalSpacer_3, 4, 2, 1, 1);

        label_2 = new QLabel(login_form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        label_3 = new QLabel(login_form);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 3, 1, 1, 1);

        login_msg_label = new QLabel(login_form);
        login_msg_label->setObjectName(QString::fromUtf8("login_msg_label"));
        login_msg_label->setMinimumSize(QSize(0, 25));
        login_msg_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(login_msg_label, 5, 1, 1, 3);


        gridLayout_6->addWidget(login_form, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(259, 250, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(331, 126, QSizePolicy::Policy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_2, 2, 1, 1, 1);

        home_pages->addWidget(login);
        clients = new QWidget();
        clients->setObjectName(QString::fromUtf8("clients"));
        verticalLayout = new QVBoxLayout(clients);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        home_actions = new QFrame(clients);
        home_actions->setObjectName(QString::fromUtf8("home_actions"));
        home_actions->setMinimumSize(QSize(0, 30));
        home_actions->setFrameShape(QFrame::Shape::NoFrame);
        home_actions->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(home_actions);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 0, 3, 0);
        home_connect = new QPushButton(home_actions);
        home_connect->setObjectName(QString::fromUtf8("home_connect"));
        home_connect->setMinimumSize(QSize(60, 0));
        home_connect->setMaximumSize(QSize(16777215, 24));
        home_connect->setCursor(QCursor(Qt::PointingHandCursor));
        home_connect->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        home_connect->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(home_connect);

        home_refresh = new QPushButton(home_actions);
        home_refresh->setObjectName(QString::fromUtf8("home_refresh"));
        home_refresh->setMinimumSize(QSize(60, 0));
        home_refresh->setMaximumSize(QSize(16777215, 24));
        home_refresh->setCursor(QCursor(Qt::PointingHandCursor));
        home_refresh->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        home_refresh->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(home_refresh);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        home_logout = new QPushButton(home_actions);
        home_logout->setObjectName(QString::fromUtf8("home_logout"));
        home_logout->setMinimumSize(QSize(60, 0));
        home_logout->setMaximumSize(QSize(16777215, 24));
        home_logout->setCursor(QCursor(Qt::PointingHandCursor));
        home_logout->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        home_logout->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(home_logout);


        verticalLayout->addWidget(home_actions);

        connected_clients = new QTreeWidget(clients);
        connected_clients->setObjectName(QString::fromUtf8("connected_clients"));
        connected_clients->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        connected_clients->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        connected_clients->setFrameShape(QFrame::Shape::NoFrame);
        connected_clients->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        connected_clients->setAlternatingRowColors(false);
        connected_clients->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        connected_clients->setIndentation(0);
        connected_clients->header()->setDefaultSectionSize(120);

        verticalLayout->addWidget(connected_clients);

        home_pages->addWidget(clients);

        gridLayout_3->addWidget(home_pages, 0, 0, 1, 1);

        tabs->addWidget(home_page);

        gridLayout_2->addWidget(tabs, 0, 0, 1, 1);


        gridLayout_5->addWidget(body, 1, 0, 1, 2);


        gridLayout->addWidget(central_widget, 0, 0, 1, 1);


        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        minimize_window->setText(QString());
#if QT_CONFIG(shortcut)
        minimize_window->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+M", nullptr));
#endif // QT_CONFIG(shortcut)
        restore_window->setText(QString());
#if QT_CONFIG(shortcut)
        restore_window->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+R", nullptr));
#endif // QT_CONFIG(shortcut)
        close_window->setText(QString());
#if QT_CONFIG(shortcut)
        close_window->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        login_form->setProperty("type", QVariant(QCoreApplication::translate("MainWindow", "elevated", nullptr)));
        login_remember_creds->setText(QCoreApplication::translate("MainWindow", "Remember me", nullptr));
        login2server->setText(QCoreApplication::translate("MainWindow", "Authenticate", nullptr));
        login_server_username->setText(QCoreApplication::translate("MainWindow", "gunter", nullptr));
        login_server_password->setText(QCoreApplication::translate("MainWindow", "superpwsd", nullptr));
        login_server_ip->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        login_server_ip->setPlaceholderText(QCoreApplication::translate("MainWindow", "0.0.0.0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        login_msg_label->setText(QString());
        home_actions->setProperty("type", QVariant(QCoreApplication::translate("MainWindow", "elevated", nullptr)));
        home_connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        home_refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        home_logout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = connected_clients->headerItem();
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("MainWindow", "uid", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("MainWindow", "version", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("MainWindow", "Address", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "system", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "hostname", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "tag", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WINDOW_H
