#include <iostream>
#include <vector>
using namespace std;

// template: funktion der virker med alle datatyper:
template <class altData>
vector <altData> randomVector;

// addCrap: lægger to værdier af vilkårlig type sammen:
template <class altData>
altData addCrap(altData a, altData b){
    return a + b;
}


int main () {

    cout << endl;
    cout << endl;

    // tester addCrap med int:
    int x = 7, y = 43, z;
    z = addCrap(x,y);
    cout << z << endl;

    // tester addCrap med double:
    double a = 7.5, b = 43.1, c;
    c = addCrap(a,b);
    cout << c << endl;

    // tester addCrap med string (sammensætter to strings):
    string navn = "Robert ", efternavn = "Klastrup", d;
    d = addCrap (navn, efternavn);
    cout << d << endl;

    cout << endl;
    cout << endl;
}
