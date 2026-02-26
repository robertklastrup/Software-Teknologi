#include <iostream>
using namespace std;

int main() {
    char koen;       // 'k' for kvinde, 'm' for mand
    double liter;    // vandindtag i liter
    double anbefaling;

    cout << "Indtast koen (m/k): ";
    cin >> koen;

    cout << "Indtast antal liter vand drukket i dag: ";
    cin >> liter;

    if (koen == 'k' || koen == 'K') {
        anbefaling = 2.0;
    } else {
        anbefaling = 2.5;
    }

    if (liter < anbefaling - 0.5) {
        cout << "Du har drukket for lidt" << endl;
    }
    else if (liter <= anbefaling + 0.5) {
        cout << "Du har drukket en passende maengde" << endl;
    }
    else {
        cout << "Du har drukket rigeligt vand" << endl;
    }

    return 0;
}
