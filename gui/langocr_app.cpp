#include <iostream>
#include "langocr_app.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QtWidgets>
// TODO - download https://github.com/robinrowe/libunistd via conanfile.py, for Windows only, to allow this to compile.
#include <unistd.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <cstring>

LangOcrApp::LangOcrApp(QMainWindow *parent):
    QMainWindow(parent) {
  button_         = new QPushButton(QString("Push to draw."), this);
  screen_overlay_ = new ScreenOverlay(this);
  draw_overlay_   = new DrawOverlay(this);
  screen_overlay_->show();

  this->setCentralWidget(button_);

  QObject::connect(button_, SIGNAL(released()), this, SLOT(onButtonReleased())); 
  QObject::connect(draw_overlay_, SIGNAL(NewDrawnItem(QPoint, QSize)),
                   screen_overlay_, SLOT(DrawRect(QPoint, QSize)));
  QObject::connect(draw_overlay_, SIGNAL(NewWindowAdded()),
                   this, SLOT(prepareToCapture()));
}

LangOcrApp::~LangOcrApp() {
  delete button_;
  delete screen_overlay_;
  delete draw_overlay_;
  return; 
}
 

void LangOcrApp::onButtonReleased() {    
  draw_overlay_->show();
  draw_overlay_->move(0,0);
}

void LangOcrApp::prepareToCapture(void) {    
  // Due to reasons I don't understand, we must delay the capture
  // process or we will capture the rubber band used to indicate
  // where the window will be captured.  I think is is because the
  // QT Main event loop hasn't hidden the rubber band yet.

  QTimer::singleShot(100, this, &LangOcrApp::captureWindow);
}

void LangOcrApp::captureWindow() {    
  QScreen *screen = QGuiApplication::primaryScreen();
  QRect rect = screen_overlay_->GetRectangle();
  QPixmap pix;
  pix = screen->grabWindow(0,
                           rect.x(),
                           rect.y(),
                           rect.width(),
                           rect.height());
 
  // Save the image to the local directory. TODO Remove this once the
  // OCR engine is extracted to an OCR Server. 
  if(!pix.save(QString("myPic.jpg"), "jpg", 100))
    std::cout << "Failure to save capture!" << std::endl;
}
