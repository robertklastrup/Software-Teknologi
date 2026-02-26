#include    <iostream>
#include   <cmath>
using namespace std;

// Dette program er et øveprogram til at bruge hvad vi har lært indtil nu.
//      Vi skriver et program til udregning af hypotenusen i en retvinklet trekant ved hjælp af Pythagoras sætning.



int main() {
    double a;
    double b;
    double c;

    cout << "Skriv længden af side a" << '\n';
    cin >> a;

    cout << "Skriv længden af side b" << '\n';
    cin >> b;

    //a = pow(a, 2);
    //b = pow(b, 2);
    c = sqrt(pow(a, 2) + pow(b, 2));

    cout << "Side c er lig med: " << c << '\n';

    return 0;
    
}