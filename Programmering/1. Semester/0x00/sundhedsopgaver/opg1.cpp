#include <iostream>


int main() {
    float vægt, højde, bmi;

    std::cout << "Indtast din vægt i kg: ";
    std::cin >> vægt;

    std::cout << "Indtast din højde i meter (f.eks. 1.75): ";
    std::cin >> højde;

    // Beregn BMI
    bmi = vægt / (højde * højde);

    std::cout << "Din BMI er: " << bmi << std::endl;

    // Vurder BMI
    if (bmi < 18.5) {
        std::cout << "Du er undervægtig." << std::endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        std::cout << "Du har normalvægt." << std::endl;
    } else if (bmi >= 25 && bmi < 30) {
        std::cout << "Du er overvægtig." << std::endl;
    } else {
        std::cout << "Du er svært overvægtig (fedme)." << std::endl;
    }

    return 0;
}
