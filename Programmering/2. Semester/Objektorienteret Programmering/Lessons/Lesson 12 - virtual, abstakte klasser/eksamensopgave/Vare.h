#include <iostream>
#include "FakturaLinje.h"
#pragma once


class Vare : public FakturaLinje{
    public:
        Vare(std::string navn, double enhedsPris, double antal);
        double beregnPris();
};