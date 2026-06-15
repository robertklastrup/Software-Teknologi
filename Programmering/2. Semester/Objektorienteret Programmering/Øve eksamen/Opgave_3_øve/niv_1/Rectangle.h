#pragma once
#include "Shape.h"


class Rectangle : public Shape{
    private:
        double width_, height_;
    public:
        Rectangle(double width, double height);
        double area()const;
        std::string describe()const;
        
};