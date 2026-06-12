#include <iostream>

class Broek{
    private:
        int taeller_;
        int naevner_;
    public:
        Broek(int taeller, int naevner);
        friend Broek operator+(Broek b1, Broek b2);
        friend Broek operator*(Broek b1, Broek b2);
        friend bool operator==(Broek b1, Broek b2);
        friend std::ostream& operator<<(std::ostream& os, const Broek& b1);
};