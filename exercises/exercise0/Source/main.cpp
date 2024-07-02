#include "add.h"
#include <iostream>

int main(){

    int x, y;

    std::cout << "enter first number :" << std::endl;
    std::cin >> x;

    std::cout << "enter second number :" << std::endl;
    std::cin >> y;

    std::cout << "The result is : " << add(x,y) << std::endl;

    system("pause");
    
    return 0;
}