#include "Arrow.h"
#include<iostream>

// by writing _source(a) it works because of the default copy constructor generated 
// by the compiler for example:
// Compiler-generated copy constructor
//    Point(const Point& other)
//        : _x(other._x), _y(other._y) {}
//
Arrow::Arrow(Point a, Point b, std::string type, std::string name)
	: Shape(name, type), _source(a), _destination(b) {
		if((a.getX()==b.getX() && (a.getY()==b.getY()))){
			std::cout << "Two identical points" << std::endl;
			exit(1);
		}
}  

Arrow::~Arrow() {}

Point Arrow::getSource() const{
	return _source;
}

Point Arrow::getDestination() const{
	return _destination;
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_source, _destination);
}

void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_source, _destination);
}

double Arrow::getPerimeter() const {
	return _source.distance(_destination);
}

double Arrow::getArea() const{
	return 0;
}

void Arrow::move(Point& other) {
    _source += other;
    _destination += other;
}