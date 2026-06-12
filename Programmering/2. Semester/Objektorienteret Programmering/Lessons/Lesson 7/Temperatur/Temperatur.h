#include <iostream>


class Temperatur{
    private:
        double grader_;
    public:
        Temperatur(double g);
        friend std::ostream& operator<<(std::ostream& os, const Temperatur& grader_);
        friend Temperatur operator+(Temperatur a, Temperatur b);
        friend bool operator==(Temperatur a, Temperatur b);
};

