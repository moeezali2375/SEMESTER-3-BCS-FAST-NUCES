#include <math.h>
#include <iostream>
#include "maxheap.h"
using namespace std;

max_heap::max_heap(int size)
{
    array = new int[size];
    current_size = 0;
    this->size = size;
}

max_heap::max_heap(max_heap &s)
{
    if (!array)
        delete[] array;
    array = new int[s.size];
    size = s.size;
    current_size = s.current_size;
}

max_heap::~max_heap()
{
    if (!array)
        delete[] array;
}

void max_heap::insert(int data)
{
    if (current_size == 0)
    {
        array[current_size++] = data;
        return;
    }
    array[current_size++] = data;
    int i = current_size - 1;
    while (i != 0 && array[i] > array[parent(i)])
    {
        swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}

int max_heap::search(int key)
{
    int i = 0;
    while (i < current_size)
    {
        if (array[i] == key)
            return i;
        i++;
    }
    return -1;
}

void max_heap::delete_key(int key)
{

    int i = search(key);
    if (i == -1)
    {
        cout << "No data found!\n";
        return;
    }
    if (i == 0)
    {
        extract_max();
        return;
    }
    array[i] = array[--current_size];
    heapify(i);
}

int max_heap::extract_max()
{
    if (empty())
    {
        cout << "Heap is empty!\n";
        return INT_MAX;
    }
    if (current_size == 1)
    {
        return array[--current_size];
    }
    else
    {
        int return_value = array[0];
        int i = --current_size;
        array[0] = array[i];
        heapify(0);
        return return_value;
    }
}

int max_heap::height()
{
    return (int)log2(current_size);
}

void max_heap::print()
{
    for (int i = 0; i < current_size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int max_heap::parent(int i)
{
    return (i - 1) / 2;
}

int max_heap::left(int i)
{
    return (i * 2) + 1;
}

int max_heap::right(int i)
{
    return (i * 2) + 2;
}

bool max_heap::empty()
{
    if (current_size == 0)
        return 1;
    return 0;
}

void max_heap::heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < current_size && array[l] > array[largest])
        largest = l;
    if (r < current_size && array[r] > array[largest])
        largest = r;
    if (largest != i)
    {
        swap(array[largest], array[i]);
        i = largest;
        heapify(i);
    }
}