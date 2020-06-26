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

TesseractOcrEngine::~TesseractOcrEngine(void) {
  api->End();
  delete api; 
}

// std::string TesseractOcrEngine::DecodeImageIntoText(TextImage image) {
void TesseractOcrEngine::DecodeImageIntoText(void) {
  char *out;    
  // This is using the leptonica library
  Pix *image = pixRead("myPic.jpg");

  // Configure API 
  api->SetImage(image);

  out = api->GetUTF8Text();
  std::cout << out << std::endl;
  delete out;
  delete image; 
}
