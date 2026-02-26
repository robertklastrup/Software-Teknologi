#include <iostream>
using namespace std;

int main() {
    float vægt, højde;
    int alder;
    float bmrMand, bmrKvinde;

    // Brugeren indtaster nødvendige data
    cout << "Indtast din vægt i kg: ";
    cin >> vægt;

    cout << "Indtast din højde i cm: ";
    cin >> højde;

    cout << "Indtast din alder i år: ";
    cin >> alder;

    // Beregn BMR for mænd og kvinder
    bmrMand = 10 * vægt + 6.25 * højde - 5 * alder + 5;
    bmrKvinde = 10 * vægt + 6.25 * højde - 5 * alder - 161;

    // Vis resultater
    cout << "\n=== Resultater for hvilestofskifte (BMR) ===" << endl;
    cout << "BMR for mænd:   " << bmrMand << " kalorier pr. dag" << endl;
    cout << "BMR for kvinder:" << bmrKvinde << " kalorier pr. dag" << endl;

    return 0;
}
