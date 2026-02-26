#include <iostream>
#include "CNCMachine.h"

using namespace std;

int main()
{
    // Opret en maskine
    CNCMachine machine("RobotArm-1", "M-100", "Lab A");

    cout << "Machine:\n";
    cout << "  name: " << machine.getName() << "\n";
    cout << "  id: " << machine.getId() << "\n";
    cout << "  location: " << machine.getLocation() << "\n\n";

    // Tilføj målinger (machineId sættes automatisk til M-100)
    machine.addMeasurement("Meas-1", "10:00", "21-01-2026",
                           10, 20, 30, 5, 1, "360");

    machine.addMeasurement("Meas-2", "11:00", "21-01-2026",
                           20, 30, 40, 6, 2, "360");

    machine.addMeasurement("Meas-3", "12:00", "21-01-2026",
                           30, 40, 50, 7, 3, "RAD");

    cout << "Antal maalinger: " << machine.getMeasurementCount() << "\n\n";

    // Udskriv målinger for at bevise composition + machineId
    cout << "Udskriver alle maalinger:\n";
    machine.printMeasurements();

    // Beregn gennemsnits-pitch vha. opgave 4 funktionen
    cout << "Gennemsnit pitch: " << machine.averagePitch() << "\n";

    return 0;
}
