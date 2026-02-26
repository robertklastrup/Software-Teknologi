#include    <iostream>
using namespace std;


int main() {
    
    double temp;
    char unit;

    cout << "*********************Temperature Conversion*********************" << '\n';
    cout << "*******************************************************************" << '\n';

    cout << "F = Fahrenheit" << '\n';
    cout << "C = Celsius" << '\n';
    cout << "Hvilken enhed vil du konvertere fra? (F/C): ";
    cin >> unit;

    if(unit == 'F' || unit == 'f') {
        cout << " Indtast temperaturen i Celsius: ";
        cin >> temp;

        temp = (1.8 * temp) + 32;
        cout << "Temperaturen i Fahrenheit er: " << temp << "F" << '\n';

    }
    else if (unit == 'C' || unit == 'c') {
        cout << " Indtast temperaturen i Fahrenheit: ";
        cin >> temp;

        temp = (temp - 32) / 1.8;
        cout << "Temperaturen i Celsius er: " << temp << "C" << '\n';
    }
    else {
        cout << "Ugyldig enhed! Venligst vælg enten F eller C." << '\n';
    }

    return 0;
}