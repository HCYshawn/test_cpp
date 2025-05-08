#include <iostream>
using namespace std;

void Fun(int &x)
{
    cout << "左值引用" << endl;
}

void Fun(const int &x)
{
    cout << "左值引用" << endl;
}

void Fun(int &&x)
{
    cout << "右值引用" << endl;
}

void Fun(const int &&x)
{
    cout << "右值引用" << endl;
}

template <class T>
void Function(T &&t)
{
    Fun(forward<T>(t));
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