#include <iostream>
#include "shape/shape.h"

int main()
{
    double radius = 5.0;
    double width  = 4.0;
    double height = 6.0;

    std::cout << "=== Shape Library Demo ===" << std::endl;
    std::cout << "Circle area (r=" << radius << "): "
              << shape::circleArea(radius) << std::endl;
    std::cout << "Rectangle area (" << width << "x" << height << "): "
              << shape::rectangleArea(width, height) << std::endl;

    return 0;
}
