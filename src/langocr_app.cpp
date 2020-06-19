#include <iostream>
#include "langocr_app.h"
#include <QPushButton>
#include <QtWidgets>
#include <unistd.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <cstring>

LangOcrApp::LangOcrApp(QMainWindow *parent):
    QMainWindow(parent)
{
  button_         = new QPushButton(QString("Push to draw."), this);
  screen_overlay_ = new ScreenOverlay(this);
  draw_overlay_   = new DrawOverlay(this);
  screen_overlay_->show();

  this->setCentralWidget(button_);

  QObject::connect(button_, SIGNAL(released()), this, SLOT(onButtonReleased())); 
  QObject::connect(draw_overlay_, SIGNAL(newDrawnItem(QPoint, QSize)),
                   screen_overlay_, SLOT(DrawRect(QPoint, QSize)));
  QObject::connect(draw_overlay_, SIGNAL(newWindowAdded()),
                   this, SLOT(prepareToCapture()));
  QObject::connect(this, SIGNAL(captureWindowDone()),
                   this, SLOT(runTesseract()));
}

LangOcrApp::~LangOcrApp()
{
  delete button_;
  delete screen_overlay_;
  delete draw_overlay_;
  return; 
}
 

void LangOcrApp::onButtonReleased()
{
  draw_overlay_->show();
  draw_overlay_->move(0,0);
}

void LangOcrApp::prepareToCapture(void)
{
  // Due to reasons I don't understand, we must delay the capture
  // process or we will capture the rubber band used to indicate
  // where the window will be captured.  I think is is because the
  // QT Main event loop hasn't hidden the rubber band yet.

  QTimer::singleShot(100, this, &LangOcrApp::captureWindow);
}

void LangOcrApp::captureWindow()
{ 
  //WId winId = overlay_->winId();
  QScreen *screen = QGuiApplication::primaryScreen();
  QRect rect = screen_overlay_->GetRectangle();
  QPixmap pix;
  pix = screen->grabWindow(0,
                           rect.x(),
                           rect.y(),
                           rect.width(),
                           rect.height());
 
  // Save the image to the local directory. 
  if(!pix.save(QString("myPic.jpg"), "jpg", 100))
    std::cout << "Failure to save capture!" << std::endl;

  emit captureWindowDone();
}

void LangOcrApp::runTesseract(void)
{
  char *out;
  tesseract::Orientation orientation;
  tesseract::WritingDirection direction;
  tesseract::TextlineOrder order;
  float deskew_angle;
    
  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    
  if(api->Init(NULL,"jpn"))
  {
    fprintf(stderr, "Failed to initalize tesseract. \n");
    exit(1);
  }

  // This is using the leptonica library
  Pix *image = pixRead("myPic.jpg");
    
  // Configure API 
  api->SetImage(image);
  //api->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK_VERT_TEXT);

  tesseract::PageIterator* it =  api->AnalyseLayout();
  //it->Orientation(&orientation, &direction, &order, &deskew_angle);
  //printf("Orientation: %d;\nWritingDirection: %d\nTextlineOrder: %d\n" 
  //       "Deskew angle: %.4f\n",
  //       orientation, direction, order, deskew_angle);

  printf("Got here!\n");
  out = api->GetUTF8Text();
  printf("Also got here!\n");
  printf("OCR Output: \n%s", out);
  api->End();
  delete api;
  delete [] out;
  pixDestroy(&image);
}
