//
// Created by 23194 on 2023/3/29.
//
#include <gtest/gtest.h>
#include <QtCharts/QXYSeries>
#include "AudioSource.h"

TEST(AudioSourceTest, SetSeries) {
QXYSeries series;
AudioSource source;
source.setSeries(&series);
EXPECT_EQ(&series, source.m_series);
}

TEST(AudioSourceTest, CalculateAmplitude) {
const char data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
qint64 maxSize = 10;
AudioSource source;
double amplitude = source.calculateAmplitude(data, maxSize);
EXPECT_DOUBLE_EQ(0.467091439, amplitude);
}
