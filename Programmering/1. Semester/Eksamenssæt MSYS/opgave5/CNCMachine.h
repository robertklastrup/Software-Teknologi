#ifndef CNCMACHINE_H
#define CNCMACHINE_H

#include <string>
#include <vector>
#include "CNCPositionMeasurement.h"

class CNCMachine
{
private:
    std::string name;
    std::string id;
    std::string location;

    // Composition: maskinen "ejer" målingerne
    std::vector<CNCPositionMeasurement> measurements;

public:
    CNCMachine(const std::string& name,
               const std::string& id,
               const std::string& location);

    // Opretter en ny måling og sætter machineId = maskinens id automatisk
    void addMeasurement(const std::string& measurementId,
                        const std::string& time,
                        const std::string& day,
                        float x, float y, float z,
                        float roll, float pitch,
                        const std::string& deg);

    // Beregner gennemsnits-pitch vha. funktionen fra opgave 4
    double averagePitch() const;

    // Gettere (til test i main)
    std::string getName() const;
    std::string getId() const;
    std::string getLocation() const;
    int getMeasurementCount() const;

    // Hjælp til test: udskriv alle målinger
    void printMeasurements() const;
};

#endif
