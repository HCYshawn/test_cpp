#include "test.h"

int main()
{
    hcy::BSTree<int> t1;
    int a[] = {8, 3, 1, 10, 1, 6, 4, 7, 14, 13};
    for (auto e : a)
    {
        t1.Insert(e);
    }

    t1.InOrder();

    t1.Insert(16);
    t1.InOrder();

    t1.Erase(3);
    t1.InOrder();

    return 0;
}