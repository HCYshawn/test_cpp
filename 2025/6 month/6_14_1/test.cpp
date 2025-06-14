#include <iostream>
using namespace std;

class A
{
public:
    void pa()
    {
        cout << "I am A" << endl;
    }
};

class B : virtual public A
{
public:
    void pb()
    {
        cout << "I am B" << endl;
    }
};

class C : virtual public A
{
public:
    void pc()
    {
        cout << "I am C" << endl;
    }
};

class D : public B, public C
{
public:
    void pd()
    {
        cout << "I am D" << endl;
    }
};

int main()
{
    D d;
    d.pa();
    d.pb();
    d.pc();
    return 0;
}