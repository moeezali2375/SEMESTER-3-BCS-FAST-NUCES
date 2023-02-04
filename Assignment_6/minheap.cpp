#include <iostream>
using namespace std;

class min_heap
{
    pair<char, int> *array;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (i * 2) + 1;
    }
    int right(int i)
    {
        return (i * 2) + 2;
    }
    void heapify_up(int i)
    {
        while (i != 0 && array[i].second <= array[parent(i)].second)
        {
            swap(array[i], array[parent(i)]);
            i = parent(i);
        }
    }
    void heapify_down(int i)
    {
        int smallest = i;
        int left = this->left(i);
        int right = this->right(i);
        if (left < curr_size && array[left].second < array[smallest].second)
            smallest = left;
        if (right < curr_size && array[right].second < array[smallest].second)
            smallest = right;
        if (smallest != i)
        {
            swap(array[smallest], array[i]);
            i = smallest;
            heapify_down(i);
        }
    }

public:
    int size;
    int curr_size;
    min_heap()
    {
        size = 1;
        array = new pair<char, int>[1];
        curr_size = 0;
    }
    ~min_heap()
    {
        delete[] array;
    }
    void grow()
    {
        int new_size = size * 2;
        pair<char, int> *new_pair = new pair<char, int>[new_size];
        for (int i = 0; i < size; i++)
        {
            new_pair[i] = array[i];
        }
        delete[] array;
        array = new_pair;
        size = new_size;
    }
    void insert(char a, int b)
    {
        if (curr_size == size)
            grow();
        array[curr_size].first = a;
        array[curr_size].second = b;
        curr_size++;
        if (curr_size == 0)
            return;
        else
        {
            int i = curr_size - 1;
            heapify_up(i);
        }
    }
    bool isEmpty()
    {
        if (curr_size == 0)
            return 1;
        return 0;
    }
    bool get_min(pair<char, int> &a)
    {
        if (!isEmpty())
        {
            a = array[0];
            array[0] = array[--curr_size];
            heapify_down(0);
            return 1;
        }
        return 0;
    }
    void display_min_heap()
    {
        for (int i = 0; i < curr_size; i++)
        {
            cout << array[i].first << " " << array[i].second << endl;
        }
    }
};

// int main()
// {
//     min_heap a;
//     a.insert(0, 5);
//     a.insert('a', 5);
//     a.insert('c', 5);
//     a.insert('d', 1);
//     a.display_min_heap();
//     cout << endl;
//     pair<char, int> b;
//     a.get_min(b);
//     a.get_min(b);
//     a.get_min(b);
//     a.display_min_heap();
// }