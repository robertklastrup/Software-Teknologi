#include <iostream>
#pragma once


class FakturaLinje{
    private:
        std::string navn_ = "Koeb";
    protected:
        double enhedsPris_ = 100.0;
        double antal_ = 1;
    public:
        FakturaLinje(std::string navn, double enhedsPris, double antal);
        virtual double beregnPris() = 0;
        virtual void print();
        virtual ~FakturaLinje();
};