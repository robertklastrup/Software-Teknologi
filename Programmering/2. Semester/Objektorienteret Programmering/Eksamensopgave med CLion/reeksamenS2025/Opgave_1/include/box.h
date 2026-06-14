#pragma once
class box {
public:
    box(double, double, double);
    double volume() const;
    static const double delta;
private:
    double length_, width_, height_;
};
