#include "broeker.h"

int main(){
    Broek b1 (1,3);
    Broek b2 (2,7);

    std::cout << "Brøk 1: " << b1 << '\n' << "Brøk 2: " << b2 << '\n';

    Broek b3 = b1 + b2;
    std::cout << "Brøkerne lagt sammen: " << b3 << '\n';
    
    Broek b4 = b1 * b2;
    std::cout << "Brøkerne ganget sammen: " << b4 << '\n';

    std::cout << "Er første brøk og anden brøk ens: " << (b1 == b2);

}