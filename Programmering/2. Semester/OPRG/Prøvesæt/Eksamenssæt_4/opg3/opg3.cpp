#include "opg3.h"


Ansat::Ansat(std::string n, double l, int a, std::string afdl){
    name = n;
    lon = l;
    ancinitet = a;
    afdeling = afdl;
}

bool Ansat::isValid(){
    if(lon > 0 && ancinitet >= 0){
        return true;
    }
    else{
        return false;
    }
}

void Ansat::makeValid(){
    if (isValid() == false){
        if (lon < 0 && ancinitet <= 0){
            lon = 1000;
            ancinitet = 0;
        }
        else if (lon < 0){
            lon = 1000;
        }
        else if (ancinitet <= 0){
            ancinitet = 0;
        }
    }
}

void Ansat::print(){
    std::cout << "Ansat" << std::endl;
    std::cout << "Navn: " << name << std::endl;
    std::cout << "Lon: " << lon << std::endl;
    std::cout << "Ancinitet: " << ancinitet << std::endl;
    std::cout << "Afdeling: " << afdeling << std::endl;
}

