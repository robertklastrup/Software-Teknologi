#include "Fraction.h"
//Opgave 1 b)

Fraction::Fraction(int nominator, int denominator){
    if(denominator == 0){
        throw std::invalid_argument("denominator cannot be 0");
    }
    else{
        this->nominator = nominator;
        this->denominator = denominator;
    }
}

int Fraction::getNominator() const{
    return (nominator);
}

int Fraction::getDenominator() const{
    return (denominator);
}

bool operator==(Fraction fraction_left, Fraction fraction_right){
    int a = fraction_left.getNominator();
    int b = fraction_left.getDenominator();
    int c = fraction_right.getNominator();
    int d = fraction_right.getDenominator();

    if (d*a == c*b){
        return true;
    }
    else{return false;}
}

//Opgave 1 d)
std::ostream& operator<<(std::ostream& os, const Fraction& f){
    os << f.getNominator() << "/" << f.getDenominator() << std::endl;
    return os;
}

//Opgave 1 f)
Fraction operator+(Fraction f_1, Fraction f_2){
    int a = f_1.getNominator();
    int b = f_1.getDenominator();
    int c = f_2.getNominator();
    int d = f_2.getDenominator();

    Fraction f3(a*d + c*b, b*d);
    return (f3);
}
