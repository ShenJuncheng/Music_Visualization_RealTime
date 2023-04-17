#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "AudioSource.h"
#include "SetDevice.h"
#include "WS2812B.h"
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

using namespace std;

// Constructor for the MainWindow class
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ledThread = new LEDThread(this);
    ws2812b = new WS2812B();
    ws2812b->begin();

    // Connect the mode and stop buttons to their respective slots
    connect(ui->modeButton, &QPushButton::clicked, this, &MainWindow::onModeButtonClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);

    // Set up the audio input and data source
    m_audioInput = m_setDevice.initializeAudioInput();
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
    axisY->setRange(-1, 1);

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

    // Connect signals and slots of audio sources to adjust LED strips in real time
    connect(m_audioSource, &AudioSource::amplitudeChanged, ledThread, &LEDThread::setAmplitude);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot for the "START" button click event
void MainWindow::onStopButtonClicked()
{
    if(ledThread->isRunning()){
        ledThread->stopThread();
        ui->stopButton->setText("START");
        ledThread->wait();
        ws2812b->off();
        cout << "LEDs stopped" << endl;
    } else {
        ledThread->startThread();
        ui->stopButton->setText("STOP");
        cout << "LEDs started" << endl;
    }
}

// Slot for the "MODE" button click event
void MainWindow::onModeButtonClicked()
{
    static int currentMode = 1;
    currentMode = (currentMode % 3) + 1; // Update the current mode, looping from 1 to 3
    ledThread->setMode(currentMode); // Set the mode of LEDThread
    cout << "Mode Changed to " << currentMode << endl;
}

