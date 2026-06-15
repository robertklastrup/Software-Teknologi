#include "DomesticAnimal.h"
#include <iostream>
#include <string>

DomesticAnimal::DomesticAnimal(std::string name){
    name_ = name;
}

std::string DomesticAnimal::describe() const{
    std::string describe = "I am a " + type() + " named " + name_;
    return describe;
}