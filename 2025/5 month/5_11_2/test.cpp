#include <iostream>
#include <stdexcept>
#include <memory>
using namespace std;

template <class T>
class SmartPtr
{
public:
    SmartPtr(T *p = nullptr) : _ptr(p)
    {
    }
    ~SmartPtr()
    {
        if (_ptr)
            delete _ptr;
    }

private:
    T *_ptr;
};

int div()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        throw invalid_argument("³ı0´íÎó");
    }
    return a / b;
}

void Func()
{
    SmartPtr<int> sp1(new int);
    SmartPtr<int> sp2(new int);

    cout << div() << endl;
}

int main()
{
    try
    {
        Func();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}