#include "circle.h"
#include "point.h"
#include <cmath>

circle::circle(point center, double radius) : center_(center), radius_(radius) {}

// implement scale operator

// implement intersect operator


std::ostream &operator<<(std::ostream &os, const circle &circle) {
    os << "center:" << "(" << circle.center_.x << "," << circle.center_.y << ")" << " radius:" << circle.radius_;
    return os;
}

circle circle:: operator*(double scale)
{
    double r = radius_ * scale;
    return circle(center_, r);
}

bool operator&&(const circle& left, const circle& right)
{
    point c = left.center_-right.center_;
    double n = c.norm();
    double r = right.radius_ + left.radius_;
    if (n <= r)
    {
        return true;
    }
    else
    {
        return false;
    }
}