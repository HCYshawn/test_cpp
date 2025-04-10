#include <iostream>
#include <set>
using namespace std;

void test1()
{
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(7);
    s.insert(5);
    s.insert(7);
    s.insert(3);

    auto it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    s.insert({2, 8, 3, 9, 2});
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test2()
{
    set<int> s = {4, 2, 7, 2, 8, 5, 9};
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    s.erase(s.begin());
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    int x = 0;
    cin >> x;
    auto it = s.find(x);
    if (it != s.end())
    {
        cout << "Found: " << *it << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test3()
{
    set<int> s;
    for (int i = 1; i < 10; i++)
    {
        s.insert(i * 10);
    }
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    auto itlow = s.lower_bound(20);
    auto itup = s.upper_bound(50);

    s.erase(itlow, itup);
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}