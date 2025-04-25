#pragma once

#include <QMdiSubWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>

#include "defcmd.hpp"

#include "utils/ui.hpp"
#include "utils/message.hpp"

namespace gpanel {
    using exeq_sign_t = std::function<void(const std::string, std::function<void(const std::string)>)>;

    class TabWindow : public QMdiSubWindow {
        public:
        gpanel::exeq_sign_t exeq;

            TabWindow(QWidget*, gpanel::exeq_sign_t);
            ~TabWindow();
        
        private:
            void paintEvent(QPaintEvent*) override;
    };
}