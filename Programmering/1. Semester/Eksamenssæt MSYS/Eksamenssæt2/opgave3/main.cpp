// main.cpp
#include <iostream>
#include "SpectralMeasurement.h"

int main()
{
    SpectralMeasurement m1("M001", "SP-01", "14:35", "20-01-2026",  // korrekt tid og dato
                           532.0f, 0.82f, "absorbance", 100.0f);    // korrekt unit

    SpectralMeasurement m2("M002", "SP-01", "24:10", "20-01-2026",  // ugyldig tid
                           532.0f, 0.82f, "a.u.", 100.0f);          // korrekt unit

    SpectralMeasurement m3("M003", "SP-02", "09:05", "31-02-2026",  // ugyldig dato
                           650.0f, 1.10f, "forkertUnit", 50.0f);    // ugyldig unit

    std::cout << "m1 valid? " << (m1.isValid() ? "ja" : "nej") << "\n"; // forventet: ja
    std::cout << "m2 valid? " << (m2.isValid() ? "ja" : "nej") << "\n"; // forventet: nej
    std::cout << "m3 valid? " << (m3.isValid() ? "ja" : "nej") << "\n"; // forventet: nej
    

    return 0;
}
