#include <iostream>
using namespace std;

void Fun(int &x)
{
    cout << "��ֵ����" << endl;
}

void Fun(const int &x)
{
    cout << "��ֵ����" << endl;
}

void Fun(int &&x)
{
    cout << "��ֵ����" << endl;
}

void Fun(const int &&x)
{
    cout << "��ֵ����" << endl;
}

template <class T>
void Function(T &&t)
{
    Fun(forward<T>(t));
}

int main()
{
    // ��ֵ����Ϊint&&
    Function(10);

    // ��ֵ����Ϊint&
    int a;
    Function(a);

    // ��ֵ����Ϊint&&
    Function(move(a));

    // ��ֵ����Ϊint&
    const int b = 8;
    Function(b);

    // ��ֵ����Ϊconst int&&
    Function(move(b));
    return 0;
}