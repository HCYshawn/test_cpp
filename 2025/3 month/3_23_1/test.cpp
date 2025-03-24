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

// void test4()
// {
//     hcy::vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     v.push_back(4);

//     print_container(v);

//     auto it = v.begin();
//     while (it != v.end())
//     {
//         if (*it % 2 == 0)
//         {
//             it = v.erase(it);
//         }
//         else
//         {
//             ++it;
//         }
//     }
// }

void test4()
{
    hcy::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(4);
    v1.push_back(4);
    print_container(v1);

    hcy::vector<int> v2(v1.begin(), v1.begin() + 3);
    print_vector(v2);
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}