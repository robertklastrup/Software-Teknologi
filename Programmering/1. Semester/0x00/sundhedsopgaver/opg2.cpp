#include <iostream>
using namespace std;

int main() {
    int alder;
    int maxPuls;
    float zone1_lower, zone1_upper;
    float zone2_lower, zone2_upper;
    float zone3_lower, zone3_upper;
    float zone4_lower, zone4_upper;
    float zone5_lower, zone5_upper;

    // Brugeren indtaster sin alder
    cout << "Indtast din alder: ";
    cin >> alder;

    // Beregn maksimal puls (formel: 220 - alder)
    maxPuls = 220 - alder;

    // Beregn grænser for træningszoner i procent af maksimal puls
    zone1_lower = maxPuls * 0.50;
    zone1_upper = maxPuls * 0.60;

    zone2_lower = maxPuls * 0.60;
    zone2_upper = maxPuls * 0.70;

    zone3_lower = maxPuls * 0.70;
    zone3_upper = maxPuls * 0.80;

    zone4_lower = maxPuls * 0.80;
    zone4_upper = maxPuls * 0.90;

    zone5_lower = maxPuls * 0.90;
    zone5_upper = maxPuls * 1.00;

    // Udskriv resultaterne
    cout << "\nDin maksimale puls er: " << maxPuls << " bpm\n" << endl;

    cout << "Træningszoner (baseret på maksimal puls):\n";
    cout << "Zone 1 (Meget let):       " << zone1_lower << " - " << zone1_upper << " bpm" << endl;
    cout << "Zone 2 (Let):             " << zone2_lower << " - " << zone2_upper << " bpm" << endl;
    cout << "Zone 3 (Moderat):         " << zone3_lower << " - " << zone3_upper << " bpm" << endl;
    cout << "Zone 4 (Hård):            " << zone4_lower << " - " << zone4_upper << " bpm" << endl;
    cout << "Zone 5 (Maksimal):        " << zone5_lower << " - " << zone5_upper << " bpm" << endl;

    return 0;
}
