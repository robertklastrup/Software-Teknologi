#include "annuity_loan.h"
#include <stdexcept>


double annuity_loan::calculate_payment(double principal, double interest_rate, unsigned int terms) {
    return principal * interest_rate * pow((1 + interest_rate), terms) / (pow((1 + interest_rate), terms) - 1);
}

annuity_loan::annuity_loan(std::string name, double principal, double interest_rate, unsigned int terms) : loan(name, principal, interest_rate,terms), payment_(calculate_payment(principal, interest_rate, terms))
{
}

double annuity_loan::get_payment(unsigned int term) const{
    if(term < 1 || term > get_terms()){
        throw std::invalid_argument("Invalid argument");
    }
    else{
        return payment_;
    }
}

