// Spectrometer.cpp
#include "Spectrometer.h"
#include "Average.h"

Spectrometer::Spectrometer(const std::string& name,
                           const std::string& id,
                           const std::string& location,
                           int capacity)
    : name(name),
      id(id),
      location(location),
      measurements(nullptr),
      capacity(capacity),
      count(0)
{
    if (this->capacity < 1)
    {
        this->capacity = 1;
    }

    measurements = new SpectralMeasurement[this->capacity];
}

Spectrometer::~Spectrometer()
{
    delete[] measurements;
}

bool Spectrometer::createMeasurement(const std::string& measurementId,
                                     const std::string& time,
                                     const std::string& day,
                                     float wavelengthNm,
                                     float intensity,
                                     const std::string& unit,
                                     float integrationTimeMs)
{
    if (count >= capacity)
    {
        return false; // ikke plads
    }

    // KRAV: machineId skal sættes til spektrometerets id
    measurements[count] = SpectralMeasurement(measurementId,
                                              id,
                                              time,
                                              day,
                                              wavelengthNm,
                                              intensity,
                                              unit,
                                              integrationTimeMs);
    count++;
    return true;
}

float Spectrometer::averageWavelengthNm() const
{
    return averageMeasurements(measurements, count, WAVELENGTH_NM);
}

int Spectrometer::getCount() const
{
    return count;
}

std::string Spectrometer::getId() const
{
    return id;
}

std::string Spectrometer::getName() const
{
    return name;
}

std::string Spectrometer::getLocation() const
{
    return location;
}
