#include    <iostream>
#include   <string>

using namespace std;


int main() {
    string name;
    cout << "Indtast dit navn: ";

    getline(cin, name);

    cout << name.at(0) << '\n';
    // at() metoden returnerer tegnet ved den angivne indeksposition, i dette tilfælde indekset 0 som er det første tegn i string variablen name    

    return 0;
    
}