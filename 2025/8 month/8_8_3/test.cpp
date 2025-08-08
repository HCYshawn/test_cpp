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
        std::cout << "test " << id << "������" << std::endl;
    }
    ~test()
    {
        std::cout << "test " << id << "������" << std::endl;
    }
};
int test::count = 0;

void *operator new[](size_t size)
{
    std::cout << "ȫ�� operator new[] �����ã����� size = " << size << std::endl;
    return malloc(size);
}

void operator delete[](void *ptr) noexcept
{
    std::cout << "ȫ�� operator delete[] ������" << std::endl;
    free(ptr);
}

int main()
{
    const int N = 3;
    std::cout << "sizeof(test) = " << sizeof(test) << std::endl;
    test *p = new test[N];

    std::cout << "test���� ��ʼ����" << std::endl;

    delete[] p;
    return 0;
}