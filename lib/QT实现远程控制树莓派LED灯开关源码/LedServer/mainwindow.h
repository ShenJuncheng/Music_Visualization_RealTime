#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wiringPi.h>
#include <QTimer>
#include <softPwm.h>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QMessageBox>
#include <QTime>
#include <QDateTime>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#define kai 27
#define guan 28
#define caidan 29
#define RLed 23
#define GLed 24
#define BLed 25
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
    int key1,key2,key3;
    int key1_flag=0,key2_flag=0,key3_flag=0;
    int red_value,green_value,blue_value,menu_value;
    QFile *keyfile;
    QTextStream *out;

public slots:
    void check();
    void Light();
    void on_listen_clicked();
    void accpectConnect();
    void readData();
    //void history();
    //void choose();
    //void Disconnect();

private slots:
    void on_dislisten_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTcpServer *tcpserver;
    QTimer *timer1;

};

#endif // MAINWINDOW_H
