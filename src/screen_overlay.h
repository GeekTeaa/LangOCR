#ifndef _SCREEN_OVERLAY_H_
#define _SCREEN_OVERLAY_H_

#include <QMainWindow>
#include <QRubberBand>

class ScreenOverlay : public QWidget
{
  Q_OBJECT

  public:
  explicit ScreenOverlay(QWidget *parent = 0);
  ~ScreenOverlay();
  QRect GetRectangle(void);
  //QRect setRectangle(void);

 public slots:
  void DrawRect(QPoint pos, QSize size);
    
 protected:
  // Special Qt Function
  void paintEvent(QPaintEvent *event);

 private:
  QRect rect_;
};

#endif // _SCREEN_OVERLAY_H_
