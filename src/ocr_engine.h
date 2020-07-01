
#ifndef _OCR_ENGINE_H_
#define _OCR_ENGINE_H_

#include <tesseract/baseapi.h>
#include <iostream>
#include <string>
#include "text_image.h"
#include "decoded_text.h"

// OcrEngine : Converts an image of text into UTF-8
//
// Purely Abstract Class
//
// Hides the OCR implementation behind a class interface. The
// implementation of the OcrEngine is expected to change radically at
// a later point.
//
// Example
// OcrEngine *o = new DerivedOcrEngine();
// ...
// delete o;
//
// Because of this 
class OcrEngine {
 public:
  virtual ~OcrEngine(void);
  virtual DecodedText DecodeImageIntoText(TextImage image) = 0;

 protected:
  virtual void Destroy(void);
};

#endif // _OCR_ENGINE_H_

  
