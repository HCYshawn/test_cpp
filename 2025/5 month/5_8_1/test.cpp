#include <iostream>
using namespace std;

int main()
{
    typedef int &lref;
    typedef int &&rref;

    int n = 0;
    lref &r1 = n;
    lref &&r2 = n;
    rref &r3 = n;
    rref &&r4 = 1;

    cout << "lref: " << r1 << endl; // lref: 0
    cout << "lref: " << r2 << endl; // lref: 0
    cout << "rref: " << r3 << endl; // rref: 0
    cout << "rref: " << r4 << endl; // rref: 1

    return 0;
}