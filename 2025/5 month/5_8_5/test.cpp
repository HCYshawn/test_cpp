#include <iostream>
#include <vector>
#include <chrono>

class Resource
{
public:
    Resource(size_t size) : size_(size), data_(new int[size])
    {
    }

    ~Resource()
    {
        delete[] data_;
    }

    Resource(const Resource &other) : size_(other.size_), data_(new int[other.size_])
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    Resource(Resource &&other) noexcept : size_(other.size_), data_(other.data_)
    {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    Resource &operator=(const Resource &other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = new int[other.size_];
            std::copy(other.data_, other.data_ + other.size_, data_);
        }
        return *this;
    }

    Resource &operator=(Resource &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

private:
    size_t size_;
    int *data_;
};

int main()
{
    const size_t size = 1000000;
    std::vector<Resource> vec;

    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 100; i++)
    {
        Resource r(size);
        vec.push_back(r);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "拷贝用时：" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    vec.clear();
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 100; i++)
    {
        Resource r(size);
        vec.push_back(std::move(r));
    }

    end = std::chrono::high_resolution_clock::now();
    std::cout << "移动用时：" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    return 0;
}