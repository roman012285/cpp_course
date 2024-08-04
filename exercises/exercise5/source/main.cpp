#include <iostream>
#include <vector>
#include "Shape.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Menu.h"

int main() {
    std::vector<Shape*> shapes;
    Menu menu;

    while (true) {
        int choice = menu.displayMainMenu();
        switch (choice) {
            case 1:
                menu.addShape(shapes);
                break;
            case 2:
                menu.modifyShape(shapes);
                break;
            case 3:
                menu.deleteAllShapes(shapes);
                break;
            case 4:
                menu.exitProgram(shapes);
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
    return 0;
}
