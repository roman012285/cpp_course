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
	virtual std::vector<Point> getPoints() const = 0;

	// override functions if need (virtual + pure virtual)
	virtual double getPerimeter() const override = 0;
	virtual void move(Point& other) override = 0;

protected:
	std::vector<Point> _points;
};