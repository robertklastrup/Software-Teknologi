#include "Amount.h"
#include "Currency.h"




//Opgave 1c)
Amount::Amount(double a, Currency& c) : amount(a), currency(c){}
        


//Opgave 1 d)
std::string Amount::toString(){
    std::string amount_string = std::to_string(amount);
    std::string currency_string = amount_string + " " + currency.getSymbol();
    return(currency_string);
}

//Opgave 1 f)
Amount Amount::operator+(Amount& other){
    double left_euro = currency.toStandardCurrency(amount);
    double right_euro = other.currency.toStandardCurrency(other.amount);
    double sum_euro = left_euro + right_euro;
    double sum_left_currency = currency.fromStandardCurrency(sum_euro);
    Amount a (sum_left_currency, currency);
    return (a);
}


//Opgave 1 h)
bool operator == (Amount& left, Amount& right){
    double left_euro = left.currency.toStandardCurrency(left.amount);
    double right_euro = right.currency.toStandardCurrency(right.amount);
    double difference = left_euro - right_euro;
    difference = std::abs(difference);

    if (difference < 0.001){
        return true;
    }
    else{return false;}
}
