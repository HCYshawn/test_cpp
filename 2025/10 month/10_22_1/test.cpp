#include "yx.hpp"

int main()
{
    Citation *a = new Citation();
    a->SetInfo("hehe", "man", "1");
    a->SetAwardsInfo("abcd", "@");
    a->Display();

    cout << endl;

    Citation *b = (Citation *)a->Clone();
    b->SetInfo("hoho", "woman", "2");
    b->SetAwardsInfo("efgh", "!");
    b->Display();

    delete a;
    delete b;
    return 0;
}