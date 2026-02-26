#include        <iostream>

// Namespace er en måde at organisere kode på og undgå navnekonflikter i større projekter.
// Ved at bruge namespaces kan vi gruppere relaterede funktioner, klasser og variabler sammen under et fælles navn.
// Dette hjælper med at forhindre navnekollisioner, især når vi arbejder med biblioteker eller større kodebaser.

using namespace std;
// Dette er et godt eksempel på brugen af namespaces i C++:
// Det gør at vi ikke skal skrive "std::" foran hver standard funktion eller objekt fra standard biblioteket.

// Man kan også bare bruge denne:
using std::cout;
using std::endl;
// Her specificerer vi kun de enkelte elementer vi vil bruge fra std namespace.


namespace first {
    int x = 1;
}
// Opretter et namespace kaldet "first" og definerer en variabel x inden for det namespace.

namespace second {
    int x = 2;
}
// Opretter et andet namespace kaldet "second" og definerer en variabel x inden for det namespace.


int main() {
    int x = 0; // Lokal variabel i main-funktionen

    cout << first::x << '\n';  // Adgang til x i "first" namespace
    cout << second::x << '\n'; // Adgang til x i "second"

    return 0;
}

// her får jeg værdien af x i hvert namespace ved at bruge scope resolution operatoren (::).


// Jeg kan også vælge at skrive det på denne måde hvis jeg bare vil bruge ét namespace i hele mit program:

int main() {
    using namespace first; // Bruger "first" namespace

    cout << x << '\n';
    
    return 0;
}

// Her behøver jeg ikke at specificere "first::" foran x, da jeg har angivet, at jeg bruger "first" namespace i hele main-funktionen.