#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Geometric_Figure.h"
using namespace std;

class Database:
	public Geometric_Figure
{
private:
	vector<Geometric_Figure*> figures;
	ofstream outFile;
	ifstream inFile;
	string fileName;
public:
	Database();
	~Database();
	void addFigure(Geometric_Figure* figure);
	void findFigure(string name);
	Geometric_Figure* findFigureName(string name);
	void removeFigure(string name);
	void saveToFile(string filename);
	void loadFromFile(string filename);
	void getTotalArea(string type);
	void getTotalPerimeter(double area);
	void printExistingFigures();
};