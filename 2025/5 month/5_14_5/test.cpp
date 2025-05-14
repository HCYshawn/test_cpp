#include <iostream>
#include <memory>
using namespace std;

class Teacher;
class Student
{
public:
    shared_ptr<Teacher> teacher;
    ~Student()
    {
        cout << "Student destructor" << endl;
    }
};

class Teacher
{
public:
    shared_ptr<Student> student;
    ~Teacher()
    {
        cout << "Teacher destructor" << endl;
    }
};

int main()
{
    auto student = make_shared<Student>();
    auto teacher = make_shared<Teacher>();
    student->teacher = teacher;
    teacher->student = student;

    return 0;
}