#include <iostream>
using namespace std;

int main() {
    char koen;       // 'k' for kvinde, 'm' for mand
    int kalorier;

    cout << "Indtast koen (m/k): ";
    cin >> koen;

    cout << "Indtast dagligt kalorieindtag: ";
    cin >> kalorier;

    int nedre = 0;
    int oevre = 0;

    if (koen == 'k' || koen == 'K') {
        nedre = 1500;
        oevre = 2000;
    }
    else if (koen == 'm' || koen == 'M') {
        nedre = 2000;
        oevre = 2500;
    }

    if (kalorier < nedre) {
        cout << "Du har spist for lidt" << endl;
    }
    else if (kalorier <= oevre) {
        cout << "Du har spist en passende maengde" << endl;
    }
    else {
        cout << "Du har spist for meget" << endl;
    }

    return 0;
}
