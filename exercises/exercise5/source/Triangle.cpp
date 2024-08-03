#include "Triangle.h"


Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name)
    : Polygon(type, name) {
    // Check if the points are collinear
    double area = a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getY() - a.getY()) +
                  c.getX() * (a.getY() - b.getY());
    
    if (area == 0) {
        exit(1);
    }

    // If the points form a valid triangle, add them to the _points vector
    _points.push_back(a);
    _points.push_back(b);
    _points.push_back(c);
}
Triangle::~Triangle() {}


void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}


double Triangle::getArea() const {
    // Using Heron's formula to calculate the area of the triangle
    double a = _points[0].distance(_points[1]);
    double b = _points[1].distance(_points[2]);
    double c = _points[2].distance(_points[0]);
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

std::vector<Point> Triangle::getPoints() const {
    return _points;
}

void Triangle::move(Point& other) {
    _points[0] += other;
	_points[1] += other;
	_points[1] += other;

}
