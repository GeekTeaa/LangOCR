#include "decoded_text.h"

DecodedText::DecodedText(std::string input_text) {
  this->std_string_ = input_text;
}

DecodedText::~DecodedText() {
  return;
}

std::string DecodedText::GetCString(void) {
  return std_string_;
}


