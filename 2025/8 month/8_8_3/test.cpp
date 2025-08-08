#include <iostream>
#include <cstdlib>
#include <new>

class test
{
private:
    static int count;
    int id;

public:
    test() : id(++count)
    {
        std::cout << "test " << id << "被创建" << std::endl;
    }
    ~test()
    {
        std::cout << "test " << id << "被销毁" << std::endl;
    }
};
int test::count = 0;

void *operator new[](size_t size)
{
    std::cout << "全局 operator new[] 被调用，请求 size = " << size << std::endl;
    return malloc(size);
}

void operator delete[](void *ptr) noexcept
{
    std::cout << "全局 operator delete[] 被调用" << std::endl;
    free(ptr);
}

int main()
{
    const int N = 3;
    std::cout << "sizeof(test) = " << sizeof(test) << std::endl;
    test *p = new test[N];

    std::cout << "test数组 开始销毁" << std::endl;

    delete[] p;
    return 0;
}