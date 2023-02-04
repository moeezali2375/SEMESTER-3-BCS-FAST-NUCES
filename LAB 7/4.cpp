#include <iostream>
using namespace std;

float factorial(float num)
{
    if (num == 0 || num == 1)
        return 1;
    else
    {
        return num * factorial(num - 1);
    }
}

float C(float n, float r)
{
    float temp = factorial(n - r);
    n = factorial(n);
    r = factorial(r);
    temp = temp * r;
    return n / temp;
}

int main()
{
    cout << C(5, 3);
}