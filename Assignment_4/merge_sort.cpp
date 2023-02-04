#include <iostream>
using namespace std;

void MERGING(int array[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int temp_index = low;

    int *temp_array = new int[high + 1];
    for (int I = 0; I < high + 1; I++)
        temp_array[I] = 0;

    // COMBINING 2 SUBARRAYS INTO ONE
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
            temp_array[temp_index++] = array[i++];
        else
            temp_array[temp_index++] = array[j++];
    }

    // COMBINING left over SUBARRAYS
    while (i <= mid)
        temp_array[temp_index++] = array[i++];
    while (j <= high)
        temp_array[temp_index++] = array[j++];

    // COPYING VALUES INTO THE ORIGINAL ARRAY
    for (int I = low; I <= high; I++)
        array[I] = temp_array[I];

    delete[] temp_array;
    temp_array = NULL;
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        MergeSort(arr, low, middle);
        MergeSort(arr, middle + 1, high);
        MERGING(arr, low, middle, high);
    }
}

int main()
{
    cout << 5 / 2 << endl;
    int array[] = {9, 24, 56, 4, 10, 39};
    int size = 6;
    cout << "The original array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    MergeSort(array, 0, size - 1);
    cout << "MERGING!" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}