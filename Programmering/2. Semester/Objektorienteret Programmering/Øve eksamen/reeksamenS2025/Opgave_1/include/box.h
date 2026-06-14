#pragma once
class box {
public:
    box(double, double, double);
    double volume() const;
    static const double delta;
    bool operator ==(const box& right) const;
    double volume () const;
private:
    double length_, width_, height_;
};
