#include <iostream>
#include <stdexcept>
#pragma once

//Opgave 1 a )
class Fraction{
    private:
        int nominator;
        int denominator;
    public:
        Fraction(int nominator = 1, int denominator = 1);
        int getNominator() const;
        int getDenominator() const;
        friend bool operator==(Fraction fraction_left, Fraction fraction_right);
        
};

//Opgave 1 d )
std::ostream& operator<<(std::ostream& os, const Fraction& f);

//Opgave 1 f)
Fraction operator+(Fraction f_1, Fraction f_2);

