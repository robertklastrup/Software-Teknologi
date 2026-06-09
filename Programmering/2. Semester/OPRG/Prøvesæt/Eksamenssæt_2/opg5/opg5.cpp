#include "opg5.h"


Volumen::Volumen(double v, Unit e){
    volume = v;
    enhed = e;
}

double Volumen::getLiter(){
    if(enhed == Gallon){
        return(volume / 0.264172);
    }
    else {return volume;}
}

double Volumen::getGallon(){
    if(enhed == Liter){
        return(volume * 0.264172);
    }
    else {return volume;}
}

void Volumen::addVolume(double v){
    volume = volume + v;
}


Car::Car(std::string b, double s, Volumen f) : fuel(f){
    brand = b;
    speed = s;
    fuel = f;
}

Volumen Car::getFuel(){
    return fuel;
}
double Car::getSpeed(){
    return speed;
}


double gennemsnit(std::vector <Car> cars, Volumen minFuel){
    double sum = 0;
    double total = 0;
    for (int i = 0; i < cars.size(); i++){
        if (cars[i].getFuel().getLiter() >= minFuel.getLiter()){
            sum = sum + cars[i].getSpeed();
            total++;
        }
        else{
            continue;
        }
    }
    
    return(sum/total);
}

