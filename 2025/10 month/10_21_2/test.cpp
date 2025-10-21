#include <iostream>
#include <mutex>

using namespace std;

class Monitor
{
private:
    Monitor() {}
    static Monitor *instance;
    static std::mutex mtx; // 静态互斥锁，供所有线程共享

public:
    static Monitor *getInstance();
    void getName();
};

// 静态成员定义
Monitor *Monitor::instance = nullptr;
std::mutex Monitor::mtx;

Monitor *Monitor::getInstance()
{
    std::lock_guard<std::mutex> lock(mtx); // RAII 自动加锁/解锁
    if (instance == nullptr)
    {
        instance = new Monitor();
    }
    else
    {
        cout << "实例已存在，返回现有实例" << endl;
    }
    return instance;
}

void Monitor::getName()
{
    cout << "测试" << endl;
}

int main()
{
    Monitor *p1 = Monitor::getInstance();
    p1->getName();
    Monitor *p2 = Monitor::getInstance();
    p2->getName();

    if (p1 == p2)
    {
        cout << "同一实例" << endl;
    }
    else
    {
        cout << "有误" << endl;
    }

    // 记得释放单例实例（避免内存泄漏）
    delete p1;
    return 0;
}