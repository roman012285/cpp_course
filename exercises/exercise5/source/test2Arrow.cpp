/*
#include "Arrow.h"
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

std::string getArrowInfo(const Arrow& a)
{
	return "Name = " + a.getName() + ", type = " + a.getType() + "\n" +
		"Perimeter = " + std::to_string(a.getPerimeter()) +
		", Area = " + std::to_string(a.getArea()) + "\n" +
		"Source = " + getPointInfo(a.getSource()) +
		" , Destination = " + getPointInfo(a.getDestination());
}

bool test2Arrow()
{
	bool result = false;

	try
	{
		// Tests Ex5 part 1 - Arrow

		set_console_color(LIGHT_PURPLE);
		cout <<
			"****************\n" <<
			"Test 2 - Arrow \n" <<
			"****************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing new Arrow object a1 with P1 = (0,0) , P2 = (13,14) ... \n" << endl;
		Arrow a1(Point(0, 0), Point(13, 14), "arrow", "a1");

		std::string expected = "Name = a1, type = arrow\n";
		expected += "Perimeter = 19.104973, Area = 0.000000\n";
		expected += "Source = [X = 0.000000, Y = 0.000000] , Destination = [X = 13.000000, Y = 14.000000]";
		std::string got = getArrowInfo(a1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Arrow information is not as expected\n" <<
				"Check constructor Arrow::Arrow(Point, Point, string, string) and functions\n" <<
				"Arrow::getArea(), Arrow::getPerimeter()\n" <<
				"Arrow::getSource(), Arrow::getDestination()\n" <<
				"Shape::getName(), Shape::getType()";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Arrow a1.move(10,10) ... \n" << endl;

		a1.move(Point(10, 10));
		expected = "Name = a1, type = arrow\n";
		expected += "Perimeter = 19.104973, Area = 0.000000\n";
		expected += "Source = [X = 10.000000, Y = 10.000000] , Destination = [X = 23.000000, Y = 24.000000]";
		got = getArrowInfo(a1);
		cout << "Expected\n" << expected << endl;
		cout << "Got\n" << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Arrow information is not as expected\n" <<
				"check function Arrow::move()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nMoving Arrow a1.move(-15,-120) ... \n" << endl;

		a1.move(Point(-15, -120));
		expected = "Name = a1, type = arrow\n";
		expected += "Perimeter = 19.104973, Area = 0.000000\n";
		expected += "Source = [X = -5.000000, Y = -110.000000] , Destination = [X = 8.000000, Y = -96.000000]";
		got = getArrowInfo(a1);
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
	cout << "\n########## Arrow - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"########################\n" <<
		"Exercise 5 - Shapes\n" <<
		"Part 1 - Arrow\n" <<
		"########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test2Arrow();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex5 Arrow Tests Passed!!! ##########" << "\n\n";
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