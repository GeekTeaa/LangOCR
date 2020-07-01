#include "tesseract_ocr_engine.h"
#include <string>
#include <iostream>

TesseractOcrEngine::TesseractOcrEngine(void) {
  api = new tesseract::TessBaseAPI();
  if(api->Init(NULL,"jpn")) {
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
  api->End();
  delete api; 
}


DecodedText TesseractOcrEngine::DecodeImageIntoText(TextImage image) {
  std::string out;    

  api->SetImage(static_cast<Pix*>(&image));
  out = api->GetUTF8Text();
  return DecodedText(out);
}
