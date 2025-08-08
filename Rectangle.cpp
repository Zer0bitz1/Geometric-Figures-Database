#include "Rectangle.h"
#include <cmath>
#include <iostream>
using namespace std;

Rectangle::Rectangle()
{
	height = 0;
	width = 0;
}

Rectangle::Rectangle(string name, double area, double perimeter, double height, double width)
	:Geometric_Figure(name, area, perimeter, "Rectangle")
{
	this->height = height;
	this->width = width;
}

double Rectangle::getHeight()
{
	return height;
}

void Rectangle::setHeight(double height)
{
	this->height = height;
}

double Rectangle::getWidth()
{
	return width;
}

void Rectangle::setWidth(double width)
{
	this->width = width;
}

void Rectangle::visualizeRec() {
	const float scale = 1.0f;
	int widthStars = static_cast<int>(round(width * scale));
	int heightLines = static_cast<int>(round(height * scale));
	for (int i = 0; i < heightLines; ++i) {
		cout << string(widthStars, '*') << endl;
	}
}