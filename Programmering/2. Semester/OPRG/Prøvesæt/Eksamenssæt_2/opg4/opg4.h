#include <iostream>
#include <vector>

/*
Lav en funktion der tager vector<Car> og beregner gennemsnitshastigheden for bilerne. Hvis bilernes
fuel er nul, skal de ikke medtages i gennemsnittet. Derudover skal funktionen have en parameter som
angiver den minimums fuel en bil skal have for at være med i gennemsnitsberegningen. 
*/

class Car{
    private:
        std::string brand;
        double speed;
        double fuel;
        
    public:
        Car(std::string b, double s, double f);
        double getFuel();
        double getSpeed();
};

double gennemsnit(std::vector <Car> cars, double minFuel);
