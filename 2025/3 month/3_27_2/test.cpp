#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}
template int add<int>(int, int);

int main()
{
    cout << add(1, 2) << endl;
    cout << add(1.1, 2.2) << endl;
    cout << add<int>(1, 'a') << endl;
    cout << add<int>(1, 3.3) << endl;
    return 0;
}