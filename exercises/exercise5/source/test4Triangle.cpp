/*
#include "Triangle.h"
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

std::string getTrianglePoints(const std::vector<Point>& points)
{
	return "{" + getPointInfo(points[0]) + ", " + getPointInfo(points[1]) + ", " + getPointInfo(points[2]) + "}";
}

std::string getTriangleInfo(const Triangle& t)
{
	return "Name = " + t.getName() + ", type = " + t.getType() + "\n" +
		"Perimeter = " + std::to_string(t.getPerimeter()) +
		", Area = " + std::to_string(t.getArea()) + "\n"
		"Points: " + getTrianglePoints(t.getPoints());
}

bool test4Triangle()
{
	bool result = false;

	try
	{
		// Tests Ex5 part 1 - Triangle

		set_console_color(LIGHT_BLUE);
		cout <<
			"*******************\n" <<
			"Test 4 - Triangle \n" <<
			"*******************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing new Triangle object t1 with P1 = (12,-11) , P2 = (33,44), P3 = (-18,91) ... \n" << endl;
		Triangle t1(Point(12, -11), Point(33, 44), Point(-18, 91), "triangle", "t1");

		std::string expected = "Name = t1, type = triangle\n";
		expected += "Perimeter = 234.547179, Area = 1896.000000\n";
		expected += "Points: {[X = 12.000000, Y = -11.000000], [X = 33.000000, Y = 44.000000], [X = -18.000000, Y = 91.000000]}";
		std::string got = getTriangleInfo(t1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Triangle information is not as expected\n" <<
				"Check constructor Triangle::Triangle(Point, Point, Point, string, string) and functions\n" <<
				"Triangle::getArea(), Triangle::getPerimeter()\n" <<
				"Shape::getName(), Shape::getType()";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Triangle t1.move(100,100) ... \n" << endl;

		t1.move(Point(100, 100));
		expected = "Name = t1, type = triangle\n";
		expected += "Perimeter = 234.547179, Area = 1896.000000\n";
		expected += "Points: {[X = 112.000000, Y = 89.000000], [X = 133.000000, Y = 144.000000], [X = 82.000000, Y = 191.000000]}";
		got = getTriangleInfo(t1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Triangle information is not as expected\n" <<
				"check function Triangle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Triangle a1.move(-50,-220) ... \n" << endl;

		t1.move(Point(-50, -220));
		expected = "Name = t1, type = triangle\n";
		expected += "Perimeter = 234.547179, Area = 1896.000000\n";
		expected += "Points: {[X = 62.000000, Y = -131.000000], [X = 83.000000, Y = -76.000000], [X = 32.000000, Y = -29.000000]}";
		got = getTriangleInfo(t1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Triangle information is not as expected\n" <<
				"check function Triangle::move()\n";
			set_console_color(WHITE);
			return false;
		}

		// #########################
		// #  pythagorean triplet  #
		// #     < 3 , 4 , 5 >     #
		// #########################

		cout <<
			"\nInitializing new Triangle object t2 with P1 = (0,0) , P2 = (3,0), P3 = (0,4) ... \n" << endl;
		Triangle t2(Point(0, 0), Point(3, 0), Point(0, 4), "triangle", "t2");

		expected = "Name = t2, type = triangle\n";
		expected += "Perimeter = 12.000000, Area = 6.000000\n";
		expected += "Points: {[X = 0.000000, Y = 0.000000], [X = 3.000000, Y = 0.000000], [X = 0.000000, Y = 4.000000]}";
		got = getTriangleInfo(t2);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Triangle information is not as expected\n" <<
				"Check constructor Triangle::Triangle(Point, Point, Point, string, string) and functions\n" <<
				"Triangle::getArea(), Triangle::getPerimeter()\n" <<
				"Shape::getName(), Shape::getType()";
			set_console_color(WHITE);
			return false;
		}

		// #########################
		// #  pythagorean triplet  #
		// #     < 5 , 12 , 13 >     #
		// #########################

		cout <<
			"\nInitializing new Triangle object t3 with P1 = (0,0) , P2 = (-12,0), P3 = (0,-5) ... \n" << endl;
		Triangle t3(Point(0, 0), Point(-12, 0), Point(0, -5), "triangle", "t3");

		expected = "Name = t3, type = triangle\n";
		expected += "Perimeter = 30.000000, Area = 30.000000\n";
		expected += "Points: {[X = 0.000000, Y = 0.000000], [X = -12.000000, Y = 0.000000], [X = 0.000000, Y = -5.000000]}";
		got = getTriangleInfo(t3);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Triangle information is not as expected\n" <<
				"Check constructor Triangle::Triangle(Point, Point, Point, string, string) and functions\n" <<
				"Triangle::getArea(), Triangle::getPerimeter()\n" <<
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
	cout << "\n########## Triangle - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"########################\n" <<
		"Exercise 5 - Shapes\n" <<
		"Part 1 - Triangle\n" <<
		"########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test4Triangle();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex5 Triangle Tests Passed!!! ##########" << "\n\n";
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
