#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(1, 2) << endl;
    cout << add(1.1, 2.2) << endl;
    
    return 0;
}