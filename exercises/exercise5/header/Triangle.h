#include "Polygon.h"
#include <string>

class Triangle : public Polygon
{
public:
	
	// Constructor
	Triangle(Point a, Point b, Point c, std::string type, std::string name);

	// Destructor
	~Triangle();

	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;
	double getArea() const override;

	// override functions if need (virtual + pure virtual)
	std::vector<Point> getPoints() const override;

	double getPerimeter() const override;
	void move(const Point& other) override;

};