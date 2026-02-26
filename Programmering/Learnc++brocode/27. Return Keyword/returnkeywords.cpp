#include    <iostream>
using namespace std;



// Return keyword vil returnere en værdi fra en funktion til det sted hvor funktionen blev kaldt.

double square(double length);
double cube (double length);

int main() {

    double length;

    cout << "Skriv længden af et kvadrat: ";
    cin >> length;
    
    double area = square(length);
    double volume = cube(length);

    cout << "Arealet af kvadratet er: " << area << " cm^2" << '\n';
    cout << "Volumen af kuben er: " << volume << " cm^3" << '\n';

    return 0;
}



// Hvor vidt vi skrivet int, void, double osv. foran funktionsnavnet, angiver det hvilken type værdi funktionen vil returnere.
// I dette tilfælde vil funktionen returnere en double værdi.
double square(double length){
    double result = length * length;
    return result;
    
}

double cube(double length){
    double result = length * length * length;
    return result;
    
}

//her har vi skrevet det kortere:
//double square(double length){
//    return length * length;
//}
