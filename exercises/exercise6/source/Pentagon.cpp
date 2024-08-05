#include "Pentagon.h"
#include "ShapeException.h"
#include <iostream>

Pentagon::Pentagon(std::string nam, std::string col, double side) : Shape(nam, col)
{
	setSide(side);
}

void Pentagon::setSide(double side)
{
	if (side < 0)
	{
		throw ShapeException();
	}
	this->side = side;
}

double Pentagon::getSide() const
{
	return this->side;
}

void Pentagon::draw()
{
	std::cout << std::endl << "Color is " << getColor() << std::endl << "Name is " << getName() << std::endl << "side is " << getSide() << std::endl << "erea: " << MathUtils::CalPentagonArea(getSide()) << std::endl;
}
