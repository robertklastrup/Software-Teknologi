#include "Circle.h"


Circle::Circle(double radius){
    radius_ = radius;
}

double Circle::area() const{
    return (3.14 * radius_ * radius_);
}

std::string Circle::describe() const{
    std::string d = "Cirle with radius " + std::to_string(radius_);
    return d;
}