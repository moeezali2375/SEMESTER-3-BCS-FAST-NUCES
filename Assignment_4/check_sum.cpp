#include <iostream>
using namespace std;
bool checksum(int *array, int size)
{
    if (size < 1)
        return false;
    if (size >= 1)
    {
        int i = size;
        int j = 0;
        int k = 0;
        for (; k < size; k++)
        {
            for (j = 0; j < size; j++)
            {
                if (array[k] + array[j] == array[i])
                    return true;
            }
        }
    }
    return checksum(array, size - 1);
}
int main()
{
    int array[] = {0, 2,5};
    int size = 3;
    cout << checksum(array, size-1) << endl;
}