#include <iostream>
using namespace std;
static int a = 0;
bool palindrome(string name, float i, float size)
{
    a++;
    if (i >= size)
        return true;
    if (name[i] == name[size])
    {
        if (palindrome(name, i + 1, size - 1))
            return true;
    }
    return false;
}

int main()
{
    string name = "peep";
    float i = 0;
    int size = 3;
    cout << palindrome(name, i, size);
}