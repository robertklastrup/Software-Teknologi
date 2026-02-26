#include  <iostream>
using namespace std;

//Rækkefølge:
//paranteser
//multiplikation og division
//addition og subtraktion

int main() {

    int students = 6 - 5 + 4 * 3 / 2;

    //i dette tilfælde vil multiplikation og division blive udført først, så 4 * 3 = 12, og derefter 12 / 2 = 6. så det bliver 7


    cout << students << '\n';
    return 0;


}