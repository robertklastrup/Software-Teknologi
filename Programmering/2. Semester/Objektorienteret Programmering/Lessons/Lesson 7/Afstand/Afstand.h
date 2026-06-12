#include <iostream>


class Afstand{
    private:
        double meter_;
    public:
        Afstand(double m);
        friend Afstand operator+(Afstand a, Afstand b);
        friend bool operator<(Afstand a, Afstand b);
        friend std::ostream& operator<<(std::ostream& os, const Afstand& meter_);
};