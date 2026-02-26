#include    <iostream>
#include    <string>
#include   <vector>

using namespace std;

struct Sang {
    string titel;
    string kunstner;
    double varighed; // i minutter
};

//Vi vil bruge en struktur til at repræsentere en sang med titel, kunstner og varighed.

void sangdata(Sang &sang) {
    cout << "Indtast sangtitel: ";
    cin >> sang.titel;
    cout << "Indtast kunstnernavn: ";
    cin >> sang.kunstner;
    cout << "Indtast sangens varighed (i minutter): ";
    cin >> sang.varighed;
}

//indtastningsfunktionen til at få sangdata fra brugeren og gemme dem i en Sang struktur.

double beregn_total_varighed(const vector<Sang> &spilleliste) {
    double total = 0.0;
    for (const auto &sang : spilleliste) {
        total += sang.varighed;
    }
    return total;
}
//funktionen til at beregne den samlede varighed af alle sange i spillelisten.

double længste_og_korteste_sang(const vector<Sang> &spilleliste, double &korteste) {
    if (spilleliste.empty()) return 0.0;

    double længste = spilleliste[0].varighed;
    korteste = spilleliste[0].varighed;

    for (const auto &sang : spilleliste) {
        if (sang.varighed > længste) {
            længste = sang.varighed;
        }
        if (sang.varighed < korteste) {
            korteste = sang.varighed;
        }
    }
    return længste;
}
//funktionen til at finde den længste og korteste sang i spillelisten.

double udskriv_liste_over_alle_sange(const vector<Sang> &spilleliste) {
    cout << "\nSpilleliste:\n";
    for (const auto &sang : spilleliste) {
        cout << "Titel: " << sang.titel << ", Kunstner: " << sang.kunstner << ", Varighed: " << sang.varighed << " minutter\n";
    }
    double total_varighed = beregn_total_varighed(spilleliste);
    cout << "Samlet varighed af spillelisten: " << total_varighed << " minutter\n";
    return total_varighed;
}

//funktionen til at udskrive alle sange i spillelisten sammen med den samlede varighed.
int main() {
    vector<Sang> spilleliste;
    int antal_sange;

    cout << "Indtast antal sange i spillelisten: ";
    cin >> antal_sange;

    for (int i = 0; i < antal_sange; ++i) {
        Sang ny_sang;
        sangdata(ny_sang);
        spilleliste.push_back(ny_sang);
    }

    double korteste;
    double længste = længste_og_korteste_sang(spilleliste, korteste);

    cout << "\nLængste sang varighed: " << længste << " minutter\n";
    cout << "Korteste sang varighed: " << korteste << " minutter\n";

    udskriv_liste_over_alle_sange(spilleliste);

    return 0;
}
//hovedfunktionen der styrer programmet. Den beder brugeren om at indtaste antal sange, indsamler sangdata, beregner længste og korteste sang, og udskriver spillelisten.

