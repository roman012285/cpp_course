#include "Hexagon.h"
#include "ShapeException.h"
#include <iostream>

Hexagon::Hexagon(std::string nam, std::string col, double side) : Shape(nam, col)
{
	setSide(side);
}

void Hexagon::setSide(double side)
{
	if (side < 0)
	{
		throw ShapeException();
	}
	this->side = side;
}

double Hexagon::getSide() const
{
	return this->side;
}

void Hexagon::draw()
{
	std::cout << std::endl << "Color is " << getColor() << std::endl << "Name is " << getName() << std::endl << "side is " << getSide() << std::endl << "erea: " << MathUtils::CalHexagonArea(getSide()) << std::endl;
}
