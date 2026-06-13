#pragma once
#include "Currency.h"
#include <string>
#include <cmath>

//Opgave 1 b)

class Amount{
    private:
        double amount;
        Currency currency;
    public:
        Amount(double a, Currency& c);
        Amount operator+(Amount& other);
        friend bool operator == (Amount& left, Amount& right);
        std::string toString();
};


