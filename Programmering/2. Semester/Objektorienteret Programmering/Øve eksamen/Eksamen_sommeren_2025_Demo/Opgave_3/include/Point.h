#pragma once
#include <ostream>

struct point
{
	double x;
	double y;

	/*point(double x, double y);*/
};
std::ostream& operator<<(std::ostream&, const point&);
