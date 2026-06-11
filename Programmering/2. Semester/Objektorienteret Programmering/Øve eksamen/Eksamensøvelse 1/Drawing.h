#pragma once
#include "Shape.h"

class Drawing
{
public:
	Drawing(int id);
	~Drawing() override;
	void print() const override;
	double area() const override;
	double circumference() const override;
	void add(Shape* shape);

private:

};
