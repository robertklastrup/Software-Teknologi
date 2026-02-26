#include <iostream>
#include "CNCPositionMeasurement.h"

using namespace std;

void printMeasurement(const CNCPositionMeasurement& m);

int main()
{
    cout << "=== Test 1: Alle gyldige vaerdier ===\n";
    CNCPositionMeasurement m1("A1", "CNC-7", "13:45", "21-01-2026",
                              10.0f, 20.0f, 30.0f,
                              5.0f, 2.0f,
                              "RAD");
    printMeasurement(m1);

    cout << "\nAfstand fra m1 til (10,20,40): "
         << m1.distanceTo(10.0f, 20.0f, 40.0f) << "\n";

    cout << "\n=== Test 2: Ugyldig time (skal blive default) ===\n";
    CNCPositionMeasurement m2("A2", "CNC-7", "25:10", "21-01-2026",
                              0.0f, 0.0f, 0.0f,
                              0.0f, 0.0f,
                              "360");
    printMeasurement(m2);

    cout << "\n=== Test 3: Ugyldig day (skal blive default) ===\n";
    CNCPositionMeasurement m3("A3", "CNC-7", "09:05", "99-13-1899",
                              1.0f, 2.0f, 3.0f,
                              10.0f, 20.0f,
                              "360");
    printMeasurement(m3);

    cout << "\n=== Test 4: Day 31-02-2026 (skal vaere OK iflg. krav) ===\n";
    CNCPositionMeasurement m4("A4", "CNC-7", "00:00", "31-02-2026",
                              1.0f, 1.0f, 1.0f,
                              0.0f, 0.0f,
                              "RAD");
    printMeasurement(m4);

    cout << "\n=== Test 5: Ugyldig deg (skal blive default) ===\n";
    CNCPositionMeasurement m5("A5", "CNC-7", "23:59", "01-12-2020",
                              9.0f, 9.0f, 9.0f,
                              1.0f, 1.0f,
                              "DEG"); // ugyldig
    printMeasurement(m5);

    return 0;
}


void printMeasurement(const CNCPositionMeasurement& m)
{
    cout << "id: " << m.getId() << endl;
    cout << "machineId: " << m.getMachineId() << endl;
    cout << "time: " << m.getTime() << endl;
    cout << "day: " << m.getDay() << endl;
    cout << "x,y,z: " << m.getX() << ", " << m.getY() << ", " << m.getZ() << endl;
    cout << "roll,pitch: " << m.getRoll() << ", " << m.getPitch() << endl;
    cout << "deg: " << m.getDeg() << endl;
}