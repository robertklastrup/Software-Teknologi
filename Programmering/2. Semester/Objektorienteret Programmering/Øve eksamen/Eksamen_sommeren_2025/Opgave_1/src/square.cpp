#include "square.h"
#include "point.h"
#include <cmath>

square::square(const point &center, double size) : center_{center}, size_(size) {}

point square::get_center() const {
    return center_;
}

double square::area() const {
    return pow(size_, 2);
}

square operator+(square a, square b){
    point center = (a.center_ + b.center_);
    double areal = a.area() + b.area();
    square c(center, sqrt(areal));
    return(c);
}

std::ostream& operator<<(std::ostream& os, const square& s){
    os << "Center" << s.get_center() << " Area: " << s.area();
    return os;
}