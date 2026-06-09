#include "opg3.h"



Car::Car(std::string b, double s, double f){
    brand = b;
    speed = s;
    fuel = f;
}
void Car::print (){
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Fuel: " << fuel << std::endl;
}

bool Car::isValid(){
    if(speed >= 0 && fuel >= 0){
        if(fuel == 0 && fuel != speed){
            std::cout << "Objektet er ugyldigt, da fuel = 0 og speed < 0" << std::endl;
            return false;
        }
        else {return true;}
    }
    else{
        std::cout << "Bilobjektet er ugyldigt" << std::endl;
        return false;
    }
}

bool Car::makeValid(){
    if(isValid() == false){
        if(fuel < 0 || speed < 0){
            fuel = 0;
            speed = 0;
            std::cout << "Fuel eller speed var negativ, de er nu sat til 0 og det er et gyldigt objekt" << std::endl;
            print();
            return true;
        }
        else if(fuel == 0 && fuel != speed){
            speed = 0;
            std::cout << "Eftersom fuel = 0, men speed != 0, bliver speed sat til 0 " << std::endl;
            print();
            return true;
        }
        else{
            print();
            return true;
        }
    }
    else{
        std::cout << "Gyldigt objekt:" << std::endl;
        print();
        return true;
    }
}