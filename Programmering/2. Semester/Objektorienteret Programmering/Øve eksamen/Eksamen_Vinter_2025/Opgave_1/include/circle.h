#pragma once

#include "point.h"

class circle {

    friend std::ostream &operator<<(std::ostream &, const circle &);
    friend bool operator&&(const circle& left, const circle& right);

public:
    circle(point, double);
    circle operator*(double scale);
private:
    point center_;
    double radius_;

};


