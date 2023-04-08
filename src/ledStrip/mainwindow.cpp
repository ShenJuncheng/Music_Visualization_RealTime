#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ledThread = new LEDThread(this);
    connect(ui->modeButton, &QPushButton::clicked, this, &MainWindow::onModeButtonClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStopButtonClicked()
{
    if(ledThread->isRunning()){
        ledThread->stopThread();
        ui->stopButton->setText("START");
        ledThread->wait();
        cout << "LEDs stopped" << endl;
    } else {
        ledThread->startThread();
        ui->stopButton->setText("STOP");
        cout << "LEDs started" << endl;
    }
}

void MainWindow::onModeButtonClicked()
{
    cout<< "stop led"<< endl;
}

