#include    <iostream>
using namespace std;

int main() {
    double pi = 3.14159; //deklaration og initialisering af konstant variabel pi
    const double pi = 3.14159; //deklaration og initialisering af konstant variabel pi, så den ikke kan ændres
    double radius = 10; //deklaration af variabel radius
    double omkreds = 2 * pi * radius; //beregning af omkreds ved hjælp af konstanten pi

    cout << "Omkredsen er: " << omkreds << "cm" << '\n'; //udskrivning af omkreds til konsollen

    return 0;

}


// Det er dog sådan, at man alligevel kan ændre værdien af en konstant hvis man ønsker det.
// Eksempelvis ved at skrive; pi = 5000; under vores deklaration af pi.
// Men hvis du ikke vil have at det sker kan du skrive const foran din variabel som sådan her:
//const double pi = 3.14159;
// Nu vil compiler'en give en fejl hvis du prøver at ændre værdien af pi nogen steder i koden.
// Det giver sikkerhed.