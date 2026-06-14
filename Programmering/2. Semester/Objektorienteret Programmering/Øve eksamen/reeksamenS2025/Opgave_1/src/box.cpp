#include "box.h"
#include <cmath>
#include <iostream>

//initialization of static member
const double box::delta = 0.001;

// ctor implementation
box::box(double length, double width, double height) : length_(length), width_(width), height_(height) {}

//implementation of volume
double box::volume() const {
    return length_ * width_ * height_;
}

bool box::operator ==(const box& right) const
{
    if (std::abs(volume() - right.volume()) < delta)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool operator<(box b1, box b2)
{
    if (b1.volume() < (b2.volume()-box::delta))
    {
        return true;
    }
    else
    {
        return false;
    }
}