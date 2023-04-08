#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LEDThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onModeButtonClicked();
    void onStopButtonClicked();

private:
    Ui::MainWindow *ui;
    LEDThread *ledThread;
};
#endif // MAINWINDOW_H
