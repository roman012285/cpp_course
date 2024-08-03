#pragma once

#include "Polygon.h"

namespace myShapes {
    // Calling it MyRectangle because Rectangle is taken by global namespace.
    class Rectangle : public Polygon {
    public:
        // Constructor
        // Only the top-left corner is needed along with length and width
        Rectangle(Point a, double length, double width, std::string type, std::string name);

        // Destructor
        ~Rectangle() override;

        // Methods
        void draw(const Canvas& canvas) override;
        void clearDraw(const Canvas& canvas) override;
        double getArea() const override;
        double getPerimeter() const override;
        void move(Point& other) override;
        std::vector<Point> getPoints() const override;

    private:
        double _length;
        double _width;
    };
}
