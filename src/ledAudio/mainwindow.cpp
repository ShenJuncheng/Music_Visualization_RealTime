#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "AudioSource.h"
#include "WS2812B.h"
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ledThread = new LEDThread(this);
    connect(ui->modeButton, &QPushButton::clicked, this, &MainWindow::onModeButtonClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);

    // Set up the audio input and data source
    QAudioFormat formatAudio;
    formatAudio.setSampleRate(900);
    formatAudio.setChannelCount(1);
    formatAudio.setSampleSize(8);
    formatAudio.setCodec("audio/pcm");
    formatAudio.setByteOrder(QAudioFormat::LittleEndian);
    formatAudio.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo inputDevices = QAudioDeviceInfo::defaultInputDevice();
    m_audioInput = new QAudioInput(inputDevices, formatAudio, this);
    AudioSource *m_audioSource = new AudioSource(this);
    m_audioSource->open(QIODevice::WriteOnly);
    m_audioInput->start(m_audioSource);

    // Create the chart and series
    auto *chart = new QChart();
    auto *lineSeries = new QLineSeries();

    // Set up the axes
    auto *axisX = new QValueAxis;
    axisX->setRange(0, 3000);

    auto *axisY = new QValueAxis;
    axisY->setRange(-0.3, 0.3);

    chart->addSeries(lineSeries);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    lineSeries->attachAxis(axisX);
    lineSeries->attachAxis(axisY);

    // Set the chart in the QChartView
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    // Connect the data source to the series
    m_audioSource->setSeries(lineSeries);

    //new adding
    // 连接音频源的信号和槽以实时调整LED灯带
//    connect(m_audioSource, &AudioSource::amplitudeChanged, this, &MainWindow::activeThread);
    connect(m_audioSource, &AudioSource::amplitudeChanged, ledThread, &LEDThread::updateLEDStrip);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// new adding
// 一个新的槽函数，根据音频信号振幅调整LED灯带
void MainWindow::activeThread()
{
    ledThread->startThread();
    cout << "LEDs started" << endl;
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

