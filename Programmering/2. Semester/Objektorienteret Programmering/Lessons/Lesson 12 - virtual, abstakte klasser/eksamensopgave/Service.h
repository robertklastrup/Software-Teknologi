#include "FakturaLinje.h"
#pragma once

class Service : public FakturaLinje{
    private:
        bool momsPligtig_ = true;
    public:
        Service(std::string navn, double enhedsPris, double antal, bool momsPligtig);
        double beregnPris();
        void print();
};