#include <iostream>
#include <cstdlib>   // for rand() og srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    // seed til random generator (nyt udgangspunkt hver gang)
    srand(time(0));

    // tilfældigt tal mellem 1 og 10
    int hemmeligt = rand() % 10 + 1;
    int gaet = 0;

    cout << "Gaet et tal mellem 1 og 10" << endl;

    while (gaet != hemmeligt) {
        cout << "Indtast dit gaet: ";
        cin >> gaet;

        if (gaet == hemmeligt) {
            cout << "Du gaettede rigtigt!" << endl;
        }
        else if (gaet < hemmeligt) {
            cout << "For lavt" << endl;
        }
        else {
            cout << "For hoejt" << endl;
        }
    }

    return 0;
}
