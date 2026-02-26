#include "CNCMachine.h"
#include "Average.h"
#include <iostream>

CNCMachine::CNCMachine(const std::string& name,
                       const std::string& id,
                       const std::string& location)
{
    this->name = name;
    this->id = id;
    this->location = location;
}

void CNCMachine::addMeasurement(const std::string& measurementId,
                                const std::string& time,
                                const std::string& day,
                                float x, float y, float z,
                                float roll, float pitch,
                                const std::string& deg)
{
    // Her oprettes målingen inde i maskinen (composition)
    // machineId sættes automatisk til maskinens id
    CNCPositionMeasurement m(measurementId,
                             this->id,   // machineId = maskinens id
                             time,
                             day,
                             x, y, z,
                             roll, pitch,
                             deg);

    measurements.push_back(m);
}

double CNCMachine::averagePitch() const
{
    // Genbrug fra opgave 4: beregn gennemsnit af "pitch"
    return averageValue(measurements, "pitch");
}

std::string CNCMachine::getName() const { return name; }
std::string CNCMachine::getId() const { return id; }
std::string CNCMachine::getLocation() const { return location; }

int CNCMachine::getMeasurementCount() const
{
    return (int)measurements.size();
}

void CNCMachine::printMeasurements() const
{
    for (size_t i = 0; i < measurements.size(); i++)
    {
        std::cout << "Measurement " << i << ":\n";
        std::cout << "  id: " << measurements[i].getId() << "\n";
        std::cout << "  machineId: " << measurements[i].getMachineId() << "\n";
        std::cout << "  time: " << measurements[i].getTime() << "\n";
        std::cout << "  day: " << measurements[i].getDay() << "\n";
        std::cout << "  pitch: " << measurements[i].getPitch() << "\n";
        std::cout << "\n";
    }
}
