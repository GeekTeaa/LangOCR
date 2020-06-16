#include <iostream>
#include <overlay_window.h>
#include "langocr_app.h"
#include <QRubberBand>
#include <QMouseEvent>
#include <QScreen>
#include <QGuiApplication>
#include <QPainter>

OverlayWindow::OverlayWindow(QWidget *parent):
    QWidget(parent)
{
    QScreen *screen = QGuiApplication::primaryScreen();

    // The OverlayWindow is a transparent, non-clickable widget that's
    // sole purpose is to be drawn on. This will allow persistent
    // drawing to be placed on the screen. 

    ///< Set the Window flags 
    this->setWindowFlags(Qt::Window |
                         Qt::FramelessWindowHint |
                         Qt::WindowStaysOnTopHint |
                         Qt::WindowTransparentForInput |
                         Qt::X11BypassWindowManagerHint	);
    
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    this->setAttribute(Qt::WA_X11NetWmWindowTypeDesktop, true);

    this->setFocusPolicy(Qt::NoFocus);
    this->setFixedSize(screen->size());    
    //this->setAttribute(Qt::WA_ShowWithoutActivating, true);
    //this->setAttribute(Qt::WA_X11DoNotAcceptFocus, true);
    this->move(0,0);
}

OverlayWindow::~OverlayWindow()
{
    return;
}

QRect OverlayWindow::getRectangle(void)
{
    return rect_;
}

void OverlayWindow::drawRect(QPoint pos, QSize size)
{
    rect_ = QRect(pos, size);
    this->update();
}

void OverlayWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::red);
    painter.drawRect(rect_);
}
