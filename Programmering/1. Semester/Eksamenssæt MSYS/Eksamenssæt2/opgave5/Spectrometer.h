// Spectrometer.h
#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <string>
#include "SpectralMeasurement.h"

class Spectrometer
{
private:
    std::string name;
    std::string id;
    std::string location;

    // Composition: spektrometeret "ejer" sine målinger
    SpectralMeasurement* measurements;
    int capacity;
    int count;

public:
    Spectrometer(const std::string& name,
                 const std::string& id,
                 const std::string& location,
                 int capacity);

    ~Spectrometer();

    // Opretter en måling og sætter machineId til spektrometerets id
    bool createMeasurement(const std::string& measurementId,
                           const std::string& time,
                           const std::string& day,
                           float wavelengthNm,
                           float intensity,
                           const std::string& unit,
                           float integrationTimeMs);

    float averageWavelengthNm() const;

    int getCount() const;
    std::string getId() const;
    std::string getName() const;
    std::string getLocation() const;
};

#endif
