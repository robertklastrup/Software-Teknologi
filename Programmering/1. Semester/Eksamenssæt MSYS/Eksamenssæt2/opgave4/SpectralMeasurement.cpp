#include "SpectralMeasurement.h"

bool SpectralMeasurement::isDigits(const std::string& s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

bool SpectralMeasurement::parseTwoDigits(const std::string& s, int& value)
{
    if (s.size() != 2) return false;
    if (!isDigits(s)) return false;
    value = std::stoi(s);
    return true;
}

bool SpectralMeasurement::parseFourDigits(const std::string& s, int& value)
{
    if (s.size() != 4) return false;
    if (!isDigits(s)) return false;
    value = std::stoi(s);
    return true;
}

SpectralMeasurement::SpectralMeasurement(const std::string& id,
                                         const std::string& machineId,
                                         const std::string& time,
                                         const std::string& day,
                                         float wavelengthNm,
                                         float intensity,
                                         const std::string& unit,
                                         float integrationTimeMs)
    : id(id),
      machineId(machineId),
      time(time),
      day(day),
      wavelengthNm(wavelengthNm),
      intensity(intensity),
      unit(unit),
      integrationTimeMs(integrationTimeMs)
{
    if (this->unit != "a.u." && this->unit != "absorbance")
    {
        this->unit = "a.u.";
    }
}

bool SpectralMeasurement::isValidUnit() const
{
    return (unit == "a.u." || unit == "absorbance");
}

bool SpectralMeasurement::isValidTime() const
{
    if (time.size() != 5) return false;
    if (time[2] != ':') return false;

    int hh = 0;
    int mm = 0;
    if (!parseTwoDigits(time.substr(0, 2), hh)) return false;
    if (!parseTwoDigits(time.substr(3, 2), mm)) return false;

    if (hh < 0 || hh > 23) return false;
    if (mm < 0 || mm > 59) return false;

    return true;
}

bool SpectralMeasurement::isValidDay() const
{
    if (day.size() != 10) return false;
    if (day[2] != '-' || day[5] != '-') return false;

    int dd = 0;
    int mm = 0;
    int yyyy = 0;

    if (!parseTwoDigits(day.substr(0, 2), dd)) return false;
    if (!parseTwoDigits(day.substr(3, 2), mm)) return false;
    if (!parseFourDigits(day.substr(6, 4), yyyy)) return false;

    if (dd < 1 || dd > 31) return false;
    if (mm < 1 || mm > 12) return false;
    if (yyyy <= 1900) return false;

    return true;
}

bool SpectralMeasurement::isValid() const
{
    return isValidUnit() && isValidTime() && isValidDay();
}

// Getters
float SpectralMeasurement::getWavelengthNm() const
{
    return wavelengthNm;
}

float SpectralMeasurement::getIntensity() const
{
    return intensity;
}

float SpectralMeasurement::getIntegrationTimeMs() const
{
    return integrationTimeMs;
}
