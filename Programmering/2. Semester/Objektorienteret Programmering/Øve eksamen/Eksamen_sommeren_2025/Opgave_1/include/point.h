#pragma once
#include <ostream>
class point {
public:
    double x;
    double y;
    point(double x, double y);
    point const operator+(const point& right);
};


std::ostream& operator<<(std::ostream& os, const point& p);
