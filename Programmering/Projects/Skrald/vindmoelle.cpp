#include <iostream>
#include <cmath>

const double PI = 3.141592653589793;

// Konstant info for Vestas V236-15.0 MW
const double ROTOR_RADIUS = 118;       // meter (236 / 2)
const double RPM = 7;                  // omdrejninger per minut

// Funktion til at beregne tiphastighed
double calculateTipSpeed(double radius, double rpm) {
    // Tip speed = 2 * pi * r * (rpm / 60)
    return 2 * PI * radius * (rpm / 60);
}


int main() {
    double windSpeed;

    std::cout << "Indtast vindhastighed (m/s): ";
    std::cin >> windSpeed;

    double tipSpeed = calculateTipSpeed(ROTOR_RADIUS, RPM);

    std::cout << "\n=== Beregning af tiphastighed ===" << std::endl;
    std::cout << "Vindhastighed: " << windSpeed << " m/s" << std::endl;
    std::cout << "Tiphastighed (vingespids): " << tipSpeed << " m/s" << std::endl;

    // Tip Speed Ratio (TSR) = Tip Speed / Wind Speed
    if (windSpeed > 0) {
        double tsr = tipSpeed / windSpeed;
        std::cout << "Tip Speed Ratio (TSR): " << tsr << std::endl;
    }

    return 0;
}
