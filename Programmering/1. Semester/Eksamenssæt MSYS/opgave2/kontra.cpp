#include "Kontraharmonisk.h"
#include "kontra.h"

// Beregner (a^2 + b^2) / (a + b)
double kontraMiddel(double b)
{
    double a = b * 4;

    return kontraharmoniskMiddel(a, b);

}


