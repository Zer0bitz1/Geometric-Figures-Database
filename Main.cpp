#include <iostream>
#include <vector>
#include "Geometric_Figure.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Menu.h"
#include "Database.h"
using namespace std;

int main()
{
	int userChoice;
	Database* db{};
	Menu menu;
	do
	{
		menu.DisplayMenu();
		userChoice = menu.getUserChoice();
		switch (userChoice)
		{
		case 1: 
		{
			int dbUserChoice;
			Menu dbMenu;
			do
			{
				dbMenu.DisplayDatabaseMenu();
				dbUserChoice = dbMenu.getUserChoice();
				switch (dbUserChoice)
				{
				case 1:
					if (db == NULL)
					{
						db = new Database();
						cout << "Database created." << endl;
					}
					else
					{
						cout << "Error: Database already exists." << endl;
					}
					break;
				case 2:
					if (db != NULL)
					{
						string filename;
						cout << "Enter filename to save: ";
						cin >> filename;
						db->saveToFile(filename);
						cout << "Data saved to database." << endl;
					}
					else
					{
						cout << "Error: No database exists. Please create a database first." << endl;
					}
					break;
				case 3:
					if (db != NULL)
					{
						string filename;
						cout << "Enter filename to load: ";
						cin >> filename;
						db->loadFromFile(filename);
						cout << "Data loaded from database." << endl;
					}
					else
					{
						cout << "Error: No database exists. Please create a database first." << endl;
					}
					break;
				case 4:
					if (db != NULL)
					{
						delete db;
						db = NULL;
						cout << "Database reset." << endl;
					}
					else
					{
						cout << "Error: No database exists. Please create a database first." << endl;
					}
					break;
				case 5:
				{
					cout << "Back" << endl;
					break;
				}
				default:
					cout << "Invalid option!" << endl;
					break;
				}
			} while (dbUserChoice != 5);
			break;
		}
		case 2:
		{
			if (db == NULL)
			{
				cout << "Error: No database exists. Please create a database first." << endl;
				break;
			}
			int subUserChoice;
			Menu subMenu;
			do
			{
				subMenu.DisplaySubMenu();
				subUserChoice = subMenu.getUserChoice();
				switch (subUserChoice)
				{
				case 1:
				{
					string name;
					double height, base, a, b, area, perim;

					cout << "Write name: ";
					cin >> name;
					cout << "Write height: ";
					cin >> height;
					cout << "Write base: ";
					cin >> base;
					cout << "Write side A: ";
					cin >> a;
					cout << "Write side B: ";
					cin >> b;

					area = (base * height) / 2;
					perim = a + b + base;

					Triangle* tri = new Triangle(name, area, perim, height, base, a, b);

					db->addFigure(tri);
					cout << "Triangle added to database." << endl;
					break;
				}
				case 2:
				{
					string name;
					double height, width, area, perim;

					cout << "Write name: ";
					cin >> name;
					cout << "Write height: ";
					cin >> height;
					cout << "Write width: ";
					cin >> width;

					area = height * width;
					perim = 2 * (height + width);

					Rectangle* rec = new Rectangle(name, area, perim, height, width);

					db->addFigure(rec);
					cout << "Rectangle added to database." << endl;
					break;
				}
				case 3:
				{
					string name;
					int sides;
					double side_length, area, perim;

					cout << "Write name: ";
					cin >> name;
					cout << "Write number of sides: ";
					cin >> sides;
					cout << "Write side length: ";
					cin >> side_length;


					area = (sides * side_length * side_length) / (4 * tan(3.14 / sides));
					perim = sides * side_length;

					Polygon* poly = new Polygon(name, area, perim, sides, side_length);
					db->addFigure(poly);
					cout << "Polygon added to database." << endl;
					break;
				}
				case 4:
				{
					string name;
					double radius, area, perim;

					cout << "Write name: ";
					cin >> name;
					cout << "Write radius: ";
					cin >> radius;
					area = 3.14 * radius * radius;
					perim = 2 * 3.14 * radius;

					Circle* cir = new Circle(name, area, perim, radius);

					db->addFigure(cir);
					cout << "Circle added to database." << endl;
					break;
				}
				case 5:
				{
					cout << "Back" << endl;
					break;
				}
				default:
					cout << "Invalid option!" << endl;
					break;
				}
			} while (subUserChoice != 5);
			break;
		}
		case 3:
		{
			if (db == NULL)
			{
				cout << "Error: No database exists. Please create a database first." << endl;
				break;
			}
			db->printExistingFigures();
			string name;
			cout << "Enter the name of the figure to find: ";
			cin >> name;
			db->findFigure(name);
			break;
		}
		case 4:
		{
			if (db == NULL)
			{
				cout << "Error: No database exists. Please create a database first." << endl;
				break;
			}
			string type;
			cout << "Enter the type of figure (Triangle, Rectangle, Polygon, Circle): ";
			cin >> type;
			db->getTotalArea(type);
			break;
		}
		case 5:
		{
			if (db == NULL)
			{
				cout << "Error: No database exists. Please create a database first." << endl;
				break;
			}
			double area;
			cout << "Enter the area threshold: ";
			cin >> area;
			db->getTotalPerimeter(area);
			break;
		}
		case 6:
		{
			if (db == NULL)
			{
				cout << "Error: No database exists. Please create a database first." << endl;
				break;
			}
			db->printExistingFigures();
			string name;
			cout << "Enter the name of the figure to visualize: ";
			cin >> name;
			Geometric_Figure* figure = db->findFigureName(name);
			if (figure != NULL)
			{
				if (figure->getType() == "Triangle")
				{
					Triangle* tri = dynamic_cast<Triangle*>(figure);
					tri->visualizeTri();
				}
				else if (figure->getType() == "Rectangle")
				{
					Rectangle* rec = dynamic_cast<Rectangle*>(figure);
					rec->visualizeRec();
				}
				else if (figure->getType() == "Polygon")
				{
					Polygon* poly = dynamic_cast<Polygon*>(figure);
					poly->visualizePoly();
				}
				else if (figure->getType() == "Circle")
				{
					Circle* cir = dynamic_cast<Circle*>(figure);
					cir->visualizeCir();
				}
			}
			break;
		}
		case 7:
		{
			if (db == NULL)
			{
				cout << "Error: No database exists. Please create a database first." << endl;
				break;
			}
			db->printExistingFigures();
			string name;
			cout << "Enter the name of the figure to remove: ";
			cin >> name;
			db->removeFigure(name);
			cout << "Figure removed from database." << endl;
			break;
		}
		case 8:
		{
			break;
		}
		default:
			cout << "Invalid option!" << endl;
			break;
		}
	} while (userChoice != 8);
	return 0;
}