#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;

// recursion er når en funktion kalder sig selv  
// bruges til at løse problemer der kan opdeles i mindre delproblemer af samme type
// typiske eksempler er beregning af fakultet, Fibonacci tal, trægange osv.

//fordele ved recursion:
// - gør koden mere læsbar og enklere
// - reducerer kompleksiteten af visse algoritmer

//ulemper ved recursion:
// - kan føre til højere hukommelsesforbrug pga. funktionskaldsstacken
// - kan være mindre effektiv end iterative løsninger pga. overhead ved funktionskald

void walk(int steps);
   


int main () 
{
    int trin;

    cout << "Hvor mange skridt vil du gå? ";
    cin >> trin;

    walk(trin);
    return 0;
}

void walk(int steps){
    if(steps > 0){
        cout << "Du har taget et skridt " << steps << '\n';
        walk(steps - 1); //rekursivt kald
    }
    else{
        cout << "Du er nået til dit mål!" << '\n';
    }
}