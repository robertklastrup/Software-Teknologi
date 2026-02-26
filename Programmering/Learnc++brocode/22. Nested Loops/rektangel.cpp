#include    <iostream>
using namespace std;

int main() {

    int rows;
    int columns;
    char symbol;

    cout << "Indtast antal rækker: ";
    cin >> rows;

    cout << "Indtast antal kolonner: ";
    cin >> columns;

    cout << "Indtast et symbol: ";
    cin >> symbol;


    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
        cout << symbol;
        }
        cout << '\n';
    }
    

    return 0;
}