#include <iostream>
using namespace std;

int main() {
    int liv;

    cout << "Indtast spillerens livspoint: ";
    cin >> liv;

    if (liv > 70) {
        cout << "Din karakter er i topform" << endl;
    }
    else if (liv >= 30) {  // automatisk Liv ≤ 70, fordi første if ikke passede
        cout << "Din karakter er saaret" << endl;
    }
    else {
        cout << "Din karakter er i kritisk tilstand" << endl;
    }

    return 0;
}
