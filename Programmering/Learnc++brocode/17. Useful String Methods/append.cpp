#include    <iostream>
#include   <string>

using namespace std;


int main() {
    string name;
    cout << "Indtast dit navn: ";

    getline(cin, name);

    name.append("@gmail.com");
    // append() metoden tilføjer teksten "@gmail.com" til slutningen af string variablen name

    cout << "Din fulde email er: " << name << '\n';
    return 0;
    
}