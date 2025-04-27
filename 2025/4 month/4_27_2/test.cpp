#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    int i = 100000;
    while (i)
    {
        int a = rand();
        if (a % 2 == 0)
        {
            x++;
        }
        else
        {
            y++;
        }
        i--;
    }

    cout << "2:" << x << endl;
    cout << "!2:" << y << endl;
    return 0;
}