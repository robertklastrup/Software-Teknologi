#include    <iostream>
#include   <string>

using namespace std;


int main() {
    string name;
    cout << "Indtast dit navn: ";

    getline(cin, name);

    name.erase(0, 3);
    // erase() metoden fjerner 3 tegn startende fra indeksposition 0 i string variablen name


    cout << name << '\n';
    return 0;
    
}