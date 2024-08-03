#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	~Circle() override;

	// Getters
	Point getCenter() const;
	double getRadius() const;

	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;
	double getPerimeter() const override;
	double getArea() const override;
	void move(Point& other) override;

	// add fields
private:
	Point _center;
	Point _double;

};