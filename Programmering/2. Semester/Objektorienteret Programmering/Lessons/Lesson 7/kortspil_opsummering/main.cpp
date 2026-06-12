#include "Kort.h"
#include "Haand.h"


int main (){
    Kort k1 (5, HJERTER);
    Kort k2 (10, SPAR);
    Kort k3 (12, RUDER);
    Kort k4 (2, KLOER);
    Kort k5 (13, RUDER);
    Kort k6 (14, RUDER);

    Haand h1;
    Haand h2;

    h1.tilfoejKort(k1);
    h1.tilfoejKort(k2);
    h1.tilfoejKort(k3);
    h2.tilfoejKort(k4);
    h2.tilfoejKort(k5);
    h2.tilfoejKort(k6);

    std::cout << "Haand 1:" << std::endl << h1 << std::endl;
    std::cout << "Haand 2:" << std::endl << h2 << std::endl;

    std::cout << (h1 > h2) << std::endl;

}