#include <iostream>
#include <cstdlib>   // For rand() og srand()
#include <ctime>     // For time()
using namespace std;

int main() {
    int sider;
    int kast;

    // Brugeren vælger antal sider på terningen
    cout << "Hvor mange sider skal terningen have? ";
    cin >> sider;

    // Kontrollér at der er mindst 2 sider
    if (sider < 2) {
        cout << "En terning skal have mindst 2 sider!" << endl;
        return 1;
    }

    // Initialiser tilfældig generator med nuværende tid
    srand(time(0));

    // Simuler kastet (tilfældigt tal mellem 1 og antal sider)
    kast = (rand() % sider) + 1;

    // Vis resultatet
    cout << "Du landede på: " << kast << endl;

    return 0;
}
