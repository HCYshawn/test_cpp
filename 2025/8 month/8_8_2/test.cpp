#include <iostream>
#include <new>

class Mydata
{
private:
    int d;

public:
    Mydata(int data) : d(data)
    {
        std::cout << "Mydata ���캯�������� ����: " << d << std::endl;
    }
    ~Mydata()
    {
        std::cout << "Mydata �������������� ����: " << d << std::endl;
    }
    void print()
    {
        std::cout << "Mydata ��ֵΪ: " << d << std::endl;
    }
};

int main()
{
    // ��ջ�Ϸ����ڴ�
    alignas(Mydata) unsigned char buffer[sizeof(Mydata)];
    std::cout << "������������ַ: " << static_cast<void *>(buffer) << std::endl;

    // ʹ��placement new �ڻ������Ϲ���һ��Mydata����
    Mydata *pData = new (buffer) Mydata(123);

    std::cout << "�������ڵ�ַ: " << pData << std::endl;
    pData->print();

    // �ֶ���������
    pData->~Mydata();
    return 0;
}