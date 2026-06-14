#pragma once

#include "point.h"
#include <ostream>

class square {

public:
    square(const point &, double);
    point get_center() const;
    double area() const;
    friend square operator+(square a, square b);
    friend std::ostream& operator<<(std::ostream& os, const square& s);
private:
    point center_;
    double size_;

};