#pragma once
#include "Geometric_Figure.h"
class Rectangle :
    public Geometric_Figure
{
private:
	double height;
	double width;
public:
	Rectangle();
	Rectangle(string name, double area, double perimeter, double height, double width);
	double getHeight();
	void setHeight(double height);
	double getWidth();
	void setWidth(double width);
	void visualizeRec();
};

