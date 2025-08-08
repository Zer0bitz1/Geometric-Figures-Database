#pragma once
#include "Geometric_Figure.h"
class Circle :
    public Geometric_Figure
{
private:
	double radius;
public:
	Circle();
	Circle(string name, double area, double perimeter, double radius);
	double getRadius();
	void setRadius(double radius);
	void visualizeCir();
};