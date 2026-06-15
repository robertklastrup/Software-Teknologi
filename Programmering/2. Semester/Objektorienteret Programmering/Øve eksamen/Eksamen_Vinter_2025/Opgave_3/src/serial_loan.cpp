#include "serial_loan.h"
#include <stdexcept>



double serial_loan::calculate_payment(unsigned int term) const {
    auto remaining = get_principal() - (term - 1) * get_principal() / get_terms();
    auto interest = get_rate() * remaining;
    return get_principal() / get_terms() + interest;

}

serial_loan::serial_loan(std::string name, double principal, double interest_rate, unsigned int terms) : loan(name, principal, interest_rate,terms){}

double serial_loan::get_payment(unsigned int term) const
{
    if(term < 1 || term > get_terms()){
        throw std::invalid_argument("Invalid argument");
    }
    else{
        return calculate_payment(term);
    }
}

