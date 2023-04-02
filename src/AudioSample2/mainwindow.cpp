#include "mainwindow.h"
#include "DataSource.h"
#include "ui_mainwindow.h"
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up the audio input and data source
    QAudioFormat formatAudio;
    formatAudio.setSampleRate(10000);
    formatAudio.setChannelCount(1);
    formatAudio.setSampleSize(8);
    formatAudio.setCodec("audio/pcm");
    formatAudio.setByteOrder(QAudioFormat::LittleEndian);
    formatAudio.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo inputDevices = QAudioDeviceInfo::defaultInputDevice();
    m_audioInput = new QAudioInput(inputDevices, formatAudio, this);

    DataSource *m_dataSource = new DataSource(this);
    m_dataSource->open(QIODevice::WriteOnly);
    m_audioInput->start(m_dataSource);

    // Create the chart and series
    auto *chart = new QChart();
    auto *lineSeries = new QLineSeries();

    // Set up the axes
    auto *axisX = new QValueAxis;
    axisX->setRange(0, 8000);

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
    m_dataSource->setSeries(lineSeries);
}

MainWindow::~MainWindow()
{
    delete ui;
}
