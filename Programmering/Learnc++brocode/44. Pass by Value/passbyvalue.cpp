#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;

//pass by value vs pass by reference
//når vi passerer en variabel til en funktion, kan vi gøre det på to måder: pass by value og pass by reference.
//pass by value laver en kopi af variablen og sender den til funktionen
// pass by reference sender en reference (adresse) til variablen, så funktionen kan ændre den originale variabel

void swap(string &x, string &y);

// & er brugt til at indikere, at vi passerer ved reference


int main () 
{
    string x = "ost";
    string y = "vand";
    string temp;

    swap(x, y);

    cout << "x: " << x << endl; // vand
    cout << "y: " << y << endl; // ost
        
    return 0;
}

void swap(string &x, string &y) {
    string temp;
    temp = x;
    x = y;
    y = temp;

}