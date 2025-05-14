#include <iostream>
#include <memory>
using namespace std;

class NetworkConnection
{
public:
    NetworkConnection()
    {
        cout << "NetworkConnection created" << endl;
    }

    ~NetworkConnection()
    {
        cout << "NetworkConnection destroyed" << endl;
    }
};

int main()
{
    shared_ptr<NetworkConnection> conn1(new NetworkConnection());
    {
        auto conn2 = conn1;
        cout << "sum: " << conn1.use_count() << endl;
    }
    cout << "sum: " << conn1.use_count() << endl;
    return 0;
}