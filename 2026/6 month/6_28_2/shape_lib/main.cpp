#include "shape/shape.h"

#include <iostream>

int main()
{
    std::cout << "consumer circle area: "
              << shape::circle_area(2.0)
              << std::endl;

    std::cout << "consumer rectangle area: "
              << shape::rectangle_area(6.0, 7.0)
              << std::endl;

    return 0;
}