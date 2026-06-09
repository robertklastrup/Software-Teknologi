#include <iostream>
#include <vector>

/*
Lav en klasse Volumen, som repræsenterer en volumen. 
Denne har en enhed (liter eller gallon) samt en værdi (hvor mange liter/gallon den repræsenterer). 
Klassen har derudover to metoder der returnerer
1. indholdet i hhv liter eller gallon (getLiter og getGallon) 
2. en metode til at tilføje indhold (hvis manskal fjerne, tilføjer man blot en negativ mængde). 
*/
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
        Volumen getFuel();
        double getSpeed();
};

double gennemsnit(std::vector <Car> cars, Volumen minFuel);