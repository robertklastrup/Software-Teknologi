#include "point.h"
#include <cmath>

double point::norm()
{
    return sqrt((x*x)+(y*y));
}

point::point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const point& p)
{
    os << "(" << p.x << "," << p.y << ")" << std::endl;
    return os;
}

point operator+(const point &left, const point &right) {
    return point(left.x + right.x, left.y + right.y);
}

point operator*(double s, const point &point) {
    return {s * point.x, s * point.y};
}

point operator-(const point & left, const point & right)
{
    return left + (-1*right);
}