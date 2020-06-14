

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QProcess>
#include <QRubberBand>

class QPushButton;
class QTextBrowser;

// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0); //Constructor
    ~MainWidget(); // Destructor

//public events:
    QPoint origin;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    
private slots:
    void onButtonReleased(); // Handler for button presses
    void onCaptureProcessOutput(); // Handler for Process output

private:
   QPushButton* button_;
   QTextBrowser* textBrowser_;
   QProcess process_;   // This is the process the button will fire off
   QRubberBand* band_;
   QRect* rect_;
};

#endif // MAINWIDGET_H

