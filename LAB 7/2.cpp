#include <iostream>
using namespace std;

void putCommas(string &value, int i, int size)
{
    if (size == 0)
        return;
    if (i == 3)
    {
        i = 0;
        value.insert(size, ",");
    }
    putCommas(value, i + 1, size - 1);
}

int main()
{
    string value = "123456";
    cout << value << endl;
    putCommas(value, 0, 6);
    cout << value << endl;
}