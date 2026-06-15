#pragma once
#include <string>


class Shape{
    public:
        virtual double area() const = 0;
        virtual std::string describe()const = 0;
};