#include "Rotation.h"
#include "point.h"
#include <iostream>
#include <cmath>

//Opgave c-1)

rotation::rotation(double angle){
    this->angle = angle;
}

point rotation::transform(const point& p){
    double x_ny = (std::cos(angle) * p.x) - (std::sin(angle) * p.y);
    double y_ny = (std::sin(angle) * p.x) + (std::cos(angle) * p.y);
    point p1 (x_ny, y_ny);
    return p1;
}