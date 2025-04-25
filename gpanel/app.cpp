#include "uix/main.hpp"


int main(int argc, char *argv[])
{
    // Creating App
    QApplication app(argc, argv);
    
    // load the theme here
    QString style = load_style("../assets/theme/default.qss");

    // Apply theme on the Application
    app.setStyleSheet(style);

    // Main Window
    gpanel::GMainWindow window;

    // show the window
    window.show();

    // exec app and return it exit status code
    return app.exec();
}