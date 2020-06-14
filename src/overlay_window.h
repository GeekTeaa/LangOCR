#ifndef OVERLAY_WINDOW_H
#define OVERLAY_WINDOW_H

#include <QMainWindow>
#include <QRubberBand>

// namespace Ui {
// class OverlayWindow;
// }

class OverlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OverlayWindow(QWidget *parent = 0);
    ~OverlayWindow();
    QRect getRectangle(void);
    //QRect setRectangle(void);

public slots:
    void drawRect(QPoint pos, QSize size);
    
protected:
    void paintEvent(QPaintEvent *event);

private:
    QRect rect_;
};

#endif // OVERLAY_WINDOW_H
