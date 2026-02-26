// kvadratiskMiddelvaerdi.cpp
#include <cmath>
#include "kvadratiskMiddelvaerdi.h"

double kvadratiskMiddelvaerdi(double a, double b)
{
    return sqrt((a * a + b * b) / 2);
}

double kvadratiskMiddelvaerdiFireGange(double b)
{
    double a = 4 * b;
    return kvadratiskMiddelvaerdi(a, b);
}
