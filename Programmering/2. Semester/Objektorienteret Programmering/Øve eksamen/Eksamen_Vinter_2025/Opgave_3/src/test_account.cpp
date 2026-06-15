#include "test_account.h"
#include "account.h"
#include "annuity_loan.h"
#include "serial_loan.h"
#include <iostream>

void test_account_all_schemes() {
    annuity_loan al ("Annuity_loan", 1000, 0.03, 10);
    serial_loan sl ("Serial_loan", 1000, 0.03, 10);

    account a;
    a.add_loan(&al);
    a.add_loan(&sl);

    std::cout << a.all_schemes();
}