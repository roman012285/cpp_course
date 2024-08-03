/*
#include "Point.h"
#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <string>

using std::cout;
using std::endl;

#define GREEN 2
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

bool test1Point()
{
	bool result = false;

	try
	{
		// Tests Ex5 part 1 - Point

		set_console_color(TEAL);
		cout <<
			"****************\n" <<
			"Test 1 - Point \n" <<
			"****************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Initializing new Point object p1 ... \n" << endl;
		Point p1;

		std::string expected = "[X = 0.000000, Y = 0.000000]";
		std::string got = getPointInfo(p1);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check default constructor Point::Point()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing new Point object p2 with X=10 , Y=10 ... \n" << endl;

		Point p2(10, 10);
		expected = "[X = 10.000000, Y = 10.000000]";
		got = getPointInfo(p2);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check constructor Point::Point(double,double)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling p1.distance(p2) ... \n" << endl;

		expected = "14.142136";
		got = std::to_string(p1.distance(p2));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::distance()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing new Point object p3 with X=-15 , Y=12 ... \n" << endl;

		Point p3(-15, 12);
		expected = "[X = -15.000000, Y = 12.000000]";
		got = getPointInfo(p3);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check constructor Point::Point(double,double)\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing operator + p2 + p3 ... \n" << endl;

		const Point presult = p2 + p3;

		expected = "[X = -5.000000, Y = 22.000000]";
		got = getPointInfo(presult);;
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::operator+\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling p2.distance(p3) ... \n" << endl;

		expected = "25.079872";
		got = std::to_string(p2.distance(p3));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::distance()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nInitializing new Point object p4 with X=-6 , Y=-8 ... \n" << endl;

		Point p4(-6, -8);
		expected = "[X = -6.000000, Y = -8.000000]";
		got = getPointInfo(p4);
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check constructor Point::Point(double,double)\n";
			set_console_color(WHITE);
			return false;
		}
		
		cout <<
			"\nCalling p4.distance(p1) ... \n" << endl;

		expected = "10.000000";
		got = std::to_string(p4.distance(p1));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::distance()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling p4.distance(p2) ... \n" << endl;

		expected = "24.083189";
		got = std::to_string(p4.distance(p2));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::distance()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing operator += p3 += p1 ... \n" << endl;

		p3 += p1;

		expected = "[X = -15.000000, Y = 12.000000]";
		got = getPointInfo(p3);;
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::operator+\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nUsing operator += p3 += p3 ... \n" << endl;

		p3 += p3;

		expected = "[X = -30.000000, Y = 24.000000]";
		got = getPointInfo(p3);;
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Point information is not as expected\n" <<
				"check function Point::operator+\n";
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
	cout << "\n########## Point - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"########################\n" <<
		"Exercise 5 - Shapes\n" <<
		"Part 1 - Point\n" <<
		"########################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test1Point();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex5 Point Tests Passed!!! ##########" << "\n\n";
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
