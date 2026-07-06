#include <iostream>
#include <cassert>

typedef int STDataType;

class Stack
{
public:
    Stack(size_t capacity = 4)
        : _a(nullptr), _top(0), _capacity(0)
    {
        if (capacity == 0)
            capacity = 4;
        _a = new STDataType[capacity];
        _capacity = capacity;
    }

    ~Stack()
    {
        delete[] _a;
        _a = nullptr;
        _top = 0;
        _capacity = 0;
    }

    Stack(const Stack &st)
        : _a(nullptr), _top(0), _capacity(0)
    {
        _a = new STDataType[st._capacity];
        _capacity = st._capacity;
        for (size_t i = 0; i < st._top; i++)
        {
            _a[i] = st._a[i];
        }
        _top = st._top;
    }
    Stack &operator=(const Stack &st)
    {
        if (this != &st)
        {
            STDataType *tmp = new STDataType[st._capacity];
            for (size_t i = 0; i < st._top; i++)
            {
                tmp[i] = st._a[i];
            }
            delete[] _a;
            _a = tmp;
            _top = st._top;
            _capacity = st._capacity;
        }
        return *this;
    }

    void Push(STDataType x)
    {
        if (_top == _capacity)
        {
            size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
            STDataType *tmp = new STDataType[newCapacity];

            for (size_t i = 0; i < _top; i++)
            {
                tmp[i] = _a[i];
            }
            delete[] _a;
            _a = tmp;
            _capacity = newCapacity;
        }
        _a[_top++] = x;
    }
    void Pop()
    {
        assert(_top > 0);
        _top--;
    }
    STDataType Top() const
    {
        assert(_top > 0);
        return _a[_top - 1];
    }

    bool Empty() const
    {
        return _top == 0;
    }

    size_t Size() const
    {
        return _top;
    }

    size_t Capacity() const
    {
        return _capacity;
    }

    void Print() const
    {
        for (size_t i = 0; i < _top; i++)
        {
            std::cout << _a[i] << " ";
        }
    }

private:
    STDataType *_a;
    size_t _top;
    size_t _capacity;
};

int main()
{
    Stack st1;
    st1.Push(1);
    st1.Push(2);
    st1.Push(3);
    st1.Push(4);
    st1.Push(5); // 测试扩容

    Stack st2(st1);
    st2.Push(6);

    Stack st3;
    st3 = st1;
    st3.Push(7);

    st1.Print(); // 1 2 3 4 5
    st2.Print(); // 1 2 3 4 5 6
    st3.Print(); // 1 2 3 4 5 7

    st1 = st1;
    st1.Print(); // 1 2 3 4 5

    return 0;
}