#include <iostream>
#include "draw_window.h"
#include <QRubberBand>
#include <QMouseEvent>
#include <QScreen>
#include <QGuiApplication>

DrawWindow::DrawWindow(QWidget *parent):
    QWidget(parent)
{
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
   
    move_rubberband = false;
    rubberBand_ = new QRubberBand(QRubberBand::Rectangle, this);
}

DrawWindow::~DrawWindow()
{
    delete rubberBand_;
}

void DrawWindow::mousePressEvent(QMouseEvent *event)
{
    origin = event->pos();
    if (!rubberBand_)
    {
        rubberBand_ = new QRubberBand(QRubberBand::Rectangle, this);
    }
    
    rubberBand_->setGeometry(QRect(origin, QSize()));
    rubberBand_->show();
}

void DrawWindow::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand_->setGeometry(QRect(origin, event->pos()).normalized());
}

void DrawWindow::mouseReleaseEvent(QMouseEvent *event)
{
    // Remove an annoying warning. 
    (void) event;

    // Remove the rubberband from view
    //rubberBand_->hide();

    // Remove the current drawing window from view. 
    this->hide();

    // Make sure the QT engine has run for continuing
    QCoreApplication::processEvents();
    
    // signal that we finished drawing a box.
    emit newDrawnItem(rubberBand_->pos(), rubberBand_->size());

    // This is temporary while I figure out a better way to do
    // this. This not modular, but will trigger a screen capture
    emit newWindowAdded();
}
