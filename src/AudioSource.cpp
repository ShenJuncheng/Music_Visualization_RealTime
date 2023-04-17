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

// Constructor for the AudioSource class
AudioSource::AudioSource(QObject *parent) :
    QIODevice(parent)
{
    // Register the QAbstractSeries and QAbstractAxis metatypes
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();
}

qint64 AudioSource::readData(char *data, qint64 maxSize)
{
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
}

/*!
 * Writes audio data to the QXYSeries for visualization
 * @param *data - pointer to the audio data buffer
 * @param maxSize - the size of the audio data buffer
 * @return qint64 - the number of bytes written
 */
qint64 AudioSource::writeData(const char *data, qint64 maxSize)
{
    if (m_series)
    {
        qint64 range = 3000;
        QVector<QPointF> oldPoints = m_series->pointsVector();
        QVector<QPointF> points;
        int resolution = 1;

        if (oldPoints.count() < range) {
            points = m_series->pointsVector();
        } else {
            for (int i = maxSize / resolution; i < oldPoints.count(); i++)
                points.append(QPointF(i - maxSize / resolution, oldPoints.at(i).y()));
        }

        qint64 size = points.count();
        for (int k = 0; k < maxSize / resolution; k++)
            points.append(QPointF(k + size, ((quint8)data[resolution * k] - 128) / 128.0));

        // Calculate amplitude
        double amplitude = calculateAmplitude(data, maxSize);
        // Send the signal of amplitude changed
        emit amplitudeChanged(amplitude);

        m_series->replace(points);
    }

    return maxSize;
}

/*!
 * Sets the QXYSeries to be used for displaying the audio data
 * @param *series - pointer to the QXYSeries object
 */
void AudioSource::setSeries(QAbstractSeries *series)
{
    m_series = static_cast<QXYSeries *>(series);
}

/*!
 * Calculates the normalized amplitude of the audio data
 * @param *data - pointer to the audio data buffer
 * @param maxSize - the size of the audio data buffer
 * @return double - the normalized amplitude
 */
double AudioSource::calculateAmplitude(const char *data, qint64 maxSize)
{
    double sum = 0.0;
    const double max_amplitude = 255.0;

    for (qint64 i = 0; i < maxSize; i++) {
        // Convert the sample data of char type directly to double type
        double sample = static_cast<double>(static_cast<int8_t>(data[i]));

        sum += sample * sample;
    }
    double energy = sum / maxSize;
    double amplitude = sqrt(energy);

    // Normalizes the amplitude to the 0 to 1 range
    double normalized_amplitude = amplitude / max_amplitude;
    return abs(normalized_amplitude);
}
