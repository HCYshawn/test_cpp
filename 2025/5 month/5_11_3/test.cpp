#include <iostream>
using namespace std;

template <class T>
class SmartPtr
{
public:
    SmartPtr(T *ptr = nullptr)
        : _ptr(ptr)
    {
    }
    ~SmartPtr()
    {
        if (_ptr)
            delete _ptr;
    }
    T &operator*() { return *_ptr; }
    T *operator->() { return _ptr; }

private:
    T *_ptr;
};
struct Date
{
    int _year;
    int _month;
    int _day;
};

int main()
{
    SmartPtr<int> sp1(new int);
    *sp1 = 10;
    cout << *sp1 << endl;

    SmartPtr<Date> sp2(new Date);
    sp2->_year = 2023;
    sp2->_month = 10;
    sp2->_day = 1;
    return 0;
}