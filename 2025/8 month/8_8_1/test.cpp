#include <iostream>
#include <cstdlib>
#include <new>

void *operator new(size_t size)
{
    std::cout << "ȫ�� operator new ������ size = " << size << std::endl;
    void *p = malloc(size);
    if (!p)
    {
        throw std::bad_alloc();
    }
    return p;
}

void operator delete(void *p) noexcept
{
    std::cout << "ȫ�� operator delete ������" << std::endl;
    free(p);
}

class test
{
public:
    test()
    {
        std::cout << "test ���캯��������" << std::endl;
    }
    ~test()
    {
        std::cout << "test ��������������" << std::endl;
    }
    static void *operator new(size_t size)
    {
        std::cout << "test��::operator new������ size = " << size << std::endl;
        return ::operator new(size);
    }
    static void operator delete(void *p) noexcept
    {
        std::cout << "test��::operator delete������" << std::endl;
        ::operator delete(p);
    }
};

int main()
{
    std::cout << "ȫ��new/delete" << std::endl;
    int *p_int = new int(5);
    delete p_int;

    std::cout << "-------------------" << std::endl;
    std::cout << "���new/delete" << std::endl;
    test *p_test = new test();
    delete p_test;

    return 0;
}