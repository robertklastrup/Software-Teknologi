// main.cpp
#include <iostream>
#include "Spectrometer.h"

int main()
{
    Spectrometer sp("LabSpec", "SP-01", "Aalborg", 5);

    sp.createMeasurement("M001", "10:15", "20-01-2026", 500.0f, 0.80f, "a.u.", 100.0f);
    sp.createMeasurement("M002", "11:20", "20-01-2026", 510.0f, 0.90f, "a.u.", 120.0f);
    sp.createMeasurement("M003", "12:05", "20-01-2026", 520.0f, 1.10f, "absorbance", 80.0f);

    std::cout << "Navn: " << sp.getName() << "\n";
    std::cout << "Id: " << sp.getId() << "\n";
    std::cout << "Placering: " << sp.getLocation() << "\n";
    std::cout << "Antal maalinger: " << sp.getCount() << "\n";
    std::cout << "Gns wavelengthNm: " << sp.averageWavelengthNm() << "\n";

    return 0;
}
