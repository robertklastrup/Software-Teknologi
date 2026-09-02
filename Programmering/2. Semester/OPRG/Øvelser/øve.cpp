#include <iostream>
#include <vector>
#include "øve.h"

bool Car::isValid(){
    if(speed >= 0 && fuel.getLiter() >= 0){
        if(fuel.getLiter() == 0 && speed != 0){
            return false;
        }
        return true;
    }
    return false;
}
double Car::getSpeed(){
    return speed;
}
Volumen Car::getFuel(){
    return fuel;
}

bool Car::makeValid(){
    if(isValid() == false){
        if(fuel.getLiter() == 0 && speed != 0){
            speed = 0;
            return true;
        }
        else{
        speed = 0;
        fuel = Volumen(0, Liter);
        return true;
        }
    }
    return true;
}

void Car::print(){
    std::cout << "Brand: " << brand << " | Speed: " << speed << " | Fuel: " << fuel.getLiter() << "L" << std::endl;
}

Car fastest_car(std::vector<Car> c){
    Car fast = c[0];
    for (int i = 0; i < c.size(); i++){
        if(c[i].getFuel().getLiter() == 0.0){
            continue;
        }
        else{
            if (c[i].getSpeed() > fast.getSpeed()){
                fast = c[i];
            }
            else{
                continue;
            }
        }
    }
    return fast;
}