#ifndef AVERAGE_H
#define AVERAGE_H

#include "SpectralMeasurement.h"

enum AverageValue
{
    WAVELENGTH_NM,
    INTENSITY,
    INTEGRATION_TIME_MS
};

float averageMeasurements(const SpectralMeasurement measurements[], int count, AverageValue valueToAverage);

#endif
