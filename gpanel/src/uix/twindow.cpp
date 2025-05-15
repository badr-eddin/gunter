#include "uix/twindow.hpp"


gpanel::TabWindow::TabWindow(QWidget*parent) : QMdiSubWindow(parent) {    
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setContextMenuPolicy(Qt::NoContextMenu);
}

gpanel::TabWindow::~TabWindow() {}

void gpanel::TabWindow::closeEvent(QCloseEvent*event) {
    emit this->close_requested();
    QMdiSubWindow::closeEvent(event);
}

void gpanel::TabWindow::paintEvent(QPaintEvent*event) {
    QPainter painter(this);
    unsigned short a = 2;

    painter.setRenderHint(QPainter::Antialiasing);
    
    // window background
    painter.setPen(QColor("#13181f"));
    painter.setBrush(QColor("#0d1117"));
    painter.drawRect(QRect(a, a, width() - a*2, height() - a*2));
    
    // title bar
    QRect title_bar_rect(a, a, width() - a*2, 25);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#13181f"));
    painter.drawRect(title_bar_rect);
    
    // close button
    QRect close_rect(width() - 20 - a*2, a*2, 20, 20);
    painter.setBrush(QColor(33, 38, 45));
    painter.drawRect(close_rect);

    QIcon icon = uiutils::get_icon("actions/close.svg");
    
    icon.paint(&painter, close_rect);

    painter.setPen(QPen("#adada3"));
    QRect rect(10 + a, a, width() - 20, 25);
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, this->windowTitle());
}
