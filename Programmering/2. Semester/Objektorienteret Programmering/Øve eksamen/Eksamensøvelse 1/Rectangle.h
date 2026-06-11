#pragma once
#include "Shape.h"
#include "Point.h"

class Rectangle
{
public:
	Rectangle(const Point& corner, double height, double width);
	void print() const override;
	double area() const override;
	double circumference() const override;

private:
	Point corner;
	double height;
	double width;
};
