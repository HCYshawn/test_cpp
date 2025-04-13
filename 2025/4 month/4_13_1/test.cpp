#include "AVLtree.h"
#include <vector>

void test1()
{
    AVLTree<int, int> t;
    int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    for (auto e : a)
    {
        t.Insert({e, e});
    }

    t.InOrder();
    cout << t.IsBalanceTree() << endl;
}
void test2()
{
    const int N = 1000000;
    vector<int> v;
    v.reserve(N);
    srand(time(0));
    for (size_t i = 0; i < N; i++)
    {
        v.push_back(rand() + i);
    }

    size_t begin2 = clock();
    AVLTree<int, int> t;
    for (auto e : v)
    {
        t.Insert(make_pair(e, e));
    }
    size_t end2 = clock();

    cout << "Insert:" << end2 - begin2 << endl;
    cout << t.IsBalanceTree() << endl;

    cout << "Height:" << t.Height() << endl;
    cout << "Size:" << t.Size() << endl;

    size_t begin1 = clock();
    // 确定在的值
    for (auto e : v)
    {
        t.Find(e);
    }
    // 随机值
    /*for (size_t i = 0; i < N; i++)
    {
        t.Find((rand() + i));
    }*/
    size_t end1 = clock();
    cout << "Find:" << end1 - begin1 << endl;
}

int main()
{
    // test1();
    test2();
    return 0;
}