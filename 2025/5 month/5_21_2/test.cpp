#include <iostream>
#include <chrono>

class Counter
{
public:
    Counter() : count(0) {}
    Counter &operator++()
    {
        ++count;
        return *this;
    }
    Counter operator++(int)
    {
        Counter temp = *this;
        ++count;
        return temp;
    }

private:
    int count;
};

int main()
{
    const int iterations = 100000000;

    auto start = std::chrono::high_resolution_clock::now();
    Counter c1;
    for (int i = 0; i < iterations; ++i)
    {
        ++c1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "++i time: " << diff.count() << " s " << std::endl;

    start = std::chrono::high_resolution_clock::now();
    Counter c2;
    for (int i = 0; i < iterations; ++i)
    {
        c2++;
    }

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "i++ time: " << diff.count() << " s " << std::endl;
    return 0;
}