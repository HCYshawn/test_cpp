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
    vector<Goods> v = {{"ƻ��", 2.1, 5}, {"�㽶", 3, 4}, {"����", 2.2, 3}, {"����", 1.5, 4}};

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._price < g2._price; });
    cout << "���۸���������:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._price > g2._price; });
    cout << "���۸�������:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._evaluate < g2._evaluate; });
    cout << "��������������:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    sort(v.begin(), v.end(), [](const Goods &g1, const Goods &g2)
         { return g1._evaluate > g2._evaluate; });
    cout << "�����۽�������:" << endl;
    for (const auto &g : v)
    {
        cout << g._name << " " << g._price << " " << g._evaluate << endl;
    }

    return 0;
}