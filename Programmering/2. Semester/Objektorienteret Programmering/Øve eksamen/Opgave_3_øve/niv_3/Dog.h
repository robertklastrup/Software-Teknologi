#pragma once
#include "DomesticAnimal.h"

class Dog : public DomesticAnimal{
    public:
        using DomesticAnimal::DomesticAnimal;
        std::string sound() const;
        std::string type() const;
};
