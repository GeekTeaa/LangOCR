#include "tesseract_ocr_engine.h"
#include <string>
#include <iostream>

TesseractOcrEngine::TesseractOcrEngine(void) {
  tesseract_api = new tesseract::TessBaseAPI();
  if(tesseract_api->Init(NULL,"jpn")) {
    fprintf(stderr, "Failed to initalize tesseract. \n");
    exit(1);
  }
}

// Note: The Destroy() function is called when this object is
// deconstructed.
TesseractOcrEngine::~TesseractOcrEngine(void) {
  this->Destroy();
}

void TesseractOcrEngine::Destroy(void) {
  tesseract_api->End();
  delete tesseract_api; 
}


DecodedText TesseractOcrEngine::DecodeImageIntoText(TextImage image) {
  std::string out;    

  tesseract_api->SetImage(static_cast<Pix*>(&image));
  out = tesseract_api->GetUTF8Text();
  return DecodedText(out);
}
