#include <vector>
#include <string>
using namespace std;
enum State
{
    EXIST,
    EMPTY,
    DELETE
};

template <class K, class V>
struct HashData
{
    pair<K, V> _kv;
    State _state = EMPTY;
};

template <class K>
struct HashFunc
{
    size_t operator()(const K &key)
    {
        return (size_t)key;
    }
};

template <>
struct HashFunc<string>
{
    size_t operator()(const string &s)
    {
        // BKDR
        size_t hash = 0;
        for (auto ch : s)
        {
            hash += ch;
            hash *= 131;
        }

        return hash;
    }
};

inline unsigned long __stl_next_prime(unsigned long n)
{
    // Note: assumes long is at least 32 bits.
    static const int __stl_num_primes = 28;
    static const unsigned long __stl_prime_list[__stl_num_primes] = {
        53, 97, 193, 389, 769,
        1543, 3079, 6151, 12289, 24593,
        49157, 98317, 196613, 393241, 786433,
        1572869, 3145739, 6291469, 12582917, 25165843,
        50331653, 100663319, 201326611, 402653189, 805306457,
        1610612741, 3221225473, 4294967291};
    const unsigned long *first = __stl_prime_list;
    const unsigned long *last = __stl_prime_list + __stl_num_primes;
    const unsigned long *pos = lower_bound(first, last, n);
    return pos == last ? *(last - 1) : *pos;
}
namespace hcy
{
    template <class K, class V>
    struct HashNode
    {
        pair<K, V> _kv;
        HashNode<K, V> *_next;

        HashNode(const pair<K, V> &kv) : _kv(kv), _next(nullptr) {}
    };

    template <class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
        typedef HashNode<K, V> Node;

    private:
        vector<Node *> _tables;
        size_t _n = 0;

    public:
        HashTable()
            : table(11), _n(0)
        {
        }

        bool Insert(const pair<K, V> &kv)
        {
            if (_n == tables.size())
            {
                vector<Node *> new_table(__stl_next_prime(_n * 2));
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node *cur = _tables[i];
                    while (cur)
                    {
                        Node *next = cur->next;
                        size_t hashi = cur->_kv.first % new_table.size();
                        cur->next = new_table[hashi];
                        new_table[hashi] = cur;

                        cur = next;
                    }

                    _tables[i] = nullptr;
                }

                _tables.swap(new_table);
            }
            size_t hashi = Hash()(kv.first) % _tables.size();

            Node *newnode = new Node(kv);
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_n;
        }
    };
}