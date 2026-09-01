#include "opg2.h"




double pythagoras(double a, double b){
    if(a < 0){
        return -1;
    }
    if(b < 0){
        return -1;
    }
    else{
        return (sqrt((a * a) + (b * b)));
    }
}

double pythagoras_b(double b){
    double a = b * 4;
    return (pythagoras(a, b));
}