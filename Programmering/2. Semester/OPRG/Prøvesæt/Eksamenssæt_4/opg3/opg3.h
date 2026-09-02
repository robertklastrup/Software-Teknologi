#include <iostream>


class Ansat{
    private:
        std::string name;
        double lon;
        int ancinitet;
        std::string afdeling;
    public:
        Ansat(std::string n, double l, int a, std::string afdl);
        bool isValid();
        void makeValid();
        void print();
};