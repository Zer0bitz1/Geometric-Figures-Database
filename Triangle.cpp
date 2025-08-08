#include "Triangle.h"
#include <cmath>
#include <iostream>
using namespace std;

Triangle::Triangle()
{
	height = 0;
	base = 0;
	a = 0;
	b = 0;
}

Triangle::Triangle(string name, double area, double perimeter, double height, double base, double a, double b)
	:Geometric_Figure(name, area, perimeter, "Triangle")
{
	this->height = height;
	this->base = base;
	this->a = a;
	this->b = b;
}

double Triangle::getHeight()
{
	return height;
}

void Triangle::setHeight(double height)
{
	this->height = height;
}

double Triangle::getBase()
{
	return base;
}

void Triangle::setBase(double base)
{
	this->base = base;
}

double Triangle::getA()
{
	return a;
}

void Triangle::setA(double a)
{
	this->a = a;
}

double Triangle::getB()
{
	return b;
}

void Triangle::setB(double b)
{
	this->b = b;
}

void Triangle::visualizeTri() {
	const float scale = 1.0f;
	int width = static_cast<int>(round(base * scale));
	int heightLines = static_cast<int>(round(height * scale));
	if (width % 2 == 0) width += 1;
	for (int i = 0; i < heightLines; ++i) {
		float ratio = static_cast<float>(i + 1) / heightLines;
		int lineWidth = static_cast<int>(ratio * width);

		if (lineWidth % 2 == 0) lineWidth += 1;

		int spaces = (width - lineWidth) / 2;
		std::cout << string(spaces, ' ') << string(lineWidth, '*') << endl;
	}
}