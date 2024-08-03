#include "Shape.h"
#include<iostream>

using std::cout;
using std::endl;

Shape::Shape(std::string name, std::string type)
:_name(name), _type(type) {}

Shape::~Shape() {}

std::string Shape::getType() const{
    return _type;
}

std::string Shape::getName() const{
    return _name;
}

void Shape::printDetails() const {
    std::cout << "Shape Name: " << _name << ", Shape Type: " << _type << std::endl;
}