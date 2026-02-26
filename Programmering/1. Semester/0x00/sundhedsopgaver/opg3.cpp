#include <iostream>
using namespace std;

int main() {
    float vægt, vandML, vandL;

    // Brugeren indtaster sin vægt
    cout << "Indtast din vægt i kg: ";
    cin >> vægt;

    // Beregn vandbehov i milliliter og liter
    vandML = vægt * 35;           // 35 ml pr. kg
    vandL = vandML / 1000;        // Konverter til liter

    // Vis resultatet
    cout << "\nDu bør drikke cirka " << vandML << " ml vand dagligt." << endl;
    cout << "Det svarer til cirka " << vandL << " liter vand per dag." << endl;

    return 0;
}
