#ifndef JAPANESE_OCR_WIDGET_H
#define JAPANESE_OCR_WIDGET_H

#include <QtWidgets>
#include <QPixmap>
#include "overlay_window.h"
#include "draw_window.h"


// namespace Ui {
// class JapaneseOcrWidget;
// }

class QPushButton;

class JapaneseOcrApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit JapaneseOcrApp(QMainWindow *parent = nullptr);
    ~JapaneseOcrApp();

signals:
    void captureWindowDone(void);
                     
private slots:
    void onButtonReleased(void);
    void captureWindow(void);
    void prepareToCapture(void);
    void runTesseract(void);

    
private:
    OverlayWindow *overlay_;
    DrawWindow *drawWindow_;
    QPushButton *button_;
};

#endif // JAPANESE_OCR_WIDGET_H
