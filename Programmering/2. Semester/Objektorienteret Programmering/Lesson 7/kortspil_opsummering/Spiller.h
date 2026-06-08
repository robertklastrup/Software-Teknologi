#include <iostream>
#include "Haand.h"
#pragma once

class Spiller{
    private:
        std::string navn_;
        int saldo_;
        Haand haand_;
    public:
        Spiller(std::string navn);
        void bet(int beloeb);
        void modtagKort(Kort k);
        Haand getHaand();
        friend std::ostream& operator<<(std::ostream& os, const Spiller& s);
};