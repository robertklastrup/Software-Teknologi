#include "loan.h"
#include <sstream>

loan::loan(const std::string &name, double principal, double interest_rate, unsigned int terms)
        : name_(name), principal_(principal), interest_rate_(interest_rate), terms_(terms) {}

double loan::get_principal() const {
    return principal_;
}

unsigned int loan::get_terms() const {
    return terms_;
}

double loan::get_rate() const {
    return interest_rate_;
}

std::string loan::get_name() const {
    return name_;
}

double loan::get_total_payment() const
{
    double payment = 0;
    for (int i = 1; i <= terms_; i++)
    {
        payment = payment + get_payment(i);
    }

    return payment;
}

std::string loan::get_payment_scheme() const
{
    std::string loan = "Loan:" + name_ + "\n";
    std::string Principal = "Principal:" + std::to_string(principal_) + "\n";
    std::string Rate = "Rate:" + std::to_string(interest_rate_) + "\n";
    std::string terms;
    double total = 0;
    for (int i = 1; i <= terms_; i++)
    {
        terms = terms + "Term:" + std::to_string(get_payment(i)) + "\n";
        total += get_payment(i);
    }
    std::string total_string = "Total:" + std::to_string(total) + "\n";
    std::string result = loan + Principal + Rate + terms + total_string;
    return result;
}
