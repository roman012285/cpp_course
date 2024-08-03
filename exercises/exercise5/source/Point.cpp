#include "Point.h"
#include <cmath>

Point::Point()
: _x(0), _y(0) {};

Point::Point(double x, double y)
:_x(x), _y(y) {};

Point::~Point() {};

// that operator receives some Point reference and return a new Point
// object with the sum of coordinates according to the function implementation
Point Point::operator+(const Point& other) const {
    return Point(_x+other._x, _y+other._y);
}

// return the modified object and no new as previously
Point& Point::operator+=(const Point& other) {
    _x = _x + other._x;
    _y = _y + other._y;

    return *this;  // returns that object and not new as previously
}

double Point::getX() const {
    return this->_x;
}

double Point::getY() const {
    return this->_y;
}

double Point::distance(Point& other) const {
    double distance;
    distance = std::sqrt((_x-other._x) + (_y-other._y));

    return distance;
}