#pragma once
#include "Geometric_Figure.h"
class Polygon :
    public Geometric_Figure
{
private:
	int sides;
	double side_length;
public:
	Polygon();
	Polygon(string name, double area, double perimeter, int sides, double side_length);
	int getSides();
	void setSides(int sides);
	double getSideLength();
	void setSideLength(double side_length);
	void visualizePoly();
};