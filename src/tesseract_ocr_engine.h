#ifndef  _TESSERACT_OCR_ENGINE_H_
#define _TESSERACT_OCR_ENGINE_H_

#include "ocr_engine.h"

class TesseractOcrEngine : public OcrEngine {

 public :
  TesseractOcrEngine();
  ~TesseractOcrEngine();

 public slots:
  //std::string DecodeImageIntoText(TextImage image) override;
  void DecodeImageIntoText(void) override;
  
 private:
  tesseract::TessBaseAPI *api;
};

#endif //  _TESSERACT_OCR_ENGINE_H_
