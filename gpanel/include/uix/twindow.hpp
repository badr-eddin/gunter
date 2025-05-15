#pragma once

#include <QMdiSubWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>

#include "defcmd.hpp"
#include "utils/ui.hpp"
#include "core/client_api.hpp"
#include "utils/message.hpp"

namespace gpanel {
    class TabWindow : public QMdiSubWindow {
        Q_OBJECT

        public:
            TabWindow(QWidget*);
            ~TabWindow();

            template<typename T> void setup(T*ui, const QString title) {
                QWidget *widget = new QWidget();
                ui->setupUi(widget);
                this->setWidget(widget);
                this->setWindowTitle(title);
                this->resize(500, 300);
            };

        signals:
            void close_requested();
            void api_exeq(const QString, exeq_callback_t);
        
        private:
            void paintEvent(QPaintEvent*) override;
            void closeEvent(QCloseEvent*) override;
    };
}