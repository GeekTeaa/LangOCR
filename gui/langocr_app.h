#ifndef _LANG_OCR_APP_H_
#define _LANG_OCR_APP_H_

#include <QtWidgets/QtWidgets>
#include <QtGui/QPixmap>
#include "screen_overlay.h"
#include "draw_overlay.h"
#include "tesseract_ocr_engine.h"

class QPushButton;

class LangOcrApp : public QMainWindow {
  Q_OBJECT
  
 public:
  explicit LangOcrApp(QMainWindow *parent = nullptr);
  ~LangOcrApp();
                     
 private slots:
  void onButtonReleased(void);
  void captureWindow(void);
  void prepareToCapture(void);

 private:
  ScreenOverlay *screen_overlay_;
  DrawOverlay *draw_overlay_;   
  QPushButton *button_;
  OcrEngine *ocr_engine_;
};

#endif // _LANG_OCR_APP_H_
