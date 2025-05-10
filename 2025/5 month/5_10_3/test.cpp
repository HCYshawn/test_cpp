#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Goods
{
    string _name;
    double _price;
    int _evaluate;

    Goods(string name, double price, int evaluate)
        : _name(name), _price(price), _evaluate(evaluate) {}
};

int main()
{
    vector<Goods> v = {{"苹果", 2.1, 5}, {"香蕉", 3, 4}, {"橙子", 2.2, 3}, {"菠萝", 1.5, 4}};

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._price < g2._price; });
    cout << "按价格升序排列:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._price > g2._price; });
    cout << "按价格降序排列:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._evaluate < g2._evaluate; });
    cout << "按评价升序排列:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._evaluate > g2._evaluate; });
    cout << "按评价降序排列:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    return 0;
}