#include <iostream>
using namespace std;

double Division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    else
        return ((double)a / (double)b);
}

void Func()
{
    int len = 0;
    int time = 0;
    cin >> len >> time;
    cout << Division(len, time) << endl;
}

int main()
{
    try
    {
        Func();
    }
    catch (const char *errmsg)
    {
        cout << errmsg << endl;
    }
    catch (...)
    {
        cout << "unkown exception" << endl;
    }

    return 0;
}