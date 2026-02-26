#include    <iostream>
using namespace std;

void input (double &afstand, double &fart) {
    cout << "Indtast afstand (i km): ";
    cin >> afstand;
    cout << "Indtast fart (i km/t): ";
    cin >> fart;
}
// Overstående funktion bruges til at brugeren kan indstte afstand og fart. Vi bruger en void funktion fordi vi ikke behøver at returnere nogen værdoier.

double beregn_tid (double afstand, double fart) {
    return afstand / fart;
}

//overstående funktion bruges til at beregne tiden det tager at køre en bestemt afstand med en bestemt fart. Funktionen returnerer tiden i timer.

double beregn_antal_kalorier (double afstand) {
    const double kalorier_per_km = 30.0; // Antal kalorier forbrændt per km
    return afstand * kalorier_per_km;
}
//overstående funktion bruges til at beregne antallet af kalorier forbrændt under cykelturen baseret på den tilbagelagte afstand. Funktionen returnerer antallet af forbrændte kalorier.

double turinformationer (double afstand, double fart) {
    double tid = beregn_tid(afstand, fart);
    double kalorier = beregn_antal_kalorier(afstand);

    cout << "Tid for turen: " << tid << " timer" << endl;
    cout << "Forbrændte kalorier: " << kalorier << " kcal" << endl;

    return tid;
}
//overstående funktion bruges til at vise informationer om turen, herunder tid og forbrændte kalorier. Funktionen returnerer tiden for turen.

int main() {
    double afstand, fart;

    input(afstand, fart);
    turinformationer(afstand, fart);

    return 0;
}
//overstående er hovedfunktionen der styrer programmet. Den kalder input-funktionen for at få afstand og fart fra brugeren, og derefter kalder turinformationer-funktionen for at vise turens informationer.
