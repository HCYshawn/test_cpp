#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun() = 0;
};

class B : public A
{
public:
    void fun() override
    {
        cout << "B::fun()" << endl;
    }
};

class C : public A
{
public:
    void fun() override
    {
        cout << "C::fun()" << endl;
    }
};

int main()
{
    A *a = new B(); // Create an object of class B
    a->fun();       // Calls B::fun()
    a = new C();    // Now create an object of class C
    a->fun();       // Calls C::fun()
    delete a;       // Clean up memory
    return 0;
}