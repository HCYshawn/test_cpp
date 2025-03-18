#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("abcdf");

    cout << str << endl;
    cout << str[1] << endl;
    cout << str[3] << endl;
    str[0] = 'h';

    cout << "下标遍历" << endl;
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    cout << "迭代器遍历" << endl;
    string::iterator it = str.begin();
    for (; it != str.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "反向迭代器遍历" << endl;
    string::reverse_iterator rit = str.rbegin();
    for (; rit != str.rend(); rit++)
    {
        cout << *rit << " ";
    }
    cout << endl;

    cout << "范围for遍历" << endl;
    for (auto ch : str)
    {
        cout << ch << " ";
    }
    return 0;
}