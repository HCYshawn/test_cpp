#include <iostream>
#include <vector>
using namespace std;

enum EntryStatus
{
    ACTIVE,
    EMPTY,
    DELETED
};

template <class K>
class HashTable
{
private:
    struct HashEntry
    {
        K key;
        EntryStatus status = EMPTY;
    };

    vector<HashEntry> table;
    int capacity;
    int size;

    int hashFunction(const K &key) const
    {
        return key % capacity;
    }

    int linearProbe(int index) const
    {
        return (index + 1) % capacity;
    }

public:
    HashTable(int tableSize = 11) : capacity(tableSize), size(0)
    {
        table.resize(capacity);
    }

    bool insert(const K &key)
    {
        if (size >= capacity)
        {
            return false;
        }

        int index = hashFunction(key);
        int startIndex = index;

        do
        {
            if (table[index].status != ACTIVE)
            {
                table[index].key = key;
                table[index].status = ACTIVE;
                size++;
                return true;
            }
            index = linearProbe(index);
        } while (index != startIndex);

        return false;
    }

    bool search(K key, int &pos) const
    {
        int index = hashFunction(key);
        int startIndex = index;

        do
        {
            if (table[index].status == ACTIVE && table[index].key == key)
            {
                pos = index;
                return true;
            }
            if (table[index].status == EMPTY)
                break;
            index = linearProbe(index);
        } while (index != startIndex);

        return false;
    }

    bool remove(K key)
    {
        int pos;
        if (search(key, pos))
        {
            table[pos].status = DELETED;
            size--;
            return true;
        }
        return false;
    }

    void print() const
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << "[" << i << "]: ";
            if (table[i].status == ACTIVE)
                cout << table[i].key;
            else if (table[i].status == DELETED)
                cout << "DELETED";
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};