#include <iostream>
#include "minheap.h"
#include "minheap.cpp"
using namespace std;
template <typename T>
void heap_sort()
{
    cout << "Enter the size of the array you want to heap sort: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the array: ";
    T *array = new T[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    cout << "The data you have entered is: ";

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "Select the sorting order!: ";
    int sorting_order;
    cin >> sorting_order;
    min_heap<T> obj(array, size);
    if (!sorting_order)
    {
        int i = 0;
        while (i < size)
        {
            array[i] = obj.extract_min();
            i++;
        }
    }
    else
    {
        int i = size - 2;
        while (i >= 0)
        {
            array[i] = obj.extract_min();
            i--;
        }
    }
    cout << "The data in the sorted array is: ";
    for (int i = 0; i < size - 1; i++)
        cout << array[i] << " ";
    cout << array << endl;
    delete[] array;
}
int main()
{
    int array[] = {10, 4, 5, 30, 3, 300};
    min_heap<int> obj(array, 6);
    obj.insert(9);
    obj.print();
    for (int i = 0; i < 3; i++)
    {
        cout << obj.extract_min() << endl;
    }
    obj.print();
    obj.delete_key(300);
    obj.print();
    heap_sort<int>();
    //  obj.insert(20);
    //  obj.insert(30);
    //  obj.insert(40);
}