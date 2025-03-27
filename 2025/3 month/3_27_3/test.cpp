#include <iostream>
using namespace std;

int maxx(int a, int b)
{
    return a > b ? a : b;
}

template <typename T>
T maxx(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T maxx(T a, T b, T c)
{
    return maxx(maxx(a, b), c);
}

int main()
{
    cout << maxx(3, 4) << endl;
    cout << maxx(3.3, 4.4) << endl;
    cout << maxx(3, 4, 5) << endl;
    cout << maxx(3.3, 4.4, 5.5) << endl;
    return 0;
}