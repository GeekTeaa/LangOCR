#ifndef _DECODED_TEXT_H_
#define _DECODED_TEXT_H_

#include <iostream>

// DecodedText : Text that is output by the OcrEngine as non-formatted text. 
//
// Text that is 'Decoded' contains UTF-8 data. 
class DecodedText {
 public:
  DecodedText(std::string InputText);
  ~DecodedText();
  std::string GetCString(void);

 private:
  std::string std_string_;
};

#endif // _DECODED_TEXT_H_
