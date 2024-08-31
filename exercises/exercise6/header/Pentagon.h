#pragma once
#include "Shape.h"
#include "MathUtils.h"

class Pentagon : public Shape
{
public:
	Pentagon(std::string nam, std::string col, double side); // ctor
	void setSide(double side);
	double getSide() const; // add for the draw to work
	void draw(); // for the menu

private:
	double side;

};

