#include <iostream>
#include <memory>
using namespace std;

class FileHandler
{
public:
    FileHandler()
    {
        cout << "file open" << endl;
    }
    ~FileHandler()
    {
        cout << "file close" << endl;
    }
};

int main()
{
    unique_ptr<int[]> arr = make_unique<int[]>(10);
    arr[0] = 10;

    auto fileDeleter = [](FILE *f)
    {
        if (f)
        {
            fclose(f);
            cout << "file release" << endl;
        }
    };

    unique_ptr<FILE, decltype(fileDeleter)> filePtr(fopen("test.txt", "w"), fileDeleter);
    return 0;
}