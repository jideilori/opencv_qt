#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class myVideoCapture;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_capture_clicked();

private:
    Ui::MainWindow *ui;
    myVideoCapture *mOpenCV_videocapture;
};
#endif // MAINWINDOW_H
