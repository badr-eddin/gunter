#include "uix/dialogs.hpp"

gpanel::InputDialog::InputDialog(QWidget*parent) : QLineEdit(parent) {
    this->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
    this->setFixedSize(150, 30);
}

void gpanel::InputDialog::request_input(QPoint pos, const std::string placeholder) {
    this->setPlaceholderText(QString::fromStdString(placeholder));
    this->move(pos);
    this->show();
    this->raise();
}

void gpanel::InputDialog::reset() {
    disconnect(this, &gpanel::InputDialog::on_success, nullptr, nullptr);
    disconnect(this, &gpanel::InputDialog::on_abort, nullptr, nullptr);
    this->clear();
    this->close();
}

void gpanel::InputDialog::keyPressEvent(QKeyEvent*event) {
    if (event->key() == Qt::Key_Escape) {
        emit this->on_abort();
        this->reset();
    }
    else if (event->key() == Qt::Key_Return) {
        emit this->on_success(this->text().toStdString());
        this->reset();
    }

    QLineEdit::keyPressEvent(event);
}
