#include <iostream>
#include <vector>
using namespace std;

//lav en funktion der ligger to tal sammen
//int addCrap(int a, int b){
//    return a + b;
//}

//Nu skal vi lave en lommeregner
//For at gøre det, skal vi sørge for at de kan køre alle datatyper
//Template definition:

template <class altData>
vector <altData> randomVector;

template <class altData>
altData addCrap(altData a, altData b){
    return a + b;
}


int main () {

    cout << endl;
    cout << endl;

    int x = 7, y = 43, z;
    z = addCrap(x,y);
    cout << z << endl;

    double a = 7.5, b = 43.1, c;
    c = addCrap(a,b);
    cout << c << endl;

    string navn = "Robert ", efternavn = "Klastrup", d;
    d = addCrap (navn, efternavn);
    cout << d << endl;

    cout << endl;
    cout << endl;
}