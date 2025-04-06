#include <iostream>
using namespace std;

class A
{
public:
    void func(int a = 1)
    {
        cout << "A->" << a << endl;
    }
    void test()
    {
        func();
    }
};

class B : public A
{
public:
    void func(int a = 0)
    {
        cout << "B->" << a << endl;
    }
};

int main()
{
    B *b = new B;
    b->test(); // Calls A::func, prints "A->1"
    b->func(); // Calls B::func, prints "B->0"
    return 0;
}