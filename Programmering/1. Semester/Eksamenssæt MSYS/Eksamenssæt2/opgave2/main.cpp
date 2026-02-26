// main.cpp
#include <iostream>
#include "kvadratiskMiddelvaerdi.h"
using namespace std;


int main()
{
    double b = 2.0;

    double resultat = kvadratiskMiddelvaerdiFireGange(b);

    cout << "Den kvadratiske middelvaerdi er: " << resultat << '\n';

    return 0;
}
