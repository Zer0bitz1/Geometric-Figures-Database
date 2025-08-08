#pragma once
#include "Geometric_Figure.h"
class Triangle :
    public Geometric_Figure
{
private:
	double height;
	double base;
	double a;
	double b;
public:
	Triangle();
	Triangle(string name, double area, double perimeter, double height, double base, double a, double b);
	double getHeight();
	void setHeight(double height);
	double getBase();
	void setBase(double base);
	double getA();
	void setA(double a);
	double getB();
	void setB(double b);
	void visualizeTri();
};

