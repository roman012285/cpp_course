#pragma once

#include "Shape.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(std::string type, std::string name);

	// Destructor
	~Polygon() override;

	// Methods

	// Getters
	std::vector<Point> getPoints() const;

	// override functions if need (virtual + pure virtual)
	double getPerimeter() const override;
	void move(Point& other) override;

protected:
	std::vector<Point> _points;
};