#include <iostream>
#include <vector>

template <class T>
class ObjectPool
{
private:
    std::vector<T *> pool_;

public:
    ObjectPool(std::size_t size = 10)
    {
        for (std::size_t i = 0; i < size; ++i)
        {
            pool_.push_back(new T());
        }
    }
    ~ObjectPool()
    {
        for (auto &obj : pool_)
        {
            delete obj;
        }
    }

    T *acquire()
    {
        if (pool_.empty())
        {
            return new T();
        }
        else
        {
            T *obj = pool_.back();
            pool_.pop_back();
            return obj;
        }
    }

    void release(T *obj)
    {
        std::cout << "Releasing object back to pool\n";
        pool_.push_back(obj);
    }
};

class MyObject
{
public:
    MyObject() { std::cout << "MyObject created\n"; }
    ~MyObject() { std::cout << "MyObject destroyed\n"; }

    void dosomething()
    {
        std::cout << "---------runing-------------" << std::endl;
    }
};

int main()
{

    ObjectPool<MyObject> pool(5);

    MyObject *obj = pool.acquire();
    obj->dosomething();

    pool.release(obj);

    return 0;
}