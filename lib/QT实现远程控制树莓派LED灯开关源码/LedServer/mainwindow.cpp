#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetup();
    pinMode(kai,INPUT);
    pinMode(guan,INPUT);
    pinMode(caidan,INPUT);
    pullUpDnControl(kai,PUD_UP);
    pullUpDnControl(guan,PUD_UP);
    pullUpDnControl(caidan,PUD_UP);
    pinMode(RLed,OUTPUT);
    softPwmCreate(RLed,0,100);
    pinMode(GLed,OUTPUT);
    softPwmCreate(GLed,0,100);
    pinMode(BLed,OUTPUT);
    softPwmCreate(BLed,0,100);
    red_value=ui->lineEdit->text().toInt();
    green_value=ui->lineEdit_2->text().toInt();
    blue_value=ui->lineEdit_3->text().toInt();
    menu_value=ui->lineEdit_4->text().toInt();
    //timer1=new QTimer(this);
    tcpserver=new QTcpServer();
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(accpectConnect()));
    connect(tcpserver,SIGNAL(Connection()),this,SLOT(Light()));

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));
    timer->start(100);
    //QFile keyfile("./history.txt");
    //QTextStream out(&keyfile);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check()
{
    key1=digitalRead(kai);
    key2=digitalRead(guan);
    key3=digitalRead(caidan);
    if(key1==0 && key1_flag==1){
       if(menu_value==0){
           red_value=1;
           digitalWrite(RLed,HIGH);
           softPwmWrite(RLed,100*red_value);
           ui->lineEdit_5->setText(QString::number(100*red_value));
           //ui->lineEdit_6->setText("0");
           //ui->lineEdit_7->setText("0");
           ui->lineEdit_8->setText("red");
        }
       if(menu_value==1){
           green_value=1;
           digitalWrite(GLed,HIGH);
           softPwmWrite(GLed,100*green_value);
           ui->lineEdit_6->setText(QString::number(100*green_value));
           //ui->lineEdit_5->setText("0");
           //ui->lineEdit_7->setText("0");
           ui->lineEdit_8->setText("green");
       }
       if(menu_value==2){
           blue_value=1;
           digitalWrite(BLed,HIGH);
           softPwmWrite(BLed,100*blue_value);
           ui->lineEdit_7->setText(QString::number(100*blue_value));
           //ui->lineEdit_6->setText("0");
           //ui->lineEdit_5->setText("0");
           ui->lineEdit_8->setText("blue");
    }
    }
    if(key2==0 && key2_flag==1){
        if(menu_value==0){
            red_value=0;
            digitalWrite(RLed,LOW);
            softPwmWrite(RLed,100*red_value);
            ui->lineEdit_5->setText("0");
            ui->lineEdit_8->setText("");
         }
        if(menu_value==1){
            green_value=0;
            digitalWrite(GLed,LOW);
            softPwmWrite(GLed,100*green_value);
            //ui->lineEdit_5->setText("0");
            ui->lineEdit_6->setText("0");
            //ui->lineEdit_7->setText("0");
            ui->lineEdit_8->setText("");
        }
        if(menu_value==2){
            blue_value=0;
            digitalWrite(BLed,LOW);
            softPwmWrite(BLed,100*blue_value);
            //ui->lineEdit_5->setText("0");
            //ui->lineEdit_6->setText("0");
            ui->lineEdit_7->setText("0");
            ui->lineEdit_8->setText("");
        }
    }
    if(key3==0 && key3_flag==1){
        menu_value=(menu_value+1)%3;
    }
    key1_flag=key1;
    key2_flag=key2;
    key3_flag=key3;
    ui->lineEdit->setText(QString::number(red_value));
    ui->lineEdit_2->setText(QString::number(green_value));
    ui->lineEdit_3->setText(QString::number(blue_value));
    ui->lineEdit_4->setText(QString::number(menu_value));
}


void MainWindow::on_listen_clicked()
{
    if(ui->listen->text()==tr("listen")){
    tcpserver->listen(QHostAddress::Any,12345);
    QMessageBox::about(this,"cue","listen successful");
    //ui->listen->setText("dislisten");
    }
}
void MainWindow::accpectConnect()
{
    socket=this->tcpserver->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(socket,SIGNAL(disconnected()),socket,SLOT(deleteLater()));

}
void MainWindow::readData()
{
    QString datas=socket->readAll();
    ui->lineEdit_5->setText(datas);
    QStringList list=datas.split(",");
    QString r_pwm=list[0];
    QString g_pwm=list[1];
    QString b_pwm=list[2];
    QString color=list[3];
    ui->lineEdit_5->setText(r_pwm);
    ui->lineEdit_6->setText(g_pwm);
    ui->lineEdit_7->setText(b_pwm);
    ui->lineEdit_8->setText(color);
    Light();

}
void MainWindow::Light()
{
    if(ui->lineEdit_8->text()==tr("red")){
        digitalWrite(RLed,HIGH);
        softPwmWrite(RLed,ui->lineEdit_5->text().toInt());
        red_value=1;
        ui->lineEdit->setText(QString::number(red_value));
    }else if(ui->lineEdit_8->text()==tr("green")){
        digitalWrite(GLed,HIGH);
        softPwmWrite(GLed,ui->lineEdit_6->text().toInt());
        green_value=1;
        ui->lineEdit_2->setText(QString::number(green_value));
    }else if(ui->lineEdit_8->text()==tr("blue")){
        digitalWrite(BLed,HIGH);
        softPwmWrite(BLed,ui->lineEdit_7->text().toInt());
        blue_value=1;
        ui->lineEdit_3->setText(QString::number(blue_value));
    }else if(ui->lineEdit_8->text()==tr("")){
        digitalWrite(RLed,LOW);
        digitalWrite(GLed,LOW);
        digitalWrite(BLed,LOW);
        softPwmWrite(RLed,0);
        softPwmWrite(GLed,0);
        softPwmWrite(BLed,0);
        red_value=0;
        green_value=0;
        blue_value=0;
        ui->lineEdit->setText(QString::number(red_value));
        ui->lineEdit_2->setText(QString::number(green_value));
        ui->lineEdit_3->setText(QString::number(blue_value));

    }
    this->socket->write(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toLatin1()
                        +"\r\n");
    this->socket->write("RedLed state:"+ui->lineEdit->text().toLatin1()+"\r\n"
                        + "GreenLed state:"+ui->lineEdit_2->text().toLatin1()+"\r\n"
                        +"BlueLed state:"+ui->lineEdit_3->text().toLatin1());
}

void MainWindow::on_dislisten_clicked()
{
    socket->disconnectFromHost();
     socket->close();
}
