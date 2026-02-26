#include    <iostream>
using namespace std;

int main() {
   
    // int heltal
    int alder = 22; 
    int år = 2024;

    // double decimaltal
    double højde = 175.5;
    double vægt = 70.2;
    
    // char enkelttegn
    char karakter = 'A';
    char initial = 'R';

    // Bool sandt/falsk (ligesom lys, tændt/slukket)
    bool studerende = true;
    bool tændt = false;
    bool tilbud = true;

    //String tekst
    string navn = "Robert";
    string dag = "Fredag";

    //programmet udskriver værdierne af de forskellige variabler til konsollen
    cout << "Alder: " << alder << '\n';
    cout << "År: " << år << '\n';
    cout << "Højde: " << højde << " cm\n";
    cout << "Vægt: " << vægt << " kg\n";
    cout << "Karakter: " << karakter << '\n';
    cout << "Initial: " << initial << '\n';
    cout << "Er studerende: " << studerende << '\n';
    cout << "Er tændt: " << tændt << '\n';
    cout << "Er på tilbud: " << tilbud << '\n';
    cout << "Navn: " << navn << '\n';
    cout << "Dag: " << dag << '\n';

    // Vi sætter nu nogle af variablerne sammen og udskriver dem (husk mellemrum efter ord så det ikke bliver returneret som ét langt ord)
    cout << "hej " << navn << ", i dag er det " << dag << "!\n";
    cout << "Du er " << alder << " år gammel i år " << år << ".\n";


    return 0;


}