

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
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/Ball.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/pitch.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/Ball.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/Ball.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/Free.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/B2.mp4"));
    medialist->addMedia(QUrl::fromLocalFile("/Users/yangchengkun/3-2.mp4"));
    player->setPlaylist(medialist);
    medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    connect(ui->startButton_1,SIGNAL(clicked()), this, SLOT(startVideo_1()));
    connect(ui->startButton_2,SIGNAL(clicked()), this, SLOT(startVideo_2()));
    connect(ui->startButton_3,SIGNAL(clicked()), this, SLOT(startVideo_3()));
    connect(ui->startButton_4,SIGNAL(clicked()), this, SLOT(startVideo_4()));
    connect(ui->startButton_5,SIGNAL(clicked()), this, SLOT(startVideo_5()));
    connect(ui->startButton_6,SIGNAL(clicked()), this, SLOT(startVideo_6()));
    connect(ui->startButton_7,SIGNAL(clicked()), this, SLOT(startVideo_7()));
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

void MainWindow::startVideo_3()
{
    medialist->setCurrentIndex(2);
    videoWidget->show();
    player->play();
}

void MainWindow::startVideo_4()
{
    medialist->setCurrentIndex(3);
    videoWidget->show();
    player->play();
}

void MainWindow::startVideo_5()
{
    medialist->setCurrentIndex(4);
    videoWidget->show();
    player->play();
}


void MainWindow::startVideo_6()
{
    medialist->setCurrentIndex(5);
    videoWidget->show();
    player->play();
}

void MainWindow::startVideo_7()
{
    medialist->setCurrentIndex(6);
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
