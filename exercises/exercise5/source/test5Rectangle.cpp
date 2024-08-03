/*
#include "Rectangle.h"
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

std::string getRectanglePoints(const std::vector<Point>& points)
{
	return "{" + getPointInfo(points[0]) + ", " + getPointInfo(points[1]) +
		",\n\t" + getPointInfo(points[2]) + ", " + getPointInfo(points[3]) + "}";
}

std::string getRectangleInfo(const myShapes::Rectangle& r)
{
	return "Name = " + r.getName() + ", type = " + r.getType() + "\n" +
		"Perimeter = " + std::to_string(r.getPerimeter()) +
		", Area = " + std::to_string(r.getArea()) + "\n"
		"Points:\n\t" + getRectanglePoints(r.getPoints());
}

bool test5Rectangle()
{
	bool result = false;

	try
	{
		// Tests Ex5 part 1 - Rectangle

		set_console_color(PURPLE);
		cout <<
			"*******************\n" <<
			"Test 5 - Rectangle \n" <<
			"*******************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing new Rectangle object r1 with P1 = (0,0) , Length = 134 , Width = 185 ... \n" << endl;
		myShapes::Rectangle r1(Point(0, 0), 134, 185, "rectangle", "r1");

		std::string expected = "Name = r1, type = rectangle\n";
		expected += "Perimeter = 638.000000, Area = 24790.000000\n";
		expected += "Points:\n";
		expected += "\t{[X = 0.000000, Y = 0.000000], [X = 134.000000, Y = 0.000000],\n";
		expected += "\t[X = 134.000000, Y = 185.000000], [X = 0.000000, Y = 185.000000]}";

		std::string got = getRectangleInfo(r1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Rectangle information is not as expected\n" <<
				"Check constructor Rectangle::Rectangle(Point, Point, Point, string, string) and functions\n" <<
				"Rectangle::getArea(), Rectangle::getPerimeter()\n" <<
				"Shape::getName(), Shape::getType()";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Rectangle r1.move(100,100) ... \n" << endl;

		r1.move(Point(100, 100));
		expected = "Name = r1, type = rectangle\n";
		expected += "Perimeter = 638.000000, Area = 24790.000000\n";
		expected += "Points:\n";
		expected += "\t{[X = 100.000000, Y = 100.000000], [X = 234.000000, Y = 100.000000],\n";
		expected += "\t[X = 234.000000, Y = 285.000000], [X = 100.000000, Y = 285.000000]}";
		got = getRectangleInfo(r1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Rectangle information is not as expected\n" <<
				"check function Rectangle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Rectangle a1.move(-350,-320) ... \n" << endl;

		r1.move(Point(-350, -320));
		expected = "Name = r1, type = rectangle\n";
		expected += "Perimeter = 638.000000, Area = 24790.000000\n";
		expected += "Points:\n";
		expected += "\t{[X = -250.000000, Y = -220.000000], [X = -116.000000, Y = -220.000000],\n";
		expected += "\t[X = -116.000000, Y = -35.000000], [X = -250.000000, Y = -35.000000]}";
		got = getRectangleInfo(r1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Rectangle information is not as expected\n" <<
				"check function Rectangle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"Initializing new Rectangle object r2 with P1 = (56,-100) , Length = 150 , Width = 250 ... \n" << endl;
		myShapes::Rectangle r2(Point(56, -100), 150, 250, "rectangle", "r2");

		expected = "Name = r2, type = rectangle\n";
		expected += "Perimeter = 800.000000, Area = 37500.000000\n";
		expected += "Points:\n";
		expected += "\t{[X = 56.000000, Y = -100.000000], [X = 206.000000, Y = -100.000000],\n";
		expected += "\t[X = 206.000000, Y = 150.000000], [X = 56.000000, Y = 150.000000]}";

		got = getRectangleInfo(r2);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Rectangle information is not as expected\n" <<
				"Check constructor Rectangle::Rectangle(Point, Point, Point, string, string) and functions\n" <<
				"Rectangle::getArea(), Rectangle::getPerimeter()\n" <<
				"Shape::getName(), Shape::getType()";
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
	cout << "\n########## Rectangle - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"########################\n" <<
		"Exercise 5 - Shapes\n" <<
		"Part 1 - Rectangle\n" <<
		"########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test5Rectangle();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex5 Rectangle Tests Passed!!! ##########" << "\n\n";
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
