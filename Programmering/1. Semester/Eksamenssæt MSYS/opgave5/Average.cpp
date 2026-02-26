#include "Average.h"

double averageValue(const std::vector<CNCPositionMeasurement>& measurements,
                    const std::string& valueType)
{
    // Hvis der ikke er nogen målinger
    if (measurements.size() == 0)
        return 0.0;

    double sum = 0.0;

    for (size_t i = 0; i < measurements.size(); i++)
    {
        if (valueType == "x")
            sum += measurements[i].getX();
        else if (valueType == "y")
            sum += measurements[i].getY();
        else if (valueType == "z")
            sum += measurements[i].getZ();
        else if (valueType == "roll")
            sum += measurements[i].getRoll();
        else if (valueType == "pitch")
            sum += measurements[i].getPitch();
        else
            return 0.0; // ukendt værdi
    }

    return sum / measurements.size();
}
