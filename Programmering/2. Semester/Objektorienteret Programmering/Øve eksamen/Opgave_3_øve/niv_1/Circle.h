#pragma once
#include "Shape.h"
#include <string>


class Circle : public Shape{
    private:
        double radius_;
    public:
        Circle(double radius);
        double area() const;
        std::string describe() const;

};