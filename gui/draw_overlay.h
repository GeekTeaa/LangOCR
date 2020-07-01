#ifndef DRAW_WINDOW_H
#define DRAW_WINDOW_H

#include <QMainWindow>
#include <QRubberBand>

class DrawOverlay : public QWidget {
  Q_OBJECT

 public:
  explicit DrawOverlay(QWidget *parent = 0);
  ~DrawOverlay();
  QPoint origin;

 signals:
  void NewDrawnItem(QPoint pos, QSize size);
  void NewWindowAdded(void);
    
 protected:
  void mousePressEvent(QMouseEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);

 private:
  QRubberBand *rubber_band_;
  bool move_rubberband_;
  QPoint rubberband_offset_;
};

#endif // DRAW_WINDOW_H
