#pragma once
#include <string>

class Animal{
    public: 
        virtual std::string sound() const = 0;
        virtual std::string describe() const = 0;
        virtual std::string type() const = 0;
};