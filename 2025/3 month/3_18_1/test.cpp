#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("abcdef");
    cout << "str: " << str << endl;

    // 显示字符串的长度
    cout << "size: " << str.size() << endl;
    cout << "length: " << str.length() << endl;

    // 显示字符串的容量
    cout << "capacity: " << str.capacity() << endl;

    // 显示字符串是否为空
    cout << "empty: " << str.empty() << endl;

    // 清空字符串
    str.clear();
    cout << "str: " << str << endl;

    // 开辟100个字节的空间
    str.reserve(100);
    cout << "capacity: " << str.capacity() << endl;

    // 重新设置字符串的长度并填充字符
    str.resize(5, 'a');
    cout << "size: " << str.size() << endl;
    cout << "str: " << str << endl;
    return 0;
}