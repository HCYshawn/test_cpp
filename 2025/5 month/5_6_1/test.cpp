#include "hashtable.h"

int main()
{
    int a2[] = {19, 30, 5, 36, 13, 20, 21, 12, 24, 96};
    hcy::HashTable<int, int> ht2;
    for (auto e : a2)
    {
        ht2.Insert({e, e});
    }

    ht2.Insert({100, 100});
    ht2.Insert({101, 101});

    return 0;
}