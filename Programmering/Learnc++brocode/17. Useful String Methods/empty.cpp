#include    <iostream>
#include    <string>
using namespace std;


int main() {

    string name;
    cout << "Indtast dit navn: ";
    getline(cin, name);

    if(name.empty()) {
        cout << "Du skrev ikke dit navn" << '\n';
    }
    else {
        cout << "Velkommen " << name << "!" << '\n';
    }
    return 0;
}