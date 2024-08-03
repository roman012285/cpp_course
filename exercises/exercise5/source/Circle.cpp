#include "Circle.h"

Circle::Circle(Point center, double radius, std::string type, std::string name)
:Shape(name, type), _center(center), _radius(radius) {
	if(radius < 0){
		exit(1);
	}
}

Circle::~Circle(){}

Point Circle::getCenter() const{
	return _center;
}

double Circle::getRadius() const{
	return _radius;
}


void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}


double Circle::getPerimeter() const {
	return 2*PI*_radius;
}

double Circle::getArea() const {
	return PI*_radius*_radius;
}

void Circle::move(const Point& other){
	_center += other;
}
