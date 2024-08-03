#include "Menu.h"
#include "Shape.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Point.h"
#include "Canvas.h"
#include <iostream>
#include <vector>
#include <string>

using namespace myShapes;

int Menu::displayMainMenu() {
    int choice;
    std::cout << "1. Add a shape" << std::endl;
    std::cout << "2. Modify a shape" << std::endl;
    std::cout << "3. Delete all shapes" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

void Menu::addShape(std::vector<Shape*>& shapes) {
    std::string shapeType, name;
    std::cout << "Enter the type of shape (arrow, triangle, circle, rectangle): ";
    std::cin >> shapeType;
    std::cout << "Enter the name of the shape: ";
    std::cin >> name;

    Shape* shape = nullptr;

    if (shapeType == "arrow") {
        Point a, b;
        double ax, ay, bx, by;
        std::cout << "Enter point A (x y): ";
        std::cin >> ax >> ay;
        std::cout << "Enter point B (x y): ";
        std::cin >> bx >> by;
        a = Point(ax, ay);
        b = Point(bx, by);
        shape = new Arrow(a, b, "arrow", name);
    } else if (shapeType == "triangle") {
        Point a, b, c;
        double ax, ay, bx, by, cx, cy;
        std::cout << "Enter point A (x y): ";
        std::cin >> ax >> ay;
        std::cout << "Enter point B (x y): ";
        std::cin >> bx >> by;
        std::cout << "Enter point C (x y): ";
        std::cin >> cx >> cy;
        a = Point(ax, ay);
        b = Point(bx, by);
        c = Point(cx, cy);
        shape = new Triangle(a, b, c, "triangle", name);
    } else if (shapeType == "circle") {
        Point center;
        double cx, cy, radius;
        std::cout << "Enter center point (x y): ";
        std::cin >> cx >> cy;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        center = Point(cx, cy);
        shape = new Circle(center, radius, "circle", name);
    } else if (shapeType == "rectangle") {
        Point a;
        double ax, ay, length, width;
        std::cout << "Enter point A (x y): ";
        std::cin >> ax >> ay;
        std::cout << "Enter length: ";
        std::cin >> length;
        std::cout << "Enter width: ";
        std::cin >> width;
        a = Point(ax, ay);
        shape = new myShapes::Rectangle(a, length, width, "rectangle", name); // Fully qualified name
    } else {
        std::cout << "Unknown shape type." << std::endl;
        return;
    }

    shapes.push_back(shape);
    Canvas canvas; // Assuming you have a canvas object to draw on
    shape->draw(canvas);
    std::cout << shapeType << " added and drawn." << std::endl;
}

void Menu::modifyShape(std::vector<Shape*>& shapes) {
    if (shapes.empty()) {
        std::cout << "No shapes to modify." << std::endl;
        return;
    }

    int index;
    std::cout << "Enter the index of the shape to modify: ";
    std::cin >> index;

    if (index < 0 || index >= shapes.size()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    Shape* shape = shapes[index];
    int action;
    std::cout << "1. Move shape" << std::endl;
    std::cout << "2. Get shape information" << std::endl;
    std::cout << "3. Remove shape" << std::endl;
    std::cout << "Enter your action: ";
    std::cin >> action;

    Canvas canvas; // Assuming you have a canvas object to draw on

    switch (action) {
        case 1: {
            double dx, dy;
            std::cout << "Enter new position offset (dx dy): ";
            std::cin >> dx >> dy;
            Point offset(dx, dy);
            shape->move(offset);
            shape->draw(canvas);
            break;
        }
        case 2:
            std::cout << "Shape information: " << std::endl;
            std::cout << "Name: " << shape->getName() << std::endl;
            std::cout << "Type: " << shape->getType() << std::endl;
            std::cout << "Perimeter: " << shape->getPerimeter() << std::endl;
            std::cout << "Area: " << shape->getArea() << std::endl;
            break;
        case 3:
            shape->clearDraw(canvas);
            delete shape;
            shapes.erase(shapes.begin() + index);
            std::cout << "Shape removed." << std::endl;
            break;
        default:
            std::cout << "Invalid action." << std::endl;
    }
}

void Menu::deleteAllShapes(std::vector<Shape*>& shapes) {
    Canvas canvas; // Assuming you have a canvas object to draw on
    for (Shape* shape : shapes) {
        shape->clearDraw(canvas);
        delete shape;
    }
    shapes.clear();
    std::cout << "All shapes deleted." << std::endl;
}

void Menu::exitProgram(std::vector<Shape*>& shapes) {
    deleteAllShapes(shapes);
    std::cout << "Exiting program." << std::endl;
}
