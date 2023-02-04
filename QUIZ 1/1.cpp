#include <iostream>
using namespace std;
int one_counter(int n)
{
    int counter = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
            counter++;
        n = n / 2;
    }
    return counter;
}

int main()
{
    cout << "Enter the integer: ";
    int n;
    cin >> n;
    cout << "[";
    for (int i = 0; i <= n; i++)
    {
        cout << one_counter(i) << ",";
    }
    cout << "]" << endl;
}
