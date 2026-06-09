#include "opg4.h"


Car::Car(std::string b, double s, double f){
    brand = b;
    speed = s;
    fuel = f;
}

double Car::getFuel(){
    return fuel;
}
double Car::getSpeed(){
    return speed;
}


double gennemsnit(std::vector <Car> cars, double minFuel){
    double sum = 0;
    double total = 0;
    for (int i = 0; i < cars.size(); i++){
        if (cars[i].getFuel() >= minFuel){
            sum = sum + cars[i].getSpeed();
            total++;
        }
        else{
            continue;
        }
    }
    
    return(sum/total);
}