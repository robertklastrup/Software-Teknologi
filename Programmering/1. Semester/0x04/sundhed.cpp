#include    <iostream>
#include    <cmath>
#include    <string>
using namespace std;

void navn(string navn)
{
    cout << "Indtast dit navn: ";
    cin >> navn;
}

void readHealthData(double height, double weight)
{
    cout << "Indtast hoejde (i meter): ";
    cin >> height;
    cout << "Indtast vaegt (i kg): ";
    cin >> weight;
}

double calculateBMI(double height, double weight)
{
    double bmi = weight / (height * height);


    cout << "\n" << "Din BMI er: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Du er undervægtig." << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Du har normal vægt." << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "Du er overvægtig." << endl;
    } else {
        cout << "Du er svært overvægtig." << endl;
    }
    return bmi;

}

int aktivitetLevel(int level)
{
    cout << "nu skal vi se på dit aktivitetsniveau" << endl;

    int minGang, minLoeb, minCykling;
    cout << "Hvor mange minutter har du gaaet i dag? ";
    cin >> minGang;
    cout << "Hvor mange minutter har du loebet i dag? ";
    cin >> minLoeb;
    cout << "Hvor mange minutter har du cyklet i dag? ";
    cin >> minCykling;

    double kalorierGang = minGang * 4.0;
    double kalorierLoeb = minLoeb * 10.0;
    double kalorierCykling = minCykling * 8.0;

    cout << "\nKalorieforbrug ved gaatur:" << kalorierGang << " kcal" << endl;
    cout << "Kalorieforbrug ved loeb:" << kalorierLoeb << " kcal" << endl;
    cout << "Kalorieforbrug ved cykling:" << kalorierCykling << " kcal" << endl;

    double totalKalorier = kalorierGang + kalorierLoeb + kalorierCykling;
    cout << "Samlet kalorieforbrug i dag: " << totalKalorier << " kcal" << endl;

    return 0;
    
}

int aktivDag(int totalKalorier)
{
    if (totalKalorier < 200) {
        cout << "Du har haft en inaktiv dag." << endl;
    } else if (totalKalorier >= 200 && totalKalorier < 500) {
        cout << "Du har haft en moderat aktiv dag." << endl;
    } else {
        cout << "Du har haft en meget aktiv dag." << endl;
    }
    
    cout << "Tak for i dag!" << endl;
    
    return 0;
}

int main ()
{
    navn;
    string navn;
    
    double height;
    double weight;

    readHealthData;
    
    calculateBMI;

    aktivitetLevel;

    aktivDag;
    
    double calculateBMI;

    int level;
    double aktivitetLevel;
    double minGang;
    double minLoeb;
    double minCykling;
    double kalorierGang;
    double kalorierLoeb;
    double kalorierCykling;
    double totlalKalorier;

    double aktivDag;
    int totalKalorier;

    return 0;
}

