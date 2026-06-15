#include "account.h"
#include <sstream>

void account::add_loan(loan *loan) {
    loans_.push_back(loan);

}

std::string account::all_schemes()
{
    std::string loan;
    for (int i = 0; i < loans_.size(); i++)
    {
        loan = loan + loans_[i]->get_payment_scheme() + "\n";
    }
    return loan;
}