#include <iostream>
#include <vector>
#include "Average.h"

using namespace std;

int main()
{
    vector<CNCPositionMeasurement> measurements;

    measurements.push_back(
        CNCPositionMeasurement("1", "CNC1", "10:00", "20-01-2026",
                               10, 20, 30, 5, 1, "360"));

    measurements.push_back(
        CNCPositionMeasurement("2", "CNC1", "11:00", "20-01-2026",
                               20, 30, 40, 7, 2, "360"));

    measurements.push_back(
        CNCPositionMeasurement("3", "CNC1", "12:00", "20-01-2026",
                               30, 40, 50, 9, 3, "360"));

    cout << "Gennemsnit x: " << averageValue(measurements, "x") << endl;
    cout << "Gennemsnit y: " << averageValue(measurements, "y") << endl;
    cout << "Gennemsnit z: " << averageValue(measurements, "z") << endl;
    cout << "Gennemsnit roll: " << averageValue(measurements, "roll") << endl;
    cout << "Gennemsnit pitch: " << averageValue(measurements, "pitch") << endl;

    return 0;
}
