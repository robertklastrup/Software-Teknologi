#pragma once

#include <iostream>

class point {
public:
    point(double, double);

    double norm();

    double x;
    double y;
};
std::ostream& operator<<(std::ostream& os, const point& p);

point operator*(double, const point &);

point operator+(const point &, const point &);

point operator-(const point & left, const point & right);

