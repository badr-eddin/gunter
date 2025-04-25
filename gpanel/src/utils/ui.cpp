#include "utils/ui.hpp"

QIcon uiutils::get_icon(std::string icon) {
    icon = "../assets/icons/" + icon;

    QString icon_path = QString::fromStdString(icon);
        
        // check if the file exists before creating an icon
        if (!QFile::exists(icon_path)) {
            return QIcon();  // return an empty icon if the file doesn't exist
        }

        return QIcon(icon_path);
}
