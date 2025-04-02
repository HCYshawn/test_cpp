#include <iostream>
using namespace std;

class A
{
public:
    void fun()
    {
        cout << "fun()" << endl;
    }
};

class B : public A
{
public:
    void fun(int i)
    {
        cout << "fun(int i)" << endl;
    }
};

int main()
{
    B b;
    b.fun();
    b.fun(1);
    return 0;
}