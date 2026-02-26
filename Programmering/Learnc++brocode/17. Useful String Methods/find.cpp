#include    <iostream>
#include   <string>

using namespace std;


int main() {
    string name;
    cout << "Indtast dit navn: ";

    getline(cin, name);

    cout << name.find(' ') << '\n';
    
    return 0;
    
}