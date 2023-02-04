#include <iostream>
using namespace std;

void sorting(int *arr, int size, int &e)
{
    if (size - 1 == 0)
        return;
    int flag = 0;
    if (arr[size - 1] % 2 == 0)
    {
        while (arr[e] % 2 == 0 && e < size)
            e++;
        if (e < size)
            swap(arr[e++], arr[size - 1]);
    }
    sorting(arr, size - 1, e);
}

int main()
{
    int size;
    int *arr;
    cout << "Enter the size: ";
    cin >> size;
    arr = new int[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int e = 0;
    sorting(arr, size, e);
    cout << "Calling sorting function!" << endl;
    cout << "The sorted arr is: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}