#ifndef  _TESSERACT_OCR_ENGINE_H_
#define _TESSERACT_OCR_ENGINE_H_

#include "ocr_engine.h"

// TesseractOcrEngine : Using Teseract-Ocr API to decode images into text
//
// Implements the abstract class OcrEngine.
//
// Example:
//  DecodedText my_text;
//  TextImage   my_image = GetTextImage();
//  OcrEngine  *my_engine = new TesseractOcrEngine();
//
//  my_text = my_engine->DecodeImageIntoText(my_image);

class TesseractOcrEngine : public OcrEngine {

 public :
  TesseractOcrEngine();
  ~TesseractOcrEngine();
  DecodedText DecodeImageIntoText(TextImage image) override;

 protected :
  void Destroy(void) override;
  
 private:
  tesseract::TessBaseAPI *api;
};

#endif //  _TESSERACT_OCR_ENGINE_H_
