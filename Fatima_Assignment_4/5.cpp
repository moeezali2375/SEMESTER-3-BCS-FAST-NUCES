#include <iostream>
using namespace std;
void MERGE(int arr[], int low, int medium, int high);

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        MergeSort(arr, low, middle);
        MergeSort(arr, middle + 1, high);
        MERGE(arr, low, middle, high);
    }
}

void MERGE(int arr[], int low, int medium, int high)
{
    int *temp = new int[high];
    for (int i = 0; i < high; i++)
        temp[i] = 0;

    int start = low;
    int temp_ptr = low;
    int middle_index = medium;
    medium++;
    // this loop will combine 2 sub_arrays into a single sorted array and will break if a smaller sub_array is finished!
    while (low <= middle_index && medium <= high)
    {
        if (arr[low] < arr[medium])
        {
            temp[temp_ptr] = arr[low];
            temp_ptr++;
            low++;
        }
        else
        {
            temp[temp_ptr] = arr[medium];
            temp_ptr++;
            medium++;
        }
    }
    // these two loops will combine subarray if they were sorted and left from the above while loop
    while (low <= middle_index)
    {
        temp[temp_ptr] = arr[low];
        temp_ptr++;
        low++;
    }
    while (medium <= high)
    {
        temp[temp_ptr] = arr[medium];
        temp_ptr++;
        medium++;
    }

    for (int i = start; i <= high; i++)
    {
        arr[i] = temp[i];
    }
    delete[] temp;
}

int main()
{
    int arr[] = {5, 1, 6, 4, 0, 9};
    int size = 6;
    cout << "The array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    MergeSort(arr, 0, size - 1);
    cout << "Calling merge sort!" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}