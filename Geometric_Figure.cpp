#include "Geometric_Figure.h"

Geometric_Figure::Geometric_Figure()
{
	name = "";
	area = 0;
	perimeter = 0;
	type = "";
}

Geometric_Figure::Geometric_Figure(string name, double area, double perimeter, string type)
{
	this->name = name;
	this->area = area;
	this->perimeter = perimeter;
	this->type = type;
}

string Geometric_Figure::getName()
{
	return name;
}

void Geometric_Figure::setName(string name)
{
	this->name = name;
}

double Geometric_Figure::getArea()
{
	return area;
}

void Geometric_Figure::setArea(double area)
{
	this->area = area;
}

double Geometric_Figure::getPerimeter()
{
	return perimeter;
}

void Geometric_Figure::setPerimeter(double perimeter)
{
	this->perimeter = perimeter;
}

string Geometric_Figure::getType()
{
	return type;
}

void Geometric_Figure::setType(string type)
{
	this->type = type;
}