#include <iostream>
#include <math.h>
#include "minheap.h"
using namespace std;

min_heap::min_heap(int size)
{
    this->size = size;
    current_size = 0;
    array = new int[size];
}

min_heap::min_heap(min_heap &s)
{
    if (!this->array)
        delete[] array;
    this->size = s.size;
    this->current_size = s.current_size;
}

min_heap::~min_heap()
{
    if (!array)
        delete[] array;
}

void min_heap::insert(int data)
{
    if (current_size == size)
    {
        cout << "Size full!\n";
        return;
    }
    if (current_size == 0)
    {
        array[current_size++] = data;
        return;
    }
    array[current_size++] = data;
    int i = current_size - 1;
    while (i != 0 && array[i] <= array[parent(i)])
    {
        swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}

int min_heap::search(int key)
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

void min_heap::delete_key(int key)
{
    int i = search(key);
    if (i == -1)
    {
        cout << "No data found!\n";
        return;
    }
    if (i == 0)
    {
        extract_min();
        return;
    }
    current_size--;
    array[i] = array[current_size];
    heapify(i);
}

int min_heap::extract_min()
{
    if (empty())
    {
        cout << "Heap is empty!\n";
        return INT16_MAX;
    }
    if (current_size == 1)
        return array[current_size--];
    int min_value = array[0];
    current_size--;
    array[0] = array[current_size];
    heapify(0);
    return min_value;
}

int min_heap::height()
{
    return (int)log2(current_size);
}

void min_heap::print()
{
    for (int i = 0; i < current_size; i++)
        cout << array[i] << "|";
    cout << endl;
}

int min_heap::parent(int i)
{
    return (i - 1) / 2;
}

int min_heap::left(int i)
{
    return (i * 2) + 1;
}

int min_heap::right(int i)
{
    return (i * 2) + 2;
}

bool min_heap::empty()
{
    if (current_size == 0)
    {
        return 1;
    }
    return 0;
}

void min_heap::heapify(int i)
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
        heapify(i);
    }
}
