#include "test.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
    hcy::list<int> lt;

    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    hcy::list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void test2()
{
    hcy::list<int> lt;

    lt.push_front(1);
    lt.push_front(2);
    lt.push_front(3);
    lt.push_front(4);
    lt.push_front(5);
    lt.push_front(6);

    for (auto e : lt)
    {
        std::cout << e << " ";
    }
    cout << endl;

    auto it = lt.begin();
    int k = 3;
    while (k--)
    {
        ++it;
    }

    lt.insert(it, 30);

    for (auto e : lt)
    {
        std::cout << e << " ";
    }
    cout << endl;

    // int x = 0;
    // cin >> x;
    // it = find(lt.begin(), lt.end(), x);
    // if (it != lt.end())
    // {
    //     lt.erase(it);
    // }

    // for (auto e : lt)
    // {
    //     std::cout << e << " ";
    // }
    // cout << endl;
}

int main()
{
    // test1();
    test2();
    return 0;
}