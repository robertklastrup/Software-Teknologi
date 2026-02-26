#include        <iostream>
using namespace std;


// do while loop = do some block of code
//                 Then Repeat again if condition is true

int main() {

    int number;

    cout << "Indtast et positivt tal: " << '\n';
    cin >> number;


    do{
        cout << "Indtast et positivt tal: " << '\n';
        cin >> number;
    }while(number < 0);

    cout << "nummeret er " << number << '\n';

    return 0;
}

// do while loopet fungerer på samme måde som et almindeligt while loop men med en vigtig forskel.
// I et do while loop bliver koden inden for loopet altid udført mindst én gang,
// før betingelsen kontrolleres. Dette skyldes, at betingelsen evaluer