#include <iostream>
#include <cstdlib>
#include <new>

void *operator new(size_t size)
{
    std::cout << "全局 operator new 被调用 size = " << size << std::endl;
    void *p = malloc(size);
    if (!p)
    {
        throw std::bad_alloc();
    }
    return p;
}

void operator delete(void *p) noexcept
{
    std::cout << "全局 operator delete 被调用" << std::endl;
    free(p);
}

class test
{
public:
    test()
    {
        std::cout << "test 构造函数被调用" << std::endl;
    }
    ~test()
    {
        std::cout << "test 析构函数被调用" << std::endl;
    }
    static void *operator new(size_t size)
    {
        std::cout << "test类::operator new被调用 size = " << size << std::endl;
        return ::operator new(size);
    }
    static void operator delete(void *p) noexcept
    {
        std::cout << "test类::operator delete被调用" << std::endl;
        ::operator delete(p);
    }
};

int main()
{
    std::cout << "全局new/delete" << std::endl;
    int *p_int = new int(5);
    delete p_int;

    std::cout << "-------------------" << std::endl;
    std::cout << "类的new/delete" << std::endl;
    test *p_test = new test();
    delete p_test;

    return 0;
}