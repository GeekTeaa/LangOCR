
#include <iostream>
#include <unistd.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    char *out;
    tesseract::Orientation orientation;
    tesseract::WritingDirection direction;
    tesseract::TextlineOrder order;
    float deskew_angle;
    
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    
    if(api->Init(NULL,"jpn"))
    {
        fprintf(stderr, "Failed to initalize tesseract. \n");
        exit(1);
    }

    // This is using the leptonica library
    Pix *image = pixRead("../../input/page-014.png");
    
    // Configure API 
    api->SetImage(image);
    api->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK_VERT_TEXT);
    api->SetRectangle(0, 0, 1440, 2100);

    tesseract::PageIterator* it =  api->AnalyseLayout();
    it->Orientation(&orientation, &direction, &order, &deskew_angle);
    printf("Orientation: %d;\nWritingDirection: %d\nTextlineOrder: %d\n" \
           "Deskew angle: %.4f\n",
           orientation, direction, order, deskew_angle);

    out = api->GetUTF8Text();
    printf("OCR Output: \n%s", out);
    api->End();
    delete api;
    delete [] out;
    pixDestroy(&image);
    printf("End of script\n");
    exit(EXIT_SUCCESS);
}
