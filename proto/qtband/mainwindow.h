#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRubberBand>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPoint origin;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    QRubberBand *rubberBand;
    bool move_rubberband;
    QPoint rubberband_offset;
};

#endif // MAINWINDOW_H
