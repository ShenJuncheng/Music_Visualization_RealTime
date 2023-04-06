

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    videoWidget = new QVideoWidget;
    medialist = new QMediaPlaylist;

    ui->verticalLayout->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);

    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/Desktop/QT/test.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/Desktop/QT/31_1679187302.mp4"));
    player->setPlaylist(medialist);
    medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    connect(ui->startButton_1,SIGNAL(clicked()), this, SLOT(startVideo_1()));
    connect(ui->startButton_2,SIGNAL(clicked()), this, SLOT(startVideo_2()));
    connect(ui->pauseButton,SIGNAL(clicked()), this, SLOT(pauseVideo()));
    connect(ui->resumeButton,SIGNAL(clicked()), this, SLOT(closeVideo()));
    connect(ui->closeButton,SIGNAL(clicked()), this, SLOT(closeVideo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startVideo_1()
{
    medialist->setCurrentIndex(0);
    videoWidget->show();
    player->play();
}

void MainWindow::startVideo_2()
{
    medialist->setCurrentIndex(1);
    videoWidget->show();
    player->play();
}

void MainWindow::pauseVideo()
{
    player->pause();
}

void MainWindow::closeVideo()
{
    player->stop();
}

void MainWindow::resumeVideo()
{
    //player->stop();
}
