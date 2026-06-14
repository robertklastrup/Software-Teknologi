#include "point.h"


point::point(double x, double y){
    this->x = x;
    this->y = y;
}

point const point::operator+(const point& right){
    point mid ((right.x + x)/2.0, (right.y + y)/2.0);
    return mid;
}


std::ostream& operator<<(std::ostream& os, const point& p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
