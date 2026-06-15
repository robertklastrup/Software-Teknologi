#pragma once

#include "loan.h"

class serial_loan : public loan{
public:
    serial_loan(std::string name, double principal, double interest_rate, unsigned int terms);
    double get_payment(unsigned int term) const override;

private:
    double calculate_payment(unsigned int term) const;
};