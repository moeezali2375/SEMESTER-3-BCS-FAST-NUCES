#include <iostream>
#include<math.h>
#include <string>
using namespace std;
void print01(int k, int i = 0)
{
    if (i == pow(2, k))
        return;
    string str;
    for (int i = 0; i < k; i++)
        str.push_back('0');
    for (int j = i, a = k - 1; j != 0; j /= 2, --a)
        str[a] = (char)(j % 2 + 48);
    cout << "\n"<< str;
    print01(k, i + 1);
}
int main()
{
    int k;
    cout << "Enter any number to print 0/1 ";
    cin >> k;

    print01(k);
}