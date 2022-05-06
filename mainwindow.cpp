#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myvideocapture.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mOpenCV_videocapture = new myVideoCapture(this);
    connect(mOpenCV_videocapture, &myVideoCapture::newPixmapCaptured, this , [&]()
    {
       ui->lbl_frame->setPixmap(mOpenCV_videocapture->pixmap().scaled(500,500));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    mOpenCV_videocapture->terminate();
}


void MainWindow::on_btn_capture_clicked()
{

    mOpenCV_videocapture->start(QThread::HighestPriority);

}

