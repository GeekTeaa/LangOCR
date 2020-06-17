#include <QtWidgets>
#include "langocr_app.h"

int main(int argc, char *argv[])
{
    // Creates an instance of QApplication
    QApplication a(argc, argv);

    // First things first, create of the overlay window. This window
    //   allows the rest of the application to draw boxes on the
    //   screen so it can mark the capture window for the user.

    // Note: The overlay window inherits QMainWindow, meaning there
    // can only be one, and it has to be the highest parent of all the
    // QWidgets.

    LangOcrApp app;
    app.show();
    
    // run the application and return execs() return value/code
    return a.exec();
}
