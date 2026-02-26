#include    <iostream>
using namespace std;

int main() {

    string name;
    cout << "Indtast dit navn: ";
    getline(cin, name);

    if(name.length() > 12) {
        cout << "Dit navn kan ikke være længere end 12 tegn" << '\n';
    }
    else {
        cout << "Velkommen " << name << "!" << '\n';
    }
    return 0;
}