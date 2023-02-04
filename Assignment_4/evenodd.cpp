#include <iostream>
using namespace std;

void even_odd(int *array, int size, int &even_index)
{
    if (size - 1 == 0)
        return;
    int flag = 0;
    if (array[size - 1] % 2 == 0)
    {
        // int i = size - 1;
        // while (i > even_index)
        // {
        //     swap(array[i], array[i - 1]);
        //     i--;
        // }
        while (array[even_index] % 2 != 1 && even_index < size)
            even_index++;
        if (even_index < size)
        {
            swap(array[even_index], array[size - 1]);
            even_index++;
        }
    }
    // if(flag)
    // even_odd(array, size , even_index);
    // else
    even_odd(array, size - 1, even_index);
}

int main()
{
    cout << "Enter the size of array: ";
    int size;
    cin >> size;
    int *array = new int[size];
    cout << "Enter the element of the array: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];
    cout << "Sorting!" << endl;
    int even = 0;
    even_odd(array, size, even);
    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}