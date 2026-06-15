#include <stdexcept>

#include "Vector.h"

std::string vector::to_string() const
{
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

vector vector::operator+(const vector& right) const
{
	return {x + right.x, y + right.y};
}

vector vector::operator/(const double val) const
{
	if (val < 0.0000001)
	{
		throw std::invalid_argument("Division by zero");
	}
	return {x / val, y / val};
}
