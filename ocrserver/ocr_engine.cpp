#include "ocr_engine.h"

// OcrEngine is a purely abstract module. General use will be as
// follows.
//
// OcrEngine *o = new DerivedOcrEngine();
// ...
// delete o;
//
// Inorder to call the proper destructor from the derived class, the
// derived class must re-implement Destroy. This, supported with the
// logic below, will allow the user to delete the base class instance
// with the derived class's destructor.
OcrEngine::~OcrEngine() {
  this->Destroy(); 
}

void OcrEngine::Destroy(void) {
  return;
}
