#pragma once
#include <string>

struct vector
{
public:
	double x;
	double y;
	std::string to_string() const;
	vector operator+(const vector&) const;
	vector operator/(double) const;
};
