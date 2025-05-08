#include <iostream>
using namespace std;

template <class T>
void f1(T &x)
{
    cout << "f1<T&>." << endl;
}

template <class T>
void f2(T &&x)
{
    cout << "f2<T&&>." << endl;
}

int main()
{
    int n = 0;
    f1<int>(n);
    // f1<int>(0);

    f1<int &>(n);
    // f1<int&>(0);

    f1<int &&>(n);
    // f1<int&&>(0);

    f1<const int &>(n);
    f1<const int &>(0);

    // f2<int>(n);
    f2<int>(0);

    f2<int &>(n);
    // f2<int &>(0);

    // f2<int &&>(n);
    f2<int &&>(0);
    return 0;
}