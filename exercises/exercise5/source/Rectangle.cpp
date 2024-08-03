#include "Rectangle.h"
#include <iostream>

namespace myShapes {
    // Constructor
    Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name)
        : Polygon(type, name), _length(length), _width(width) {
        _points.push_back(a); // Top-left corner
        _points.push_back(Point(a.getX() + length, a.getY())); // Top-right corner
        _points.push_back(Point(a.getX() + length, a.getY() + width)); // Bottom-right corner
        _points.push_back(Point(a.getX(), a.getY() + width)); // Bottom-left corner
    }

    // Destructor
    Rectangle::~Rectangle() {}

    // Methods
    void Rectangle::draw(const Canvas& canvas) {
        canvas.draw_rectangle(_points[0], _points[2]); // Drawing using top-left and bottom-right
    }

    void Rectangle::clearDraw(const Canvas& canvas) {
        canvas.clear_rectangle(_points[0], _points[2]); // Clearing using top-left and bottom-right
    }

    double Rectangle::getArea() const {
        return _length * _width;
    }

    double Rectangle::getPerimeter() const {
        return 2 * (_length + _width);
    }

    void Rectangle::move(Point& other) {
        for (auto& point : _points) {
            point += other;
        }
    }

    std::vector<Point> Rectangle::getPoints() const {
        return _points;
    }
}
