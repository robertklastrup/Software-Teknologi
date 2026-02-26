#include <iostream>
using namespace std;

int main() {
    double vægt, højde, bmi;

    cout << "Indtast din vægt i kg: ";
    cin >> vægt;

    cout << "Indtast din højde i meter: ";
    cin >> højde;

    bmi = vægt / (højde * højde);

    cout << "Din BMI er: " << bmi << "\n";

    if (bmi < 18.5)
        cout << "Du er undervægtig\n";
    if (bmi >= 18.5 && bmi < 25)
        cout << "Du er normalvægtig\n";
    if (bmi >= 25 && bmi < 30)
        cout << "Du er overvægtig\n";
    if (bmi >= 30)
        cout << "Du er svært overvægtig\n";

    return 0;
}