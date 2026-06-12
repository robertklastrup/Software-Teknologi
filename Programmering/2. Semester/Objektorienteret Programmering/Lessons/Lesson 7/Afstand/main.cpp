#include "Afstand.h"



int main (){
    Afstand a1 (500);
    Afstand a2 (600);

    std::cout << "Afstand 1: " << a1 << '\n' << "Afstand 2: " << a2 << '\n';

    Afstand a3 = a1 + a2;
    std::cout << a3 << '\n';

    std::cout << (a1 < a2);
}