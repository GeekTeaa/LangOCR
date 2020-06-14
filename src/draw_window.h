#ifndef DRAW_WINDOW_H
#define DRAW_WINDOW_H

#include <QMainWindow>
#include <QRubberBand>

class DrawWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DrawWindow(QWidget *parent = 0);
    ~DrawWindow();
    QPoint origin;

signals:
    void newDrawnItem(QPoint pos, QSize size);
    void newWindowAdded(void);
    
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QRubberBand *rubberBand_;
    bool move_rubberband;
    QPoint rubberband_offset;
};

#endif // DRAW_WINDOW_H
