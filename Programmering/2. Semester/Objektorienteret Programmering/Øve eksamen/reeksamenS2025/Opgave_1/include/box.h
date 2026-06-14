#pragma once
class box {
public:
    box(double, double, double);
    double volume() const;
    static const double delta;
    bool operator ==(const box& right) const;


private:
    double length_, width_, height_;
};

bool operator<(box b1, box b2);