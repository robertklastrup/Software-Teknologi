#include       <iostream>
using namespace std;

int main() {
    
    char grade;

    cout << "Indtast dit karakter bogstav (A-F): ";
    cin >> grade;

    switch(grade){
        case 'A':
            cout << "Fantastisk job!" << '\n';
            break;
        case 'B':
            cout << "Godt klaret!" << '\n';  
            break;
        case 'C':
            cout << "Du klarede det fint!" << '\n';
            break;
        case 'D':
            cout << "Du bestod lige akkurat!" << '\n';    
            break;
        case 'F':
            cout << "Desværre, du dumpede." << '\n';
            break;  
        default:
            cout << "Ugyldigt karakter bogstav!" << '\n';
            break;

    }

    return 0;

}
