#include <iostream>
using namespace std;
bool sum_checker(int *arr, int s)
{
    if (s < 1)
        return false;
    if (s >= 1)
    {
        int i = s;
        int j = 0;
        int k = 0;
        for (; k < s; k++)
        {
            for (j = 0; j < s; j++)
            {
                if (arr[k] + arr[j] == arr[i])
                    return true;
            }
        }
    }
    return sum_checker(arr, s - 1);
}
int main()
{

    int arr[] = {1, 4, 5};
    int s = 3;
    cout << sum_checker(arr, s - 1) << endl;
}