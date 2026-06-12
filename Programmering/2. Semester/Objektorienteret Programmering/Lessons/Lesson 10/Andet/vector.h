#pragma once

#include <iostream>

class vector {

    friend std::ostream &operator<<(std::ostream &, const vector &);

public:
    vector(double, double);

private:
    double x_;
    double y_;
};