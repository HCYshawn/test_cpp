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

    cout << "�±����" << endl;
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    cout << "����������" << endl;
    string::iterator it = str.begin();
    for (; it != str.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "�������������" << endl;
    string::reverse_iterator rit = str.rbegin();
    for (; rit != str.rend(); rit++)
    {
        cout << *rit << " ";
    }
    cout << endl;

    cout << "��Χfor����" << endl;
    for (auto ch : str)
    {
        cout << ch << " ";
    }
    return 0;
}