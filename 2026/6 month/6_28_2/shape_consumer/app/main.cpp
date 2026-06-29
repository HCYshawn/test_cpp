#include "shape/shape.h"

#include <iostream>

int main()
{
    std::cout << "circle area: " << shape::circle_area(3.0) << std::endl;
    std::cout << "rectangle area: " << shape::rectangle_area(4.0, 5.0) << std::endl;
    return 0;
}