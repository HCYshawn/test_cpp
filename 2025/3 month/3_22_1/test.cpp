#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5, 1);
    vector<vector<int>> vv(10, v);

    v.reserve(10);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}