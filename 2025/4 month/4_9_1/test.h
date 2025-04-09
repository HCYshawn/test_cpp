#pragma once
#include <iostream>
using namespace std;

namespace hcy
{
    // 二叉搜索树节点
    template <class K>
    struct BSTNode
    {
        K _key;
        BSTNode *_left;
        BSTNode *_right;
        BSTNode(const K &key)
            : _key(key), _left(nullptr), _right(nullptr) {}
    };

    template <class K>
    class BSTree
    {
        using Node = BSTNode<K>;

    public:
        BSTree() = default;

        BSTree(const BSTree &other)
        {
            _root = Copy(other._root);
        }

        BSTree &operator=(const BSTree &tmp)
        {
            swap(_root, tmp._root);
            return *this;
        }

        ~BSTree()
        {
            Destroy(_root);
            _root = nullptr;
        }

        bool Insert(const K &key)
        {
            if (_root == nullptr)
            {
                _root = new Node(key);
                return true;
            }
            Node *parent = nullptr;
            Node *cur = _root;

            // 寻找要插入的位置
            while (cur)
            {
                // 满足条件向左子树插入
                if (cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                // 满足条件向右子树插入
                else if (cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    return false; // Duplicate key
                }
            }

            // 插入新节点
            cur = new Node(key);
            if (parent->_key < key)
            {
                parent->_right = cur;
            }
            else
            {
                parent->_left = cur;
            }
            return true;
        }
        Node *Find(const K &key)
        {
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key < key)
                {
                    cur = cur->_right;
                }
                else if (cur->_key > key)
                {
                    cur = cur->_left;
                }
                else
                {
                    return cur; // 找到节点
                }
            }
            return nullptr; // 没有找到节点
        }

        bool Erase(const K &key)
        {
            Node *cur = _root;
            Node *parent = nullptr;
            while (cur)
            {
                if (cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    if (cur->_left == nullptr)
                    {
                        if (parent == nullptr)
                        {
                            _root = cur->_right;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                            delete cur;
                        }
                    }
                    else if (cur->_right == nullptr)
                    {
                        if (parent == nullptr)
                        {
                            _root = cur->_left;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_left;
                            }
                            else
                            {
                                parent->_right = cur->_left;
                            }
                            delete cur;
                        }
                    }
                    else
                    {
                        Node *repalceparent = cur;
                        Node *replace = cur->_right;
                        while (replace->_left)
                        {
                            repalceparent = replace;
                            replace = replace->_left;
                        }
                        cur->_key = replace->_key;
                        if (repalceparent->_left == replace)
                        {
                            repalceparent->_left = replace->_right;
                        }
                        else
                        {
                            repalceparent->_right = replace->_right;
                        }
                        delete replace;
                    }
                    return true; // 删除成功
                }
            }
            return false; // 没有找到要删除的节点
        }

        void InOrder()
        {
            InOrder(_root);
            cout << endl;
        }

    private:
        void InOrder(Node *root)
        {
            if (root == nullptr)
                return;
            InOrder(root->_left);
            cout << root->_key << " ";
            InOrder(root->_right);
        }

        void Destroy(Node *root)
        {
            if (root == nullptr)
                return;
            Destroy(root->_left);
            Destroy(root->_right);
            delete root;
        }

        Node *Copy(Node *root)
        {
            if (root == nullptr)
                return nullptr;
            Node *newNode = new Node(root->_key);
            newNode->_left = Copy(root->_left);
            newNode->_right = Copy(root->_right);
            return newNode;
        }

    private:
        Node *_root = nullptr; // 根节点
    };

}