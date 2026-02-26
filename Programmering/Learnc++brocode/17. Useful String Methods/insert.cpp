#include    <iostream>
#include   <string>

using namespace std;


int main() {
    string name;
    cout << "Indtast dit navn: ";

    getline(cin, name);

    name.insert(0, "@");
    // insert() metoden indsætter teksten "@" ved indeksposition 0 i string vari

    cout << name << '\n';
    

    return 0;
    
}