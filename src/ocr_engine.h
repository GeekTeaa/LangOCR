
#ifndef _OCR_ENGINE_H_
#define _OCR_ENGINE_H_

#include <QWidget>
#include <tesseract/baseapi.h>
#include <iostream>
#include <string>
#include "text_image.h"

class OcrEngine : public QObject {
  Q_OBJECT
  // virtual std::string DecodeImageIntoText(TextImage image);
 public slots:
  virtual void DecodeImageIntoText(void) = 0;
};

#endif // _OCR_ENGINE_H_

  
