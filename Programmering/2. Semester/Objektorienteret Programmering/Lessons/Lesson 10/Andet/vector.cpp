#include "vector.h"

vector::vector(double x, double y) : x_(x), y_(y) {}


std::ostream &operator<<(std::ostream &os, const vector &right) {
    os << "(" << right.x_ << "," << right.y_ << ")";
    return os;
}