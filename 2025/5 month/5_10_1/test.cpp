#include <iostream>
#include <string>
using namespace std;

template <class T>
void ShowList(const T &t)
{
    cout << t << endl;
}

template <class T, class... Args>
void ShowList(T value, Args... args)
{
    cout << value << " ";
    ShowList(args...);
}

int main()
{
    ShowList(1);
    ShowList(1, 'A');
    ShowList(1, 'A', string("sort"));
    return 0;
}
