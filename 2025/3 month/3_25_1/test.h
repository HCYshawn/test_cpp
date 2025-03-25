#pragma once
#include <iostream>
#include <cassert>
namespace hcy
{

    template <typename T>
    struct list_node
    {
        T _data;
        list_node<T> *_next;
        list_node<T> *_prev;

        list_node(const T &data = T())
            : _data(data), _next(nullptr), _prev(nullptr)
        {
        }
    };

    template <class T>
    struct list_iterator
    {
        typedef list_node<T> Node;
        typedef list_iterator<T> Self;

        Node *_node;

        list_iterator(Node *node)
            : _node(node)
        {
        }

        T &operator*()
        {
            return _node->_data;
        }

        Self &operator++()
        {
            _node = _node->_next;
            return *this;
        }

        Self &operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        bool operator==(const Self &s) const
        {
            return _node == s._node;
        }

        bool operator!=(const Self &s) const
        {
            return _node != s._node;
        }
    };

    template <class T>
    class list
    {

        typedef list_node<T> Node;

    private:
        Node *_head;
        size_t _size;

    public:
        typedef list_iterator<T> iterator;

        list()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
            _size = 0;
        }

        // ~list()
        // {
        //     clear();
        //     delete _head;
        //     _head = nullptr;
        // }

        iterator begin()
        {
            return _head->_next;
        }

        iterator end()
        {
            return _head;
        }

        void push_back(const T &x)
        {
            insert(end(), x);
        }

        void push_front(const T &x)
        {
            insert(begin(), x);
        }

        void pop_back()
        {
            erase(--end());
        }

        void pop_front()
        {
            erase(begin());
        }

        void insert(iterator pos, const T &x)
        {
            Node *newnode = new Node(x);
            Node *cur = pos._node;
            Node *prev = cur->_prev;

            newnode->_next = cur;
            cur->_prev = newnode;
            newnode->_prev = prev;
            prev->_next = newnode;

            ++_size;
        }

        void erase(iterator pos)
        {
            assert(pos != end());

            Node *prev = pos._node->_prev;
            Node *next = pos._node->_next;

            prev->_next = next;
            next->_prev = prev;
            delete pos._node;

            --_size;
        }

        // void clear()
        // {
        //     Node *cur = _head->_next;
        //     while (cur != _head)
        //     {
        //         Node *next = cur->_next;
        //         delete cur;
        //         cur = next;
        //     }

        //     _head->_next = _head;
        //     _head->_prev = _head;
        //     _size = 0;
        // }

        size_t size() const
        {
            return _size;
        }

        bool empty() const
        {
            return _size == 0;
        }
    };
}