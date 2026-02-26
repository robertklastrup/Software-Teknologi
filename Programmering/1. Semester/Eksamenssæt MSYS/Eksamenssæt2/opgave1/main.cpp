
#include <iostream>
#include "kvadratiskMiddelvaerdi.h"

int main()
{
    double a = 3.0;
    double b = 4.0;

    double resultat = kvadratiskMiddelvaerdi(a, b);

    std::cout << "Den kvadratiske middelvaerdi er: " << resultat << std::endl;

    return 0;
}
