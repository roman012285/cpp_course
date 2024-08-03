#pragma once

#include <vector>
#include "Shape.h"

class Menu {
public:
    int displayMainMenu();
    void addShape(std::vector<Shape*>& shapes);
    void modifyShape(std::vector<Shape*>& shapes);
    void deleteAllShapes(std::vector<Shape*>& shapes);
    void exitProgram(std::vector<Shape*>& shapes);
};

