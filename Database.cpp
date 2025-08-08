#include "Database.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Database::Database()
{
	fileName = "database.bin";
	outFile.open(fileName, ios::binary);
	if (!outFile.is_open())
	{
		cout << "Error: Could not open file for writing." << endl;
		return;
	}
	outFile.close();
}

Database::~Database()
{
	for (int i = 0; i < figures.size(); i++)
	{
		delete figures[i];
	}
	figures.clear();
}

void Database::addFigure(Geometric_Figure* figure)
{
	if (figure->getName().empty())
	{
		cout << "Error: Figure name cannot be empty." << endl;
		return;
	}
	if (figure->getArea() <= 0)
	{
		cout << "Error: Figure area must be greater than zero." << endl;
		return;
	}
	if (figure->getPerimeter() <= 0)
	{
		cout << "Error: Figure perimeter must be greater than zero." << endl;
		return;
	}
	if (figure->getType().empty())
	{
		cout << "Error: Figure type cannot be empty." << endl;
		return;
	}
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->getName() == figure->getName())
		{
			cout << "Error: Figure with this name already exists." << endl;
			return;
		}
	}
	figures.push_back(figure);
}

void Database::findFigure(string name)
{
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->getName() == name)
		{
			cout << "Figure found: " << figures[i]->getName() << endl;
			cout << "Area: " << figures[i]->getArea() << endl;
			cout << "Perimeter: " << figures[i]->getPerimeter() << endl;
			cout << "Type: " << figures[i]->getType() << endl;
			return;
		}
	}
	cout << "Figure not found." << endl;
}

void Database::removeFigure(string name)
{
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->getName() == name)
		{
			delete figures[i];
			figures.erase(figures.begin() + i);
			break;
		}
	}
}

void Database::saveToFile(string filename)
{
	outFile.open(filename, ios::binary | ios::app);
	if (!outFile.is_open())
	{
		cout << "Error: Could not open file for writing." << endl;
		return;
	}

	for (int i = 0; i < figures.size(); i++)
	{
		size_t nameLength = figures[i]->getName().size();
		outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
		outFile.write(figures[i]->getName().c_str(), nameLength);

		double area = figures[i]->getArea();
		double perimeter = figures[i]->getPerimeter();
		outFile.write(reinterpret_cast<const char*>(&area), sizeof(area));
		outFile.write(reinterpret_cast<const char*>(&perimeter), sizeof(perimeter));

		size_t typeLength = figures[i]->getType().size();
		outFile.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
		outFile.write(figures[i]->getType().c_str(), typeLength);
	}

	outFile.close();
}

void Database::loadFromFile(string filename)
{
	inFile.open(filename, ios::binary);
	if (!inFile.is_open())
	{
		cout << "Error: Could not open file for reading." << endl;
		return;
	}

	while (!inFile.eof())
	{
		size_t nameLength;
		inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
		if (inFile.eof()) break;
		string name(nameLength, '\0');
		inFile.read(&name[0], nameLength);

		double area, perimeter;
		inFile.read(reinterpret_cast<char*>(&area), sizeof(area));
		inFile.read(reinterpret_cast<char*>(&perimeter), sizeof(perimeter));

		size_t typeLength;
		inFile.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
		string type(typeLength, '\0');
		inFile.read(&type[0], typeLength);

		Geometric_Figure* figure = new Geometric_Figure(name, area, perimeter, type);
		figures.push_back(figure);
	}
	inFile.close();
}

void Database::getTotalArea(string type)
{
	double totalArea = 0;
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->getType() == type)
		{
			totalArea += figures[i]->getArea();
		}
	}
	cout << "Total area of " << type << ": " << totalArea << endl;
}

void Database::getTotalPerimeter(double area)
{
	double totalPerimeter = 0;
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->getArea() > area)
		{
			totalPerimeter += figures[i]->getPerimeter();
		}
	}
	cout << "Total perimeter of figures with area greater than " << area << ": " << totalPerimeter << endl;
}

void Database::printExistingFigures()
{
	cout << "Existing figures: " << endl;
	for (int i = 0; i < figures.size(); i++)
	{
		cout << figures[i]->getName() << endl;
	}
}

Geometric_Figure* Database::findFigureName(string name)
{
	for (auto figure : figures)
	{
		if (figure->getName() == name)
		{
			return figure;
		}
	}
	return nullptr;
}