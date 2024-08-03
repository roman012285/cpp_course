/*
#include "Circle.h"
#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <string>

using std::cout;
using std::endl;

#define GREEN 2
#define BLUE 3
#define DARK_RED 4
#define PURPLE 5
#define YELLOW 6
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define TEAL 11
#define RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define WHITE 15

void set_console_color(unsigned int color)
{
	// colors are 0=black 1=blue 2=green and so on to 15=white
	// colorattribute = foreground + background * 16
	// to get red text on yellow use 4 + 14*16 = 228
	// light red on yellow would be 12 + 14*16 = 236
	// a Dev-C++ tested console application by vegaseat 07nov2004

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

std::string getPointInfo(const Point& p)
{
	return "[X = " + std::to_string(p.getX()) + ", Y = " + std::to_string(p.getY()) + "]";
}

std::string getCircleInfo(const Circle& c)
{
	return "Name = " + c.getName() + ", type = " + c.getType() + "\n" +
		"Center = " + getPointInfo(c.getCenter()) +
		", Radius = " + std::to_string(c.getRadius()) + "\n" +
		"Perimeter = " + std::to_string(c.getPerimeter()) +
		", Area = " + std::to_string(c.getArea());
}

bool test3Circle()
{
	bool result = false;

	try
	{
		// Tests Ex5 part 1 - Circle

		set_console_color(BLUE);
		cout <<
			"****************\n" <<
			"Test 3 - Circle \n" <<
			"****************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing new Circle object c1 with Radius = 7 , Center = (5,7) ... \n" << endl;
		Circle c1(Point(5, 7), 7, "circle", "c1");

		std::string expected = "Name = c1, type = circle\n";
		expected += "Center = [X = 5.000000, Y = 7.000000], Radius = 7.000000\n";
		expected += "Perimeter = 43.960000, Area = 153.860000";
		std::string got = getCircleInfo(c1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Circle information is not as expected\n" <<
				"Check constructor Circle::Circle(Point, double, string, string) and functions\n" <<
				"Circle::getArea(), Circle::getPerimeter(), Circle::getCenter(), Circle::getRadius()\n" <<
				"Shape::getName(), Shape::getType()";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Circle c1.move(10,10) ... \n" << endl;

		c1.move(Point(10, 10));
		expected = "Name = c1, type = circle\n";
		expected += "Center = [X = 15.000000, Y = 17.000000], Radius = 7.000000\n";
		expected += "Perimeter = 43.960000, Area = 153.860000";
		got = getCircleInfo(c1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Circle information is not as expected\n" <<
				"check function Circle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Circle c1.move(-20,-14) ... \n" << endl;

		c1.move(Point(-20, -14));
		expected = "Name = c1, type = circle\n";
		expected += "Center = [X = -5.000000, Y = 3.000000], Radius = 7.000000\n";
		expected += "Perimeter = 43.960000, Area = 153.860000";
		got = getCircleInfo(c1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Circle information is not as expected\n" <<
				"check function Circle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing new Circle object c1 with Radius = 25 , Center = (-100,34) ... \n" << endl;
		Circle c2(Point(-100, 34), 25, "circle", "c2");

		expected = "Name = c2, type = circle\n";
		expected += "Center = [X = -100.000000, Y = 34.000000], Radius = 25.000000\n";
		expected += "Perimeter = 157.000000, Area = 1962.500000";
		got = getCircleInfo(c2);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Circle information is not as expected\n" <<
				"Check constructor Circle::Circle(Point, double, string, string) and functions\n" <<
				"Circle::getArea(), Circle::getPerimeter(), Circle::getCenter(), Circle::getRadius()\n" <<
				"Shape::getName(), Shape::getType()";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Circle c1.move(101,-34) ... \n" << endl;

		c2.move(Point(101, -34));
		expected = "Name = c2, type = circle\n";
		expected += "Center = [X = 1.000000, Y = 0.000000], Radius = 25.000000\n";
		expected += "Perimeter = 157.000000, Area = 1962.500000";
		got = getCircleInfo(c2);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Circle information is not as expected\n" <<
				"check function Circle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Circle c1.move(150,200) ... \n" << endl;

		c2.move(Point(150, 200));
		expected = "Name = c2, type = circle\n";
		expected += "Center = [X = 151.000000, Y = 200.000000], Radius = 25.000000\n";
		expected += "Perimeter = 157.000000, Area = 1962.500000";
		got = getCircleInfo(c2);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Circle information is not as expected\n" <<
				"check function Circle::move()\n";
			set_console_color(WHITE);
			return false;
		}

	}
	catch (...)
	{
		set_console_color(RED);
		std::cerr << "Test crashed" << endl;
		std::cout << "FAILED: The program crashed, check the following things:\n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
			"3. Did you remember to initialize array before accessing it?";
		set_console_color(WHITE);
		return false;
	}

	set_console_color(LIGHT_GREEN);
	cout << "\n########## Circle - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"########################\n" <<
		"Exercise 5 - Shapes\n" <<
		"Part 1 - Circle\n" <<
		"########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test3Circle();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex5 Circle Tests Passed!!! ##########" << "\n\n";
		set_console_color(WHITE);
	}
	else
	{
		set_console_color(DARK_RED);
		std::cout << "\n########## TEST Failed :( ##########\n";
		set_console_color(WHITE);
	}
	return testResult ? 0 : 1;
}

*/
