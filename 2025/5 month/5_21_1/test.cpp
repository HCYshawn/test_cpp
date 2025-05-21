#include <iostream>
#include <stdio.h>

using namespace std;

void func(int num)
{
    cout << "this is int" << num << endl;
}

void func(void *ptr)
{
    cout << "this is void*" << ptr << endl;
}

void test1()
{
    func(nullptr);
}

template <typename T>
void test2(T value)
{
    if (value == NULL)
    {
        cout << "空指针" << endl;
    }
    else
    {
        cout << "不是空指针" << endl;
    }
}

int main()
{
    test1();
    test2(nullptr);
    test2(NULL);
    test2(0);
    return 0;
}