#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("abcdef");

    str.push_back('g');
    cout << str << endl;

    str.append("hijklmn");
    cout << str << endl;

    str += "123";
    cout << str << endl;

    cout << str.c_str() << endl;

    int f1 = str.find('c');
    cout << f1 << endl;

    int f2 = str.rfind('c');
    cout << f2 << endl;

    cout << str.substr(2, 3) << endl;
    return 0;
}