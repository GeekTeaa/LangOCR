#include <iostream>
#include <screen_overlay.h>
#include "langocr_app.h"
#include <QRubberBand>
#include <QMouseEvent>
#include <QScreen>
#include <QGuiApplication>
#include <QPainter>

ScreenOverlay::ScreenOverlay(QWidget *parent):
    QWidget(parent)
{
  QScreen *screen = QGuiApplication::primaryScreen();

  // The ScreenOverlay is a transparent, non-clickable widget that's
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

ScreenOverlay::~ScreenOverlay()
{
  return;
}

QRect ScreenOverlay::getRectangle(void)
{
  return rect_;
}

void ScreenOverlay::drawRect(QPoint pos, QSize size)
{
  rect_ = QRect(pos, size);
  this->update();
}

void ScreenOverlay::paintEvent(QPaintEvent *event)
{
  (void) event;
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setPen(Qt::red);
  painter.drawRect(rect_);
}
