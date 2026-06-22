#include <iostream>
#include "shape/shape.h"

int main()
{
    double r = 3.0;
    double w = 5.0;
    double h = 8.0;

    std::cout << "Circle area (r=" << r << "): "
              << shape::circleArea(r) << std::endl;
    std::cout << "Rectangle area (" << w << "x" << h << "): "
              << shape::rectangleArea(w, h) << std::endl;

    return 0;
}
