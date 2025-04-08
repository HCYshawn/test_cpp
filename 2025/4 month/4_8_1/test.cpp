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
    };
}

int main()
{
    return 0;
}