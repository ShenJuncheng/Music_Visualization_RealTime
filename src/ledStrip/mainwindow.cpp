#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ledThread = new LEDThread(this);
//    connect(ui->modeButton, &QPushButton::clicked, this, &MainWindow::onModeButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onModeButtonClicked()
{
    // 假设您有一个枚举类型，用于表示不同的 LED 模式
    // 更新当前的 LED 模式并通知 LEDThread 切换到新的模式
    cout<< "start led" << endl;
}

