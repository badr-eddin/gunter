/********************************************************************************
** Form generated from reading UI file 'tab_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TAB_PANEL_H
#define TAB_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TPanel
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *cl_fname;
    QLabel *cl_version;
    QLabel *cl_address;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *cl_ctime;
    QSpacerItem *horizontalSpacer;
    QPushButton *cl_hibern;
    QPushButton *cl_kill;

    void setupUi(QWidget *TPanel)
    {
        if (TPanel->objectName().isEmpty())
            TPanel->setObjectName(QString::fromUtf8("TPanel"));
        TPanel->resize(212, 80);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TPanel->sizePolicy().hasHeightForWidth());
        TPanel->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(TPanel);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        cl_fname = new QLabel(TPanel);
        cl_fname->setObjectName(QString::fromUtf8("cl_fname"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cl_fname->sizePolicy().hasHeightForWidth());
        cl_fname->setSizePolicy(sizePolicy1);
        cl_fname->setMinimumSize(QSize(0, 20));
        cl_fname->setMaximumSize(QSize(16777215, 20));
        cl_fname->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(cl_fname, 4, 0, 1, 1);

        cl_version = new QLabel(TPanel);
        cl_version->setObjectName(QString::fromUtf8("cl_version"));
        sizePolicy1.setHeightForWidth(cl_version->sizePolicy().hasHeightForWidth());
        cl_version->setSizePolicy(sizePolicy1);
        cl_version->setMinimumSize(QSize(0, 20));
        cl_version->setMaximumSize(QSize(16777215, 20));
        cl_version->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(cl_version, 4, 1, 1, 1);

        cl_address = new QLabel(TPanel);
        cl_address->setObjectName(QString::fromUtf8("cl_address"));
        sizePolicy1.setHeightForWidth(cl_address->sizePolicy().hasHeightForWidth());
        cl_address->setSizePolicy(sizePolicy1);
        cl_address->setMinimumSize(QSize(0, 20));
        cl_address->setMaximumSize(QSize(16777215, 20));
        cl_address->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(cl_address, 5, 0, 1, 2);

        horizontalFrame = new QFrame(TPanel);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalFrame->sizePolicy().hasHeightForWidth());
        horizontalFrame->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cl_ctime = new QLabel(horizontalFrame);
        cl_ctime->setObjectName(QString::fromUtf8("cl_ctime"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cl_ctime->sizePolicy().hasHeightForWidth());
        cl_ctime->setSizePolicy(sizePolicy3);
        cl_ctime->setMinimumSize(QSize(0, 20));
        cl_ctime->setMaximumSize(QSize(16777215, 20));
        cl_ctime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(cl_ctime);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cl_hibern = new QPushButton(horizontalFrame);
        cl_hibern->setObjectName(QString::fromUtf8("cl_hibern"));
        cl_hibern->setMinimumSize(QSize(20, 20));
        cl_hibern->setMaximumSize(QSize(20, 20));
        cl_hibern->setCursor(QCursor(Qt::PointingHandCursor));
        cl_hibern->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        cl_hibern->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(cl_hibern);

        cl_kill = new QPushButton(horizontalFrame);
        cl_kill->setObjectName(QString::fromUtf8("cl_kill"));
        cl_kill->setMinimumSize(QSize(20, 20));
        cl_kill->setMaximumSize(QSize(20, 20));
        cl_kill->setCursor(QCursor(Qt::PointingHandCursor));
        cl_kill->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        cl_kill->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(cl_kill);


        gridLayout->addWidget(horizontalFrame, 8, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(TPanel);

        QMetaObject::connectSlotsByName(TPanel);
    } // setupUi

    void retranslateUi(QWidget *TPanel)
    {
        TPanel->setWindowTitle(QCoreApplication::translate("TPanel", "Form", nullptr));
#if QT_CONFIG(tooltip)
        cl_fname->setToolTip(QCoreApplication::translate("TPanel", "client name", nullptr));
#endif // QT_CONFIG(tooltip)
        cl_fname->setText(QCoreApplication::translate("TPanel", "gunter@excomputer", nullptr));
#if QT_CONFIG(tooltip)
        cl_version->setToolTip(QCoreApplication::translate("TPanel", "version", nullptr));
#endif // QT_CONFIG(tooltip)
        cl_version->setText(QCoreApplication::translate("TPanel", "0.0.1-pen", nullptr));
#if QT_CONFIG(tooltip)
        cl_address->setToolTip(QCoreApplication::translate("TPanel", "address", nullptr));
#endif // QT_CONFIG(tooltip)
        cl_address->setText(QCoreApplication::translate("TPanel", "245.235.231.120:2020", nullptr));
#if QT_CONFIG(tooltip)
        cl_ctime->setToolTip(QCoreApplication::translate("TPanel", "connected on", nullptr));
#endif // QT_CONFIG(tooltip)
        cl_ctime->setText(QCoreApplication::translate("TPanel", "20/05/2025 12:05", nullptr));
#if QT_CONFIG(tooltip)
        cl_hibern->setToolTip(QCoreApplication::translate("TPanel", "Hibernate", nullptr));
#endif // QT_CONFIG(tooltip)
        cl_hibern->setText(QString());
#if QT_CONFIG(tooltip)
        cl_kill->setToolTip(QCoreApplication::translate("TPanel", "Kill", nullptr));
#endif // QT_CONFIG(tooltip)
        cl_kill->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TPanel: public Ui_TPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TAB_PANEL_H
