// SpectralMeasurement.h
#ifndef SPECTRALMEASUREMENT_H
#define SPECTRALMEASUREMENT_H

#include <string>

class SpectralMeasurement
{
private:
    std::string id;
    std::string machineId;
    std::string time;          // "HH:MM"
    std::string day;           // "DD-MM-YYYY"
    float wavelengthNm;
    float intensity;
    std::string unit;          // "a.u." eller "absorbance"
    float integrationTimeMs;

    bool isValidUnit() const;
    bool isValidTime() const;
    bool isValidDay() const;

    static bool isDigits(const std::string& s);
    static bool parseTwoDigits(const std::string& s, int& value);
    static bool parseFourDigits(const std::string& s, int& value);

public:
    SpectralMeasurement(const std::string& id,
                        const std::string& machineId,
                        const std::string& time,
                        const std::string& day,
                        float wavelengthNm,
                        float intensity,
                        const std::string& unit,
                        float integrationTimeMs);

    bool isValid() const;
};

#endif
