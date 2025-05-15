/********************************************************************************
** Form generated from reading UI file 'tab.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TAB_H
#define TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab
{
public:
    QVBoxLayout *verticalLayout;
    QMdiArea *windows;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *tab_tools;
    QHBoxLayout *horizontalLayout;
    QPushButton *win_file_exp;
    QPushButton *win_file_tr;
    QPushButton *win_system;
    QPushButton *win_terminal;
    QPushButton *win_tracer;
    QSpacerItem *horizontalSpacer;
    QPushButton *client_panel;

    void setupUi(QWidget *Tab)
    {
        if (Tab->objectName().isEmpty())
            Tab->setObjectName(QString::fromUtf8("Tab"));
        Tab->resize(694, 157);
        Tab->setStyleSheet(QString::fromUtf8("QMdiSubWindow, QMdiArea {\n"
"	border-radius: 0px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(Tab);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        windows = new QMdiArea(Tab);
        windows->setObjectName(QString::fromUtf8("windows"));

        verticalLayout->addWidget(windows);

        frame = new QFrame(Tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Shape::NoFrame);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(4, 0, 4, 4);
        tab_tools = new QFrame(frame);
        tab_tools->setObjectName(QString::fromUtf8("tab_tools"));
        tab_tools->setMinimumSize(QSize(0, 32));
        tab_tools->setFrameShape(QFrame::Shape::NoFrame);
        tab_tools->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(tab_tools);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        win_file_exp = new QPushButton(tab_tools);
        win_file_exp->setObjectName(QString::fromUtf8("win_file_exp"));
        win_file_exp->setMinimumSize(QSize(30, 28));
        win_file_exp->setMaximumSize(QSize(30, 28));
        win_file_exp->setCursor(QCursor(Qt::PointingHandCursor));
        win_file_exp->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        win_file_exp->setProperty("index", QVariant(0u));

        horizontalLayout->addWidget(win_file_exp);

        win_file_tr = new QPushButton(tab_tools);
        win_file_tr->setObjectName(QString::fromUtf8("win_file_tr"));
        win_file_tr->setMinimumSize(QSize(30, 28));
        win_file_tr->setMaximumSize(QSize(30, 28));
        win_file_tr->setCursor(QCursor(Qt::PointingHandCursor));
        win_file_tr->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        win_file_tr->setProperty("index", QVariant(1u));

        horizontalLayout->addWidget(win_file_tr);

        win_system = new QPushButton(tab_tools);
        win_system->setObjectName(QString::fromUtf8("win_system"));
        win_system->setMinimumSize(QSize(30, 28));
        win_system->setMaximumSize(QSize(30, 28));
        win_system->setCursor(QCursor(Qt::PointingHandCursor));
        win_system->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        win_system->setProperty("index", QVariant(2u));

        horizontalLayout->addWidget(win_system);

        win_terminal = new QPushButton(tab_tools);
        win_terminal->setObjectName(QString::fromUtf8("win_terminal"));
        win_terminal->setMinimumSize(QSize(30, 28));
        win_terminal->setMaximumSize(QSize(30, 28));
        win_terminal->setCursor(QCursor(Qt::PointingHandCursor));
        win_terminal->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        win_terminal->setProperty("index", QVariant(3u));

        horizontalLayout->addWidget(win_terminal);

        win_tracer = new QPushButton(tab_tools);
        win_tracer->setObjectName(QString::fromUtf8("win_tracer"));
        win_tracer->setMinimumSize(QSize(30, 28));
        win_tracer->setMaximumSize(QSize(30, 28));
        win_tracer->setCursor(QCursor(Qt::PointingHandCursor));
        win_tracer->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        win_tracer->setProperty("index", QVariant(4u));

        horizontalLayout->addWidget(win_tracer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        client_panel = new QPushButton(tab_tools);
        client_panel->setObjectName(QString::fromUtf8("client_panel"));
        client_panel->setMinimumSize(QSize(30, 28));
        client_panel->setMaximumSize(QSize(30, 28));
        client_panel->setCursor(QCursor(Qt::PointingHandCursor));
        client_panel->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        client_panel->setProperty("index", QVariant(4u));

        horizontalLayout->addWidget(client_panel);


        horizontalLayout_2->addWidget(tab_tools);


        verticalLayout->addWidget(frame);


        retranslateUi(Tab);

        QMetaObject::connectSlotsByName(Tab);
    } // setupUi

    void retranslateUi(QWidget *Tab)
    {
        Tab->setWindowTitle(QCoreApplication::translate("Tab", "Form", nullptr));
#if QT_CONFIG(tooltip)
        win_file_exp->setToolTip(QCoreApplication::translate("Tab", "File Explorer", nullptr));
#endif // QT_CONFIG(tooltip)
        win_file_exp->setText(QString());
#if QT_CONFIG(tooltip)
        win_file_tr->setToolTip(QCoreApplication::translate("Tab", "Transporter", nullptr));
#endif // QT_CONFIG(tooltip)
        win_file_tr->setText(QString());
#if QT_CONFIG(tooltip)
        win_system->setToolTip(QCoreApplication::translate("Tab", "System", nullptr));
#endif // QT_CONFIG(tooltip)
        win_system->setText(QString());
#if QT_CONFIG(tooltip)
        win_terminal->setToolTip(QCoreApplication::translate("Tab", "Terminal", nullptr));
#endif // QT_CONFIG(tooltip)
        win_terminal->setText(QString());
#if QT_CONFIG(tooltip)
        win_tracer->setToolTip(QCoreApplication::translate("Tab", "Tracer", nullptr));
#endif // QT_CONFIG(tooltip)
        win_tracer->setText(QString());
#if QT_CONFIG(tooltip)
        client_panel->setToolTip(QCoreApplication::translate("Tab", "Client", nullptr));
#endif // QT_CONFIG(tooltip)
        client_panel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tab: public Ui_Tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TAB_H
