#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    const int ELEMENT_COUNT = 1000000;

    vector<int> vec;
    list<int> lst;

    for (int i = 0; i < ELEMENT_COUNT; ++i)
    {
        vec.push_back(i);
        lst.push_back(i);
    }

    // ����vector
    auto start = high_resolution_clock::now();
    volatile int sum_vec = 0; // ʹ��volatile��ֹ�Ż�
    for (auto &num : vec)
    {
        sum_vec += num;
    }
    auto end = high_resolution_clock::now();
    auto vector_time = duration_cast<nanoseconds>(end - start).count();

    // ����list
    start = high_resolution_clock::now();
    volatile int sum_lst = 0; // ʹ��volatile��ֹ�Ż�
    for (auto &num : lst)
    {
        sum_lst += num;
    }
    end = high_resolution_clock::now();
    auto list_time = duration_cast<nanoseconds>(end - start).count();

    // ǿ������������һ����ֹ�Ż���
    cout << "Vector sum: " << sum_vec
         << " | Time: " << vector_time << " ns" << endl;
    cout << "List sum:   " << sum_lst
         << " | Time: " << list_time << " ns" << endl;

    return 0;
}