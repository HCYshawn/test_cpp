#include <iostream>
#include <typeinfo>

int main()
{
    auto ret = true + true;

    std::cout << "The value: " << ret << std::endl;
    std::cout<<"sizeof(ret): " << sizeof(ret) << std::endl;
    std::cout << "The type is: " << typeid(ret).name() << std::endl;

    return 0;
}