#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cctype>

int main() {
    // Liste af barer / værtshuse
    std::vector<std::string> barer = {
        "Bar Smil",
        "Oops",
        "Druden",
        "Heidis",
        "Bar 3",
        "PV",
        "Den Sidste"
    };



    // Random setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, barer.size() - 1);

    char valg;

    std::cout << "Tryk R for random værtshus, Q for at afslutte\n";

    while (true) {
        std::cout << "> ";
        std::cin >> valg;
        valg = std::toupper(valg);

        if (valg == 'R') {
            std::cout << "Du skal paa: "
                      << barer[dist(gen)] << "\n";
        }
        else if (valg == 'Q') {
            std::cout << "Farvel 🍻\n";
            break;
        }
        else {
            std::cout << "Ugyldigt input. Brug R eller Q.\n";
        }
    }

    return 0;
}
