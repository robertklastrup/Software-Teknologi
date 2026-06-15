#pragma once

#include <string>
/*I filen loan.h er klassen loan delvist deklareret. Der mangler deklaration af den abstrakte metode get payment.
Deklarer denne.*/

class loan {
public:
    std::string get_payment_scheme() const;


protected:
    loan(const std::string &name, double principal, double interest_rate, unsigned int terms);
    virtual double get_payment(unsigned int term) const = 0;

    double get_total_payment() const;

    double get_principal() const;

    unsigned int get_terms() const;

    std::string get_name() const;

    double get_rate() const;
private:
    std::string name_;
    double principal_;
    double interest_rate_;
    unsigned int terms_;
};