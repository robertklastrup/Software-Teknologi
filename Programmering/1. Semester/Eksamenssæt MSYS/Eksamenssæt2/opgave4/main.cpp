#include <iostream>
#include "SpectralMeasurement.h"
#include "Average.h"

int main()
{
    SpectralMeasurement measurements[3] =
    {
        SpectralMeasurement("M001", "SP-01", "10:15", "20-01-2026", 500.0f, 0.80f, "a.u.", 100.0f),
        SpectralMeasurement("M002", "SP-01", "11:20", "20-01-2026", 510.0f, 0.90f, "a.u.", 120.0f),
        SpectralMeasurement("M003", "SP-01", "12:05", "20-01-2026", 520.0f, 1.10f, "absorbance", 80.0f)
    };

    int count = 3;

    std::cout << "Gns wavelengthNm: "
              << averageMeasurements(measurements, count, WAVELENGTH_NM) << "\n";

    std::cout << "Gns intensity: "
              << averageMeasurements(measurements, count, INTENSITY) << "\n";

    std::cout << "Gns integrationTimeMs: "
              << averageMeasurements(measurements, count, INTEGRATION_TIME_MS) << "\n";

    return 0;
}
