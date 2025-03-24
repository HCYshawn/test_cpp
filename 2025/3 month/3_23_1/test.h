#pragma once
#include <iostream>
#include <list>
#include <assert.h>

namespace hcy
{
    template <typename T>
    class vector
    {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        vector() = default;

        vector(const vector<T> &v)
        {
            reserve(v.size());
            for (auto &e : v)
            {
                push_back(e);
            }
        }

        template <typename InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(size_t n, const T &tal = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(tal);
            }
        }

        void clear()
        {
            _finish = _start;
        }

        void swap(vector<T> &v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        vector<T> &operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t old_size = size();
                T *tmp = new T[n];
                // memcpy(tmp, _start, size() * sizeof(T));
                for (size_t i = 0; i < old_size; ++i)
                {
                    tmp[i] = _start[i];
                }
                delete[] _start;

                _start = tmp;
                _finish = _start + old_size;
                _end_of_storage = _start + n;
            }
        }

        void resize(size_t n, const T &val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                while (_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        bool empty() const
        {
            return _start == _finish;
        }

        void push_back(const T &x)
        {
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : 2 * capacity() * 2);
            }
            *_finish = x;
            ++_finish;
        }

        void pop_back()
        {
            assert(!empty());
            --_finish;
        }

        iterator insert(iterator pos, const T &x)
        {
            if (_finish == _end_of_storage)
            {
                size_t len = pos - _start;
                reserve(capacity() == 0 ? 4 : capacity() * 2);
                pos = _start + len;
            }

            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }

            *pos = x;
            ++_finish;
            return pos;
        }

        void erase(iterator pos)
        {
            assert(pos >= _start && pos < _finish);
            iterator it = pos + 1;
            while (it != end())
            {
                *(it - 1) = *it;
                ++it;
            }
            --_finish;
        }

        T &operator[](size_t i)
        {
            assert(i < size());
            return _start[i];
        }

        const T &operator[](size_t i) const
        {
            assert(i < size());
            return _start[i];
        }

    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;
    };

    template <class T>
    void print_vector(const vector<T> &v)
    {
        auto it = v.begin();
        while (it != v.end())
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;

        for (auto e : v)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    template <class Container>
    void print_container(const Container &v)
    {
        for (auto e : v)
        {
            std::cout << e << " ";
        }

        std::cout << std::endl;
    }
}
