#ifndef _TEXT_IMAGE_H_
#define _TEXT_IMAGE_H_

#include <leptonica/allheaders.h>

// This program uses Qt (QPixmap) for screen captures, and leptonica
//   (Pix) for the image class. Because of this translation of types
//   between APIs, the image type will be abstracted behind TextImage.
class TextImage : public Pix {};

#endif // _TEXT_IMAGE_H_
