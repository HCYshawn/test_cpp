#include "test.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
    hcy::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    hcy::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void test2()
{
    hcy::vector<double> v;
    v.push_back(1.1);
    v.push_back(2.2);
    v.push_back(3.3);
    v.push_back(4.4);
    v.push_back(5.5);

    print_vector(v);
}

void test3()
{
    hcy::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    print_vector(v);

    v.insert(v.begin() + 2, 30);
    print_vector(v);

    int x;
    cin >> x;
    auto p = find(v.begin(), v.end(), x);
    if (p != v.end())
    {
        p = v.insert(p, 40);
        (*(p + 1)) *= 10;
    }
    print_vector(v);
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}