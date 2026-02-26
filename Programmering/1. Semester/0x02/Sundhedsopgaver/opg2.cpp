#include <iostream>
using namespace std;

int main() {
    int alder;
    double puls;

    cout << "Indtast alder: ";
    cin >> alder;

    cout << "Indtast aktuel puls: ";
    cin >> puls;

    double maksPuls = 220 - alder;

    double procent = puls / maksPuls;

    if (procent < 0.5) {
        cout << "Rolig zone" << endl;
    } 
    else if (procent <= 0.7) {
        cout << "Moderat zone" << endl;
    } 
    else {
        cout << "Hård zone" << endl;
    }

    return 0;
}
