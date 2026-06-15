#include "Translation.h"
#include "point.h"
//Opgave e-1)

translation::translation(double dx, double dy){
    this->dx = dx;
    this->dy = dy;
}

point translation::transform(const point& p){
    double x_ny = dx + p.x;
    double y_ny = dy + p.y;
    point p1 (x_ny, y_ny);
    return p1;
}