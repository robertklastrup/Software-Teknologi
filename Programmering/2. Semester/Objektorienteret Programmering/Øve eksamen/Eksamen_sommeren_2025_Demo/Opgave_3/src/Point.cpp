#include "Point.h"
/*
point::point(double x, double y){
	this->x = x;
	this-> y = y;
}
*/
std::ostream& operator<<(std::ostream& os, const point& p)
{
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

