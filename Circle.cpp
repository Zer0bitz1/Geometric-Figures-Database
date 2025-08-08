#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle()
{
	radius = 0;
}

Circle::Circle(string name, double area, double perimeter, double radius)
	:Geometric_Figure(name, area, perimeter, "Circle")
{
	this->radius = radius;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

void Circle::visualizeCir()
{
	const float scale = 1.0f;
	int r = static_cast<int>(round(radius * scale));
	int diameter = r * 2;
	for (int y = -r; y <= r; ++y) {
		for (int x = -r; x <= r; ++x) {
			float dist = sqrt(x * x + y * y);
			if (dist <= r)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}