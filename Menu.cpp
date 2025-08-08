#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::DisplayMenu()
{
	cout << "1. Database operations" << endl;
	cout << "2. Add figure" << endl;
	cout << "3. Find figure by name" << endl;
	cout << "4. Total area of a figure type" << endl;
	cout << "5. Total perimeter of figures which have an area bigger than a certain value" << endl;
	cout << "6. Visualize figure" << endl;
	cout << "7. Remove figure" << endl;
	cout << "8. Quit" << endl;
}

int Menu::getUserChoice()
{
	int choice;
	cout << "Please write your option: ";
	cin >> choice;
	return choice;
}

void Menu::DisplaySubMenu() 
{
	cout << "1. Create triangle" << endl;
	cout << "2. Create rectangle" << endl;
	cout << "3. Create polygon" << endl;
	cout << "4. Create circle" << endl;
	cout << "5. Back" << endl;
}

void Menu::DisplayDatabaseMenu()
{
	cout << "1. Create database" << endl;
	cout << "2. Save to database" << endl;
	cout << "3. Load from database" << endl;
	cout << "4. Reset database" << endl;
	cout << "5. Back" << endl;
}