#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	~Arrow() override;

	// Getters
	Point getSource() const;
	Point getDestination() const;

	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	// override functions if need (virtual + pure virtual)
	double getPerimeter() const override;
	double getArea() const override;
	void move(const Point& other) override;

private:
	Point _source;
	Point _destination;
};