#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Ledclient=new QTcpSocket(this);//实例化tcpclient
        this->Ledclient->abort();//取消原有连接
        connect(this->Ledclient,SIGNAL(readyRead()),this,SLOT(readData()));
        connect(this->Ledclient,SIGNAL(disconnected),this,SLOT(disconnect()));
        ui->open->setEnabled(false);
        ui->close->setEnabled(false);
        ui->sava->setEnabled(false);
        ui->connect->setStyleSheet("background-color: rgb(255,0,0);");
        int nMin=0;
        int nMax=100;
        int nSingleStep=10;
        ui->spinBox_red->setMinimum(nMin);  // 最小值
        ui->spinBox_red->setMaximum(nMax);  // 最大值
        ui->spinBox_red->setSingleStep(nSingleStep);
        ui->spinBox_green->setMinimum(nMin);  // 最小值
        ui->spinBox_green->setMaximum(nMax);  // 最大值
        ui->spinBox_green->setSingleStep(nSingleStep);
        ui->spinBox_blue->setMinimum(nMin);  // 最小值
        ui->spinBox_blue->setMaximum(nMax);  // 最大值
        ui->spinBox_blue->setSingleStep(nSingleStep);
        ui->comboBox->addItem("color");
        ui->comboBox->addItem("red");
        ui->comboBox->addItem("green");
        ui->comboBox->addItem("blue");
        connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(ColorChange()));
        checktimer=new QTimer(this);
        connect(checktimer,SIGNAL(timeout()),this,SLOT(CheckConnect()));
        checktimer->start(10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ColorChange()
{
    if(ui->comboBox->currentText()==tr("red")){
        ui->open->setStyleSheet("background-color:rgb(255,0,0)");
    }
    if(ui->comboBox->currentText()==tr("green")){
        ui->open->setStyleSheet("background-color:rgb(0,255,0)");
    }
    if(ui->comboBox->currentText()==tr("blue")){
        ui->open->setStyleSheet("background-color:rgb(0,0,255)");
    }
}

void MainWindow::on_connect_clicked()
{
    if(ui->connect->text()==QString("connect")){

        Ledclient->connectToHost("192.168.43.250",12345,QTcpSocket::ReadWrite);
        if(!Ledclient->waitForConnected(30000)){
            QMessageBox::about(this,"cue","connect failer");
        }

            QMessageBox::about(this,"cue","connect successful");
            ui->connect->setText("disconnect");
            ui->open->setEnabled(true);
            ui->close->setEnabled(true);
            ui->sava->setEnabled(true);
    }else{
        Ledclient->disconnectFromHost();
        ui->connect->setText("connect");
        ui->open->setEnabled(false);
        ui->close->setEnabled(false);
        ui->sava->setEnabled(true);
    }


}

void MainWindow::on_open_clicked()
{
    red_value=ui->spinBox_red->value();
    green_value=ui->spinBox_green->value();
    blue_value=ui->spinBox_blue->value();
    str=ui->comboBox->currentText();
    Ledclient->write(QString::number(red_value).toLatin1()+","
                    +QString::number(green_value).toLatin1()+","
                    +QString::number(blue_value).toLatin1()+","
                     +str.toLatin1());
    Ledclient->flush();
}

void MainWindow::on_close_clicked()
{
    Ledclient->write(QString::number(0).toLatin1()+","
                    +QString::number(0).toLatin1()+","
                    +QString::number(0).toLatin1()+","
                     +"");
    Ledclient->flush();
    ui->spinBox_red->setValue(0);
    ui->spinBox_green->setValue(0);
    ui->spinBox_blue->setValue(0);
    ui->comboBox->setCurrentIndex(0);
}
void MainWindow::disconnect()
{
    ui->connect->setText("connect");
    ui->open->setEnabled(false);
    ui->close->setEnabled(false);
}
void MainWindow::readData()
{
    QString datas=Ledclient->readAll();
    ui->textEdit->append(datas);

}
void MainWindow::CheckConnect()
{

    qint64 x=Ledclient->write("");
    if(x==-1){
        QMessageBox::about(this,"","server disconnect!");
        Ledclient->disconnectFromHost();
        Ledclient->close();
        if(ui->connect->text()==tr("disconnect")){
            ui->connect->setText("connect");
        }
        ui->open->setEnabled(false);
        ui->close->setEnabled(false);
        ui->sava->setEnabled(false);
    }
}

void MainWindow::on_sava_clicked()
{
    QFile file("./history.txt");
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::information(this,"ERROR","please select file");
        return;
    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();
    file.close();
}

void MainWindow::on_look_clicked()
{

    QString filename=QFileDialog::getOpenFileName(this,tr("")
                                         ,"",tr(""));
    if(!filename.isNull()){
        QFile file(filename);
        if(!file.open(QFile::ReadOnly|QFile::Text))
        {
            QMessageBox::information(this,tr("Error"),"Please select file");
            return;
        }
        QTextStream in(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        dialog=new Dialog(this);
        dialog->setModal(false);
        dialog->ui->textEdit->setPlainText(in.readAll());
        QApplication::restoreOverrideCursor();
        dialog->show();

    }
}
