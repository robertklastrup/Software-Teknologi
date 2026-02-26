#include <iostream>
#include <cstdlib>   
#include <ctime>    
using namespace std;

int main() {
    int styrke;
    float våbenskade;
    float kritiskChance;
    float skade;
    bool erKritisk = false;

    cout << "Indtast din styrke: ";
    cin >> styrke;

    cout << "Indtast våbnets basisskade: ";
    cin >> våbenskade;

    cout << "Indtast kritisk chance i procent (f.eks. 25): ";
    cin >> kritiskChance;

    srand(time(0));
    int tilfældigtTal = rand() % 100 + 1; 

    if (tilfældigtTal <= kritiskChance) {
        erKritisk = true;
    }

    skade = våbenskade + (styrke * 0.5);
    if (erKritisk) {
        skade *= 2;  
    }

    cout << "\n=== Skadeberegning ===" << endl;
    if (erKritisk) {
        cout << "Kritisk træf!" << endl;
    } else {
        cout << "Normal træf." << endl;
    }
    cout << "Total skade: " << skade << endl;

    return 0;
}
