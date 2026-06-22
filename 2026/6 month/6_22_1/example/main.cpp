#include <iostream>
#include <string>

#include "strutils/strutils.hpp"

int main()
{
    std::string text = "Hello CMake Level 3!";

    std::cout << "Original : " << text << std::endl;
    std::cout << "to_upper : " << strutils::to_upper(text) << std::endl;
    std::cout << "to_lower : " << strutils::to_lower(text) << std::endl;

    return 0;
}
