#include "widget.h"
#include "ui_widget.h"
#include <QPen>
#include <QPainter>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    camera=new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);
    camera->setViewfinder(viewfinder);
    camera->start();


    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);


    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::captureImage()
{
    imageCapture->capture();
}

void Widget::displayImage(int , QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
}

void Widget::saveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), "../", tr("Images (*.png *.xpm *.jpg)"));

    if(fileName.isEmpty()) {
        return;
    }
    const QPixmap* pixmap=ui->ImageCapture->pixmap();
    if(pixmap) {
        pixmap->save(fileName);
    }
}

