#include "Temperatur.h"
using namespace std;

Temperatur :: Temperatur(double g){
    grader_ = g;
}
ostream& operator<<(ostream& os, const Temperatur& grader_){
    os << grader_.grader_ << " grader" << endl;
    return os;
}

Temperatur operator+(Temperatur a, Temperatur b){
    return Temperatur (a.grader_ + b.grader_);
}
bool operator==(Temperatur a, Temperatur b){
    if(a.grader_ == b.grader_){
        return true;
    }
    else{
        return false;
    }
}