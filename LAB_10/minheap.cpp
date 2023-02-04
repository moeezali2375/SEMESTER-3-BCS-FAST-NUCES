#include <iostream>
#include <vector>
#include <math.h>
#include "minheap.h"
using namespace std;
template <typename T>
min_heap<T>::min_heap(int size)
{
    this->size = size;
    current_size = 0;
}
template <typename T>
min_heap<T>::min_heap(T *array, int s) : array(s)
{
    this->size = s;
    current_size = 0;
    for (int i = 0; i < size; i++)
        this->insert(array[i]);
}
template <typename T>
min_heap<T>::~min_heap()
{
    // if (array!=NULL)
    //     delete[] array;
    ;
}
template <typename T>
void min_heap<T>::insert(T data)
{
    // if (current_size == size)
    // {
    //     cout << "Size full!\n";
    //     return;
    // }
    if (current_size == 0)
    {
        array[0] = data;
        current_size++;
        return;
    }
    array[current_size++] = data;
    int i = current_size - 1;
    heapify_up(i);
}
template <typename T>
int min_heap<T>::search(T key)
{
    return search(0, key);
}
template <typename T>
int min_heap<T>::search(int i, T key)
{
    if (i <= current_size)
    {
        if (array[i] == key)
            return i;
        if (key < array[i])
        {
            return search(left(i), key);
        }
        else
            return search(right(i), key);
    }
    return -1;
}

template <typename T>
void min_heap<T>::delete_key(int key)
{
    int i = search(key);
    if (i == -1)
    {
        // cout << "No data found!\n";
        return;
    }
    if (i == 0)
    {
        extract_min();
        return;
    }
    current_size--;
    array[i] = array[current_size];
    heapify_down(i);
    if (i != -1)
        delete_key(key);
}

template <typename T>
T min_heap<T>::get_min()
{
    return array[0];
}

template <typename T>
T min_heap<T>::extract_min()
{
    if (empty())
    {
        cout << "Heap is empty!\n";
        return INT16_MAX;
    }
    if (current_size == 1)
        return array[--current_size];
    int min_value = array[0];
    current_size--;
    array[0] = array[current_size];
    heapify_down(0);
    return min_value;
}
template <typename T>
int min_heap<T>::height()
{
    return (int)log2(current_size);
}
template <typename T>
void min_heap<T>::print()
{
    for (int i = 0; i < current_size; i++)
        cout << array[i] << "|";
    cout << endl;
}
template <typename T>
int min_heap<T>::parent(int i)
{
    return (i - 1) / 2;
}
template <typename T>

int min_heap<T>::left(int i)
{
    return (i * 2) + 1;
}
template <typename T>

int min_heap<T>::right(int i)
{
    return (i * 2) + 2;
}
template <typename T>

bool min_heap<T>::empty()
{
    if (current_size == 0)
    {
        return 1;
    }
    return 0;
}
template <typename T>
void min_heap<T>::heapify_down(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < current_size && array[smallest] > array[l])
        smallest = l;
    if (r < current_size && array[smallest] > array[r])
        smallest = r;
    if (smallest != i)
    {
        swap(array[smallest], array[i]);
        i = smallest;
        heapify_down(i);
    }
}
template <typename T>
void min_heap<T>::heapify_up(int i)
{
    while (i != 0 && array[i] < array[parent(i)])
    {
        swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}
