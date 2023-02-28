#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>
#include <QSpinBox>
#include <QComboBox>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <QProcess>
#include "dialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int red_value,green_value,blue_value;
        QString str;

private slots:
    //客户端槽函数
    void readData();
    void disconnect();
    void CheckConnect();
    void on_connect_clicked();
    void on_open_clicked();
    void on_close_clicked();
    void on_sava_clicked();
    void on_look_clicked();
    void ColorChange();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    QTcpSocket *Ledclient;
    QTimer *checktimer;
    QFile *file;
};

#endif // MAINWINDOW_H
