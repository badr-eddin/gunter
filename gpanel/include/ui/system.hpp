/********************************************************************************
** Form generated from reading UI file 'system.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_System
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QPushButton *sysc_ashutdown;
    QPushButton *sysc_shutdown;
    QPushButton *sysc_reboot;
    QPushButton *pushButton_3;
    QPushButton *sysc_areboot;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *System)
    {
        if (System->objectName().isEmpty())
            System->setObjectName(QString::fromUtf8("System"));
        System->resize(635, 363);
        verticalLayout = new QVBoxLayout(System);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        tabWidget = new QTabWidget(System);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sysc_ashutdown = new QPushButton(tab_2);
        sysc_ashutdown->setObjectName(QString::fromUtf8("sysc_ashutdown"));
        sysc_ashutdown->setMinimumSize(QSize(60, 25));
        sysc_ashutdown->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        gridLayout->addWidget(sysc_ashutdown, 0, 2, 1, 1);

        sysc_shutdown = new QPushButton(tab_2);
        sysc_shutdown->setObjectName(QString::fromUtf8("sysc_shutdown"));
        sysc_shutdown->setMinimumSize(QSize(60, 25));
        sysc_shutdown->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        gridLayout->addWidget(sysc_shutdown, 0, 0, 1, 1);

        sysc_reboot = new QPushButton(tab_2);
        sysc_reboot->setObjectName(QString::fromUtf8("sysc_reboot"));
        sysc_reboot->setMinimumSize(QSize(60, 25));
        sysc_reboot->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        gridLayout->addWidget(sysc_reboot, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(60, 25));
        pushButton_3->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);

        sysc_areboot = new QPushButton(tab_2);
        sysc_areboot->setObjectName(QString::fromUtf8("sysc_areboot"));
        sysc_areboot->setMinimumSize(QSize(60, 25));
        sysc_areboot->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        gridLayout->addWidget(sysc_areboot, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 6);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(System);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(System);
    } // setupUi

    void retranslateUi(QWidget *System)
    {
        System->setWindowTitle(QCoreApplication::translate("System", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("System", "About", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("System", "Processes", nullptr));
        sysc_ashutdown->setText(QCoreApplication::translate("System", "Abort Shutdown", nullptr));
        sysc_shutdown->setText(QCoreApplication::translate("System", "Shutdown", nullptr));
        sysc_reboot->setText(QCoreApplication::translate("System", "Reboot", nullptr));
        pushButton_3->setText(QCoreApplication::translate("System", "Lock", nullptr));
        sysc_areboot->setText(QCoreApplication::translate("System", "Abort Reboot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("System", "Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class System: public Ui_System {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SYSTEM_H
