#include <iostream>
using namespace std;

template <class T>
class Singleton
{
private:
    static Singleton _eton;

private:
    Singleton() {}
    ~Singleton() {}

public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    static T &getInstance()
    {
        return _eton;
    }
};
