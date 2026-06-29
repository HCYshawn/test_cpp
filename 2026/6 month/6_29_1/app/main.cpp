#include "mymath/math.h"

#include <iostream>

int main()
{
    std::cout << "3 + 4 = " << mymath::add(3, 4) << std::endl;
    std::cout << "3 - 4 = " << mymath::sub(3, 4) << std::endl;
    return 0;
}