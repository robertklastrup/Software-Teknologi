#include <iostream>
#include <vector>

enum Unit{
    Liter = 1,
    Gallon = 2,
};

class Volumen{
    private:
        double volume;
        Unit enhed;
    public:
        Volumen(double v, Unit e);
        double getLiter();
        double getGallon();
        void addVolume(double v);
};

class Car{
    private:
        std::string brand;
        double speed;
        Volumen fuel;
    public:
        Car(std::string b, double s, Volumen f);
        double getSpeed();
        Volumen getFuel();
        bool isValid();
        bool makeValid();
        void print();
        
};
Car fastest_car(std::vector<Car> c);