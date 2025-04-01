#include <iostream>
using namespace std;

template <class T1, class T2>
class Data
{
private:
    T1 a;
    T2 b;

public:
    Data() { cout << "Data <T1, T2>" << endl; }
};

// ȫ�ػ�
template <>
class Data<int, char>
{
private:
    int a;
    char b;

public:
    Data() { cout << "Data <int, char>" << endl; }
};

// ƫ�ػ�/�����ػ�
template <class T1>
class Data<T1, double>
{
public:
    Data() { cout << "Data <T1, double>" << endl; }
};

// ƫ�ػ�����ָ��
template <class T1, class T2>
class Data<T1 *, T2 *>
{
private:
    T1 *a;
    T2 *b;

public:
    Data() { cout << "Data <T1*, T2*>" << endl; }
};

int main()
{
    Data<int, char> d1;    // Data <int, char>
    Data<int, int> d2;     // Data <T1, int>
    Data<int *, int *> d3; // Data <T1*, T2*>
    Data<int, double> d4;  // Data <T1, T2>
    Data<char, double> d5;
    return 0;
}