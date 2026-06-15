#pragma once
#include "Animal.h"

class DomesticAnimal : public Animal{
    private:
        std::string name_;
    public:
        DomesticAnimal(std::string name);
        //implementering
        std::string describe() const;
        //pure virtual:
        virtual std::string sound() const = 0;
        virtual std::string type() const = 0;
};