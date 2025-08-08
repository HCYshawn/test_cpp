#include <iostream>
#include <new>

class Mydata
{
private:
    int d;

public:
    Mydata(int data) : d(data)
    {
        std::cout << "Mydata 构造函数被调用 数据: " << d << std::endl;
    }
    ~Mydata()
    {
        std::cout << "Mydata 析构函数被调用 数据: " << d << std::endl;
    }
    void print()
    {
        std::cout << "Mydata 的值为: " << d << std::endl;
    }
};

int main()
{
    // 在栈上分配内存
    alignas(Mydata) unsigned char buffer[sizeof(Mydata)];
    std::cout << "缓冲区创建地址: " << static_cast<void *>(buffer) << std::endl;

    // 使用placement new 在缓冲区上构造一个Mydata对象
    Mydata *pData = new (buffer) Mydata(123);

    std::cout << "对象构造于地址: " << pData << std::endl;
    pData->print();

    // 手动析构对象
    pData->~Mydata();
    return 0;
}