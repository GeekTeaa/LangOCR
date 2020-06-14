#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)    
{
    move_rubberband = false;
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setGeometry(0,0,50,50);
    rubberBand->show();
}

MainWindow::~MainWindow()
{
    delete rubberBand; 
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    origin = event->pos();
    if (!rubberBand)
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setGeometry(QRect(origin, QSize()));
    rubberBand->show();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    rubberBand->hide();
    // determine selection, for example using QRect::intersects()
    // and QRect::contains().
}

// 
// void MainWindow::mousePressEvent(QMouseEvent *e)
// {
//     if(rubberBand->geometry().contains(e->pos()))
//     {
//         rubberband_offset = e->pos() - rubberBand->pos();
//         move_rubberband = true;
//     }
// }
// 
// void MainWindow::mouseMoveEvent(QMouseEvent *e)
// {
//     if(move_rubberband)
//     {
//         rubberBand->move(e->pos() - rubberband_offset);
//     }
// }
// 
// void MainWindow::mouseReleaseEvent(QMouseEvent *e)
// {
//     move_rubberband = false;
// }
