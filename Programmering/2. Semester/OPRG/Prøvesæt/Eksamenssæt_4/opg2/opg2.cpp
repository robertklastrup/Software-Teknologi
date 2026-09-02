#include "opg2.h"

double heronisk_middel(double b){
    double a = b * 4;
    return ((a + sqrt(a * b) + b) / 3);
}