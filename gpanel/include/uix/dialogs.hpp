#pragma once
#include <QLineEdit>
#include <QKeyEvent>
#include <Qt>

namespace gpanel
{
    class InputDialog : public QLineEdit{
        Q_OBJECT

        public:
            InputDialog(QWidget*);
            void request_input(QPoint, const std::string);
            
        signals:
            void on_abort();
            void on_success(std::string);
            
        private:
            void reset();
            void keyPressEvent(QKeyEvent*) override;            
    };
}
