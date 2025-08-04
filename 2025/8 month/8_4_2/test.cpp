#include <iostream>
using namespace std;

int main()
{
    char s1[10] = {"abc"};
    char s2[10] = {'a', 'b', 'c'};
    for (int i = 0; i < 10; i++)
    {
        if (s1[i] != s2[i])
        {
            cout << "s1 and s2 are not equal at index " << i << endl;
            return 1;
        }
    }
    cout << "s1 and s2 are equal." << endl;
    return 0;
}