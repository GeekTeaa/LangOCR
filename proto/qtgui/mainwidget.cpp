#include <QtWidgets>
#include "mainwidget.h"

// Constructor for main window
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
   button_ = new QPushButton(tr("Push Me!"));
   textBrowser_ = new QTextBrowser();

   QGridLayout *mainLayout = new QGridLayout;
   mainLayout->addWidget(button_,0,0);
   setLayout(mainLayout);
   setWindowTitle(tr("Connecting buttons to processes.."));

   connect(button_, SIGNAL(released()), this, SLOT(onButtonReleased()));
   connect(&process_, SIGNAL(readyReadStandardOutput()), this, SLOT(onCaptureProcessOutput()));
}

// Destructor
MainWidget::~MainWidget()
{
    delete button_;
    delete textBrowser_;
}

// Handler for button click
void MainWidget::onButtonReleased()
{
    rect_ = new QRect(50, 50, 100, 100);
    // clear the text in the textBrowser and start the process
    textBrowser_->clear();
    textBrowser_->append(tr("Running command:"));

    // Set up our process to write to stdout and run our command
    process_.setCurrentWriteChannel(QProcess::StandardOutput); // Set the write channel
    QString program = "ls";
    QStringList args;
    args << "-alh"; // << "$HOME";
    process_.start(program, args); // Start a terminal command

}


// This is called whenever the QProcess::readyReadStandardOutput() signal is received
void MainWidget::onCaptureProcessOutput()
{
    // Determine whether the object that sent the signal was a pointer to a process
    QProcess* process = qobject_cast<QProcess*>(sender());
    // If so, append the output to the textbrowser
    textBrowser_->append(tr("Getting stdout\n"));
    if (process)
    {
        textBrowser_->append(process->readAllStandardOutput());
       
    }
}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    origin = event->pos();
    if (!band_)
        band_ = new QRubberBand(QRubberBand::Rectangle, this);
    band_->setGeometry(QRect(origin, QSize()));
    band_->show();
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    band_->setGeometry(QRect(origin, event->pos()).normalized());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    band_->hide();
    // determine selection, for example using QRect::intersects()
    // and QRect::contains().
}
