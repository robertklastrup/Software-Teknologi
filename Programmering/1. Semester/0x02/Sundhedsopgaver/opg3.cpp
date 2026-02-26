#include <iostream>
using namespace std;

int main() {
    int alder;
    char koen;     // m for mand, k for kvinde (selvom det ikke bruges i logikken)
    double timer;

    cout << "Indtast alder: ";
    cin >> alder;

    cout << "Indtast koen (m/k): ";
    cin >> koen;

    cout << "Indtast antal timer soevn i nat: ";
    cin >> timer;

    double minimum = 0;

    if (alder < 18) {
        minimum = 8;
    }
    else if (alder <= 64) {
        minimum = 7;
    }
    else {
        minimum = 6;
    }

    if (timer >= minimum) {
        cout << "nok soevn" << endl;
    }
    else {
        cout << "for lidt soevn" << endl;
    }

    return 0;
}
