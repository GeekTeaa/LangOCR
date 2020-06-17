#ifndef _LANG_OCR_APP_H_
#define _LANG_OCR_APP_H_

#include <QtWidgets>
#include <QPixmap>
#include "screen_overlay.h"
#include "draw_window.h"

class QPushButton;

class LangOcrApp : public QMainWindow
{
  Q_OBJECT
  
 public:
  explicit LangOcrApp(QMainWindow *parent = nullptr);
  ~LangOcrApp();

 signals:
  void captureWindowDone(void);
                     
 private slots:
  void onButtonReleased(void);
  void captureWindow(void);
  void prepareToCapture(void);
  void runTesseract(void);

 private:
  ScreenOverlay *screen_overlay_;
  DrawWindow *draw_window_;   // 
  QPushButton *button_;
};

#endif // _LANG_OCR_APP_H_
