#include "test1.h"

void test1()
{
    HashTable<int> ht(11);
    vector<int> keys = {47, 7, 29, 11, 16, 92, 22, 8, 3};

    // 测试插入
    for (auto k : keys)
    {
        cout << "插入 " << k << ": " << (ht.insert(k) ? "成功" : "失败") << endl;
    }

    // 打印散列表
    cout << "\n最终散列表状态：" << endl;
    ht.print();

    // 测试查找
    vector<int> testKeys = {7, 16, 99};
    for (auto k : testKeys)
    {
        int pos;
        bool found = ht.search(k, pos);
        cout << "查找 " << k << ": "
             << (found ? "找到 @位置" + to_string(pos) : "未找到") << endl;
    }

    // 测试删除
    cout << "\n删除 16: " << (ht.remove(16) ? "成功" : "失败") << endl;
    ht.print();
}

int main()
{
    test1();
    
    return 0;
}