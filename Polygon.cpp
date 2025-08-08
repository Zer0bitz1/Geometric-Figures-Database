#include "Polygon.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

Polygon::Polygon()
{
	sides = 0;
	side_length = 0;
}

Polygon::Polygon(string name, double area, double perimeter, int sides, double side_length) 
	:Geometric_Figure(name, area, perimeter, "Polygon")
{
	this->sides = sides;
	this->side_length = side_length;
}

int Polygon::getSides()
{
	return sides;
}

void Polygon::setSides(int sides)
{
	this->sides = sides;
}

double Polygon::getSideLength()  
{
	return side_length;
}

void Polygon::setSideLength(double side_length)
{
	this->side_length = side_length;
}

void Polygon::visualizePoly()
{
	const float scale = 1.0f;
	int size = static_cast<int>(side_length * scale);

	for (int i = 0; i < sides; ++i) {
		cout << string(size, '*') << endl;
	}
}