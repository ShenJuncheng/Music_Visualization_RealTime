#include "AudioSource.h"
#include <iostream>
#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include <QtQuick/QQuickItem>
#include <QtCore/QDebug>
#include <QtCore/QtMath>
#include <QTime>

using namespace std;
QT_CHARTS_USE_NAMESPACE

Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)

AudioSource::AudioSource( QObject *parent) :
    QIODevice(parent)
{
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();
}


qint64 AudioSource::readData(char * data, qint64 maxSize)
{
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
}


qint64 AudioSource::writeData(const char * data, qint64 maxSize)
{
    if(m_series)
    {
        qint64 range = 3000;
        QVector<QPointF> oldPoints = m_series->pointsVector();
        QVector<QPointF> points;
        int resolution = 4;

        if (oldPoints.count() < range) {
            points = m_series->pointsVector();
        } else {
            for (int i = maxSize/resolution; i < oldPoints.count(); i++)
                points.append(QPointF(i - maxSize/resolution, oldPoints.at(i).y()));
        }

        qint64 size = points.count();
        for (int k = 0; k < maxSize/resolution; k++)
            points.append(QPointF(k + size, ((quint8)data[resolution * k] - 128)/128.0));

        // new adding
        // calculate Amplitude
        double amplitude = calculateAmplitude(data, maxSize);
        // send the signal of amplitude changed
        emit amplitudeChanged(amplitude);

        m_series->replace(points);
    }

    return maxSize;
}


void AudioSource::setSeries(QAbstractSeries *series)
{
    m_series = static_cast<QXYSeries *>(series);
}

double AudioSource::calculateAmplitude(const char *data, qint64 maxSize) {
//    cout << maxSize << endl;
    double sum = 0.0;
    for (qint64 i = 0; i < maxSize; i++) {
        sum += data[i];
    }
    double amplitude = sum / maxSize;
    return amplitude;
}


