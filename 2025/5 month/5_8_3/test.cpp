#include <iostream>
using namespace std;

template <class T>
void Function(T &&t)
{
    int a = 0;
    T x = a;

    cout << &a << endl;
    cout << &x << endl
         << endl;
}

int main()
{
    // 右值，推为int&&
    Function(10);

    // 左值，推为int&
    int a;
    Function(a);

    // 右值，推为int&&
    Function(move(a));

    // 左值，推为int&
    const int b = 8;
    Function(b);

    // 右值，推为const int&&
    Function(move(b));
    return 0;
}