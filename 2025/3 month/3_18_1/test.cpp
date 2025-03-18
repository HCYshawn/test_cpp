#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("abcdef");
    cout << "str: " << str << endl;

    // ��ʾ�ַ����ĳ���
    cout << "size: " << str.size() << endl;
    cout << "length: " << str.length() << endl;

    // ��ʾ�ַ���������
    cout << "capacity: " << str.capacity() << endl;

    // ��ʾ�ַ����Ƿ�Ϊ��
    cout << "empty: " << str.empty() << endl;

    // ����ַ���
    str.clear();
    cout << "str: " << str << endl;

    // ����100���ֽڵĿռ�
    str.reserve(100);
    cout << "capacity: " << str.capacity() << endl;

    // ���������ַ����ĳ��Ȳ�����ַ�
    str.resize(5, 'a');
    cout << "size: " << str.size() << endl;
    cout << "str: " << str << endl;
    return 0;
}