#include "test_serial_loan.h"
#include "serial_loan.h"
#include <iostream>

void test_serial_get_payment_scheme() {
    serial_loan a ("Serial_loan", 1000, 0.03, 10);

    std::cout << a.get_payment_scheme();
}