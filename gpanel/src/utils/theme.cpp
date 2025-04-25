#include "utils/theme.hpp"


QString load_style(const QString &path) {
    // initiating QFile
    QFile file(path);  // it takes the path by refrence

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return "";
    }

    return QString::fromUtf8(file.readAll());
}