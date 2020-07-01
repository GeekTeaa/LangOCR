#include "decoded_text.h"

DecodedText::DecodedText(std::string InputText) {
  this->std_string_ = InputText;
}

DecodedText::~DecodedText() {
  return;
}

std::string DecodedText::GetCString(void) {
  return std_string_;
}


