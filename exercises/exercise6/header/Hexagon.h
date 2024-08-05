#pragma once
#include "Shape.h"
#include "MathUtils.h"

class Hexagon : public Shape
{
public:
	Hexagon(std::string nam, std::string col, double side);
	void setSide(double side);
	double getSide() const; // add for the draw to work
	void draw(); // for the menu

private:
	double side;

};

