/********************************************************************************
** Form generated from reading UI file 'tracer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TRACER_H
#define TRACER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tracer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *e;
    QFrame *env_eactions;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *remove_env;
    QPushButton *add_env;
    QFrame *klg_eactions;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start_klg;
    QPushButton *stop_klg;
    QPushButton *dump_target;
    QPushButton *export_target;
    QTabWidget *tabs;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *keylogs;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *clipboard_text;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *env_vars;

    void setupUi(QWidget *Tracer)
    {
        if (Tracer->objectName().isEmpty())
            Tracer->setObjectName(QString::fromUtf8("Tracer"));
        Tracer->resize(575, 332);
        Tracer->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout = new QVBoxLayout(Tracer);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        e = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(e);

        env_eactions = new QFrame(Tracer);
        env_eactions->setObjectName(QString::fromUtf8("env_eactions"));
        horizontalLayout_3 = new QHBoxLayout(env_eactions);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        remove_env = new QPushButton(env_eactions);
        remove_env->setObjectName(QString::fromUtf8("remove_env"));
        remove_env->setMinimumSize(QSize(80, 25));
        remove_env->setCursor(QCursor(Qt::PointingHandCursor));
        remove_env->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_3->addWidget(remove_env);

        add_env = new QPushButton(env_eactions);
        add_env->setObjectName(QString::fromUtf8("add_env"));
        add_env->setMinimumSize(QSize(80, 25));
        add_env->setCursor(QCursor(Qt::PointingHandCursor));
        add_env->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_3->addWidget(add_env);


        horizontalLayout->addWidget(env_eactions);

        klg_eactions = new QFrame(Tracer);
        klg_eactions->setObjectName(QString::fromUtf8("klg_eactions"));
        horizontalLayout_2 = new QHBoxLayout(klg_eactions);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        start_klg = new QPushButton(klg_eactions);
        start_klg->setObjectName(QString::fromUtf8("start_klg"));
        start_klg->setMinimumSize(QSize(80, 25));
        start_klg->setCursor(QCursor(Qt::PointingHandCursor));
        start_klg->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(start_klg);

        stop_klg = new QPushButton(klg_eactions);
        stop_klg->setObjectName(QString::fromUtf8("stop_klg"));
        stop_klg->setMinimumSize(QSize(80, 25));
        stop_klg->setCursor(QCursor(Qt::PointingHandCursor));
        stop_klg->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(stop_klg);


        horizontalLayout->addWidget(klg_eactions);

        dump_target = new QPushButton(Tracer);
        dump_target->setObjectName(QString::fromUtf8("dump_target"));
        dump_target->setMinimumSize(QSize(80, 25));
        dump_target->setCursor(QCursor(Qt::PointingHandCursor));
        dump_target->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout->addWidget(dump_target);

        export_target = new QPushButton(Tracer);
        export_target->setObjectName(QString::fromUtf8("export_target"));
        export_target->setMinimumSize(QSize(80, 25));
        export_target->setCursor(QCursor(Qt::PointingHandCursor));
        export_target->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout->addWidget(export_target);


        verticalLayout->addLayout(horizontalLayout);

        tabs = new QTabWidget(Tracer);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        tabs->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        tabs->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabs->setTabPosition(QTabWidget::TabPosition::North);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        keylogs = new QTreeWidget(tab);
        keylogs->setObjectName(QString::fromUtf8("keylogs"));
        keylogs->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        keylogs->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        keylogs->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        keylogs->setIndentation(0);
        keylogs->setAnimated(true);
        keylogs->header()->setDefaultSectionSize(150);

        verticalLayout_2->addWidget(keylogs);

        tabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        clipboard_text = new QTextBrowser(tab_2);
        clipboard_text->setObjectName(QString::fromUtf8("clipboard_text"));
        clipboard_text->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        clipboard_text->setFrameShape(QFrame::Shape::NoFrame);

        verticalLayout_3->addWidget(clipboard_text);

        tabs->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        env_vars = new QTreeWidget(tab_3);
        env_vars->setObjectName(QString::fromUtf8("env_vars"));
        env_vars->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        env_vars->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        env_vars->setIndentation(0);
        env_vars->header()->setDefaultSectionSize(200);

        verticalLayout_4->addWidget(env_vars);

        tabs->addTab(tab_3, QString());

        verticalLayout->addWidget(tabs);


        retranslateUi(Tracer);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Tracer);
    } // setupUi

    void retranslateUi(QWidget *Tracer)
    {
        Tracer->setWindowTitle(QCoreApplication::translate("Tracer", "Form", nullptr));
        remove_env->setText(QCoreApplication::translate("Tracer", "Remove", nullptr));
        add_env->setText(QCoreApplication::translate("Tracer", "Add", nullptr));
        start_klg->setText(QCoreApplication::translate("Tracer", "Start", nullptr));
        stop_klg->setText(QCoreApplication::translate("Tracer", "Stop", nullptr));
        dump_target->setText(QCoreApplication::translate("Tracer", "Dump", nullptr));
#if QT_CONFIG(tooltip)
        export_target->setToolTip(QCoreApplication::translate("Tracer", "Selected/All", nullptr));
#endif // QT_CONFIG(tooltip)
        export_target->setText(QCoreApplication::translate("Tracer", "Export", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = keylogs->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Tracer", "Formated Time", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Tracer", "Timestamp", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Tracer", "Key", nullptr));
        tabs->setTabText(tabs->indexOf(tab), QCoreApplication::translate("Tracer", "Keylogs", nullptr));
        tabs->setTabText(tabs->indexOf(tab_2), QCoreApplication::translate("Tracer", "Clipboard", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = env_vars->headerItem();
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("Tracer", "Value", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("Tracer", "Name", nullptr));
        tabs->setTabText(tabs->indexOf(tab_3), QCoreApplication::translate("Tracer", "Environment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tracer: public Ui_Tracer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TRACER_H
