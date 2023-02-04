#include <iostream>
using namespace std;
void print_num(int num, int i, int flag)
{
    if (i > num)
    {
        return;
    }
    cout << i << " ";
    if (i == 0)
    {
        cout << i << " ";
        flag = 1;
    }
    if (flag == 1)
        print_num(num, i + 1, flag);
    else
        print_num(num, i - 1, flag);
}
int main()
{
    int num;
    cin >> num;
    print_num(num, num, 0);
}