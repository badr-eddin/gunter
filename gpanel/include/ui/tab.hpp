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
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab
{
public:
    QVBoxLayout *verticalLayout;
    QMdiArea *windows;

    void setupUi(QWidget *Tab)
    {
        if (Tab->objectName().isEmpty())
            Tab->setObjectName(QString::fromUtf8("Tab"));
        Tab->resize(684, 387);
        Tab->setStyleSheet(QString::fromUtf8("QMdiSubWindow, QMdiArea {\n"
"	border-radius: 0px;\n"
"}"));
        verticalLayout = new QVBoxLayout(Tab);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        windows = new QMdiArea(Tab);
        windows->setObjectName(QString::fromUtf8("windows"));

        verticalLayout->addWidget(windows);


        retranslateUi(Tab);

        QMetaObject::connectSlotsByName(Tab);
    } // setupUi

    void retranslateUi(QWidget *Tab)
    {
        Tab->setWindowTitle(QCoreApplication::translate("Tab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab: public Ui_Tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TAB_H
