#include        <iostream>
#include        <ctime>
using namespace std;




// Pseudo Random Number Generator i C++ - terninger
int main() {

    srand(time(NULL)); //sætter seed for random number generatoren baseret på det nuværende tidspunkt
    
    int num1 = (rand() % 6)+1; //genererer et tilfældigt tal ved hjælp af rand() funktionen og begrænser det til intervallet 0-5 ved hjælp af modulus operatoren %
    int num2 = (rand() % 6)+1;
    int num3 = (rand() % 6)+1;

    cout << "Terning 1 slog " << num1 << '\n';
    cout << "Terning 2 slog " << num2 << '\n';
    cout << "Terning 3 slog " << num3 << '\n';



    return 0;
}