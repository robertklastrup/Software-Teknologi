#include "Rectangle.h"



Rectangle::Rectangle(double width, double height){
    width_ = width;
    height_ = height;
}

double Rectangle::area()const{
    return (width_ * height_);
}

std::string Rectangle::describe()const{
    std::string d = "Rectangle with width " + std::to_string (width_) + " and " + std::to_string(height_);
    return d;
}

