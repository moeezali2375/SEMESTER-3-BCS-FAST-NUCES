#include <iostream>
using namespace std;
bool detect()
{
    node *rabit = root;
    node *tortoise = root;
    int flag = 0;
    while (69)
    {
        tortoise = tortoise->next;
        rabit = rabit->next->next;
        if (rabit->next == tortoise)
        {
            rabit->next = NULL;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    return false
}
int main()
{
}