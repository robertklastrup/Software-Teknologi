#include    <iostream>
using namespace std;

int main() {

    srand(time(0)); 
    int randNum = rand() % 5 + 1; 

    switch(randNum) {
        case 1: cout << "Du vandt et klistermærke!" << '\n';
        break;
        case 2: cout << "Du vandt en cykel!" << '\n';
        break;
        case 3: cout << "Du vandt en båd!" << '\n';
        break;
        case 4: cout << "Du vandt en motorcykel!" << '\n'; 
        break;
        case 5: cout << "Du vandt en flyvemaskine!" << '\n';
        break;
    }


    return 0;
}