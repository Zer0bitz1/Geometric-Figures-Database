#pragma once
#include <string>
using namespace std;

class Geometric_Figure
{
private:
	string name;
	double area;
	double perimeter;
	string type;
public:
	Geometric_Figure();
	Geometric_Figure(string name, double area, double perimeter, string type);
	virtual ~Geometric_Figure() = default;
	string getName();
	void setName(string name);
	double getArea();
	void setArea(double area);
	double getPerimeter();
	void setPerimeter(double perimeter);
	string getType();
	void setType(string type);
};