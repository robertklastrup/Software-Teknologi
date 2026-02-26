#include "Average.h"

float averageMeasurements(const SpectralMeasurement measurements[], int count, AverageValue valueToAverage)
{
    if (count <= 0)
    {
        return 0.0f;
    }

    float sum = 0.0f;

    for (int i = 0; i < count; i++)
    {
        if (valueToAverage == WAVELENGTH_NM)
        {
            sum += measurements[i].getWavelengthNm();
        }
        else if (valueToAverage == INTENSITY)
        {
            sum += measurements[i].getIntensity();
        }
        else if (valueToAverage == INTEGRATION_TIME_MS)
        {
            sum += measurements[i].getIntegrationTimeMs();
        }
    }

    return sum / count;
}
