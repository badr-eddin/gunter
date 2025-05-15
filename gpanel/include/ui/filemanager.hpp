/********************************************************************************
** Form generated from reading UI file 'filemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FM
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *fm_search_inp;
    QPushButton *fm_new_folder;
    QPushButton *fm_new_file;
    QPushButton *fm_paste;
    QPushButton *fm_cut;
    QPushButton *fm_copy;
    QPushButton *fm_delete;
    QPushButton *fm_refresh;
    QHBoxLayout *horizontalLayout;
    QPushButton *fm_backward;
    QLineEdit *path;
    QTreeWidget *fm_files_list;

    void setupUi(QWidget *FM)
    {
        if (FM->objectName().isEmpty())
            FM->setObjectName(QString::fromUtf8("FM"));
        FM->resize(632, 298);
        verticalLayout = new QVBoxLayout(FM);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        frame_3 = new QFrame(FM);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Shape::NoFrame);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        fm_search_inp = new QLineEdit(frame_3);
        fm_search_inp->setObjectName(QString::fromUtf8("fm_search_inp"));
        fm_search_inp->setMinimumSize(QSize(0, 25));
        fm_search_inp->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        fm_search_inp->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        fm_search_inp->setReadOnly(false);

        horizontalLayout_2->addWidget(fm_search_inp);

        fm_new_folder = new QPushButton(frame_3);
        fm_new_folder->setObjectName(QString::fromUtf8("fm_new_folder"));
        fm_new_folder->setMinimumSize(QSize(25, 25));
        fm_new_folder->setMaximumSize(QSize(25, 16777215));
        fm_new_folder->setCursor(QCursor(Qt::PointingHandCursor));
        fm_new_folder->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_new_folder);

        fm_new_file = new QPushButton(frame_3);
        fm_new_file->setObjectName(QString::fromUtf8("fm_new_file"));
        fm_new_file->setMinimumSize(QSize(25, 25));
        fm_new_file->setMaximumSize(QSize(25, 16777215));
        fm_new_file->setCursor(QCursor(Qt::PointingHandCursor));
        fm_new_file->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_new_file);

        fm_paste = new QPushButton(frame_3);
        fm_paste->setObjectName(QString::fromUtf8("fm_paste"));
        fm_paste->setMinimumSize(QSize(25, 25));
        fm_paste->setMaximumSize(QSize(25, 16777215));
        fm_paste->setCursor(QCursor(Qt::PointingHandCursor));
        fm_paste->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_paste);

        fm_cut = new QPushButton(frame_3);
        fm_cut->setObjectName(QString::fromUtf8("fm_cut"));
        fm_cut->setMinimumSize(QSize(25, 25));
        fm_cut->setMaximumSize(QSize(25, 16777215));
        fm_cut->setCursor(QCursor(Qt::PointingHandCursor));
        fm_cut->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_cut);

        fm_copy = new QPushButton(frame_3);
        fm_copy->setObjectName(QString::fromUtf8("fm_copy"));
        fm_copy->setMinimumSize(QSize(25, 25));
        fm_copy->setMaximumSize(QSize(25, 16777215));
        fm_copy->setCursor(QCursor(Qt::PointingHandCursor));
        fm_copy->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_copy);

        fm_delete = new QPushButton(frame_3);
        fm_delete->setObjectName(QString::fromUtf8("fm_delete"));
        fm_delete->setMinimumSize(QSize(25, 25));
        fm_delete->setMaximumSize(QSize(25, 16777215));
        fm_delete->setCursor(QCursor(Qt::PointingHandCursor));
        fm_delete->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_delete);

        fm_refresh = new QPushButton(frame_3);
        fm_refresh->setObjectName(QString::fromUtf8("fm_refresh"));
        fm_refresh->setMinimumSize(QSize(25, 25));
        fm_refresh->setMaximumSize(QSize(25, 16777215));
        fm_refresh->setCursor(QCursor(Qt::PointingHandCursor));
        fm_refresh->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_2->addWidget(fm_refresh);


        verticalLayout->addWidget(frame_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        fm_backward = new QPushButton(FM);
        fm_backward->setObjectName(QString::fromUtf8("fm_backward"));
        fm_backward->setMinimumSize(QSize(25, 25));
        fm_backward->setMaximumSize(QSize(25, 16777215));
        fm_backward->setCursor(QCursor(Qt::PointingHandCursor));
        fm_backward->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout->addWidget(fm_backward);

        path = new QLineEdit(FM);
        path->setObjectName(QString::fromUtf8("path"));
        path->setMinimumSize(QSize(0, 25));
        path->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        path->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        path->setReadOnly(false);

        horizontalLayout->addWidget(path);


        verticalLayout->addLayout(horizontalLayout);

        fm_files_list = new QTreeWidget(FM);
        fm_files_list->setObjectName(QString::fromUtf8("fm_files_list"));
        fm_files_list->setMinimumSize(QSize(587, 0));
        fm_files_list->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        fm_files_list->setFrameShape(QFrame::Shape::NoFrame);
        fm_files_list->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        fm_files_list->setProperty("showDropIndicator", QVariant(false));
        fm_files_list->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
        fm_files_list->setDefaultDropAction(Qt::DropAction::IgnoreAction);
        fm_files_list->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        fm_files_list->setIconSize(QSize(20, 20));
        fm_files_list->setTextElideMode(Qt::TextElideMode::ElideMiddle);
        fm_files_list->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        fm_files_list->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        fm_files_list->setIndentation(0);
        fm_files_list->header()->setDefaultSectionSize(250);

        verticalLayout->addWidget(fm_files_list);


        retranslateUi(FM);

        QMetaObject::connectSlotsByName(FM);
    } // setupUi

    void retranslateUi(QWidget *FM)
    {
        FM->setWindowTitle(QCoreApplication::translate("FM", "Form", nullptr));
        frame_3->setProperty("type", QVariant(QCoreApplication::translate("FM", "elevateds", nullptr)));
        fm_search_inp->setPlaceholderText(QCoreApplication::translate("FM", "search (local)", nullptr));
#if QT_CONFIG(tooltip)
        fm_new_folder->setToolTip(QCoreApplication::translate("FM", "New Folder", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_new_folder->setText(QString());
#if QT_CONFIG(tooltip)
        fm_new_file->setToolTip(QCoreApplication::translate("FM", "New File", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_new_file->setText(QString());
#if QT_CONFIG(tooltip)
        fm_paste->setToolTip(QCoreApplication::translate("FM", "Paste", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_paste->setText(QString());
#if QT_CONFIG(tooltip)
        fm_cut->setToolTip(QCoreApplication::translate("FM", "New File", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_cut->setText(QString());
#if QT_CONFIG(tooltip)
        fm_copy->setToolTip(QCoreApplication::translate("FM", "Copy", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_copy->setText(QString());
#if QT_CONFIG(tooltip)
        fm_delete->setToolTip(QCoreApplication::translate("FM", "Delete", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_delete->setText(QString());
#if QT_CONFIG(tooltip)
        fm_refresh->setToolTip(QCoreApplication::translate("FM", "Refresh", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_refresh->setText(QString());
#if QT_CONFIG(tooltip)
        fm_backward->setToolTip(QCoreApplication::translate("FM", "New Folder", nullptr));
#endif // QT_CONFIG(tooltip)
        fm_backward->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = fm_files_list->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("FM", "Modified", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("FM", "Size", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("FM", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FM: public Ui_FM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FILEMANAGER_H
