#include <iostream>
#include "draw_overlay.h"
#include <QRubberBand>
#include <QMouseEvent>
#include <QScreen>
#include <QGuiApplication>

DrawOverlay::DrawOverlay(QWidget *parent):
    QWidget(parent) { 
    
  QScreen *screen = QGuiApplication::primaryScreen();

  // The OverlayWindow is a transparent, non-clickable widget that's
  // sole purpose is to be drawn on. This will allow persistent
  // drawing to be placed on the screen. 

  ///< Set the Window flags 
  this->setWindowFlags(Qt::Window |
                       Qt::FramelessWindowHint |
                       Qt::WindowStaysOnTopHint );
    
  this->setAttribute(Qt::WA_TranslucentBackground, true);
    
  this->setFixedSize(screen->size());    
  this->move(0,0);
   
  move_rubberband_ = false;
  rubber_band_ = new QRubberBand(QRubberBand::Rectangle, this);
}

DrawOverlay::~DrawOverlay() {
  delete rubber_band_;
}

void DrawOverlay::mousePressEvent(QMouseEvent *event) {
  origin = event->pos();
  if (!rubber_band_) 
    rubber_band_ = new QRubberBand(QRubberBand::Rectangle, this);

  rubber_band_->setGeometry(QRect(origin, QSize()));
  rubber_band_->show();
}

void DrawOverlay::mouseMoveEvent(QMouseEvent *event) {    
  rubber_band_->setGeometry(QRect(origin, event->pos()).normalized());
}

void DrawOverlay::mouseReleaseEvent(QMouseEvent *event) {
  // Remove an annoying warning. 
  (void) event;

  // Remove the rubberband from view
  //rubber_band_->hide();

  // Remove the current drawing window from view. 
  this->hide();

  // Make sure the QT engine has run for continuing
  QCoreApplication::processEvents();
    
  // signal that we finished drawing a box.
  emit NewDrawnItem(rubber_band_->pos(), rubber_band_->size());

  // This is temporary while I figure out a better way to do
  // this. This not modular, but will trigger a screen capture
  emit NewWindowAdded();
}
