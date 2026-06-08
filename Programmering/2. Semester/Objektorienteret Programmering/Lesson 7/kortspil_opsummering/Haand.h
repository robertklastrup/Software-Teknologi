#include "Kort.h"
#include <vector>
#include <iostream>
#pragma once


class Haand{
    private:
        std::vector<Kort> kort_;
    public:
        Haand();
        void tilfoejKort(Kort k);
        friend std::ostream& operator<<(std::ostream& os, const Haand& h);
        friend bool operator>(const Haand& h1, const Haand& h2);
};