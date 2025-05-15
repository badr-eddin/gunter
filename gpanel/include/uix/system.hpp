#pragma once
#include "ui/system.hpp"
#include "uix/twindow.hpp"


namespace gpanel {
    class GSystem : public TabWindow {
        Q_OBJECT 
        
        public:
            GSystem(QWidget*);
            ~GSystem();

        private:
            Ui::System *ui;
    }; 
}