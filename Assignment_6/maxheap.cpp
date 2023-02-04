#include <iostream>
#include "minheap.cpp"
using namespace std;

class max_heap
{
    pair<char, int> *array;
    int size;
    int curr_size;
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
        while (i != 0 && array[i].second > array[parent(i)].second)
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
        if (left < curr_size && array[left].second > array[smallest].second)
            smallest = left;
        if (right < curr_size && array[right].second > array[smallest].second)
            smallest = right;
        if (smallest != i)
        {
            swap(array[smallest], array[i]);
            i = smallest;
            heapify_down(i);
        }
    }

public:
    max_heap()
    {
        size = 1;
        array = new pair<char, int>[1];
        curr_size = 0;
    }
    ~max_heap()
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
        while (curr_size >= size)
            grow();
        array[curr_size].first = a;
        array[curr_size].second = b;
        curr_size++;
        if (curr_size == 0)
            return;
        else
        {
            int i = curr_size - 1;
            if (array[i].first == 0)
                heapify_up(i);
        }
    }
    bool isEmpty()
    {
        if (curr_size == 0)
            return 1;
        return 0;
    }
    bool get_max(pair<char, int> &a)
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
    void display_max_heap()
    {
        for (int i = 0; i < curr_size; i++)
        {
            cout << array[i].first << " " << array[i].second << endl;
        }
    }
    int top()
    {
        return array[0].second;
    }
    bool path_append(int i, char symbol, int value, string &a)
    {
        if (i > curr_size)
            return false;
        if (array[i].second == value && array[i].first == symbol)
        {
            // a.push_back(direction);
            return 1;
        }
        // if (array[i].first != 0)
        //     return false;
        if (path_append(left(i), symbol, value, a))
        {
            a.push_back('0');
            return true;
        }
        if (path_append(right(i), symbol, value, a))
        {
            a.push_back('1');
            return true;
        }
        return false;
    }
    void encode_data(max_heap &x_heap, min_heap &m_heap)
    {
        //! Fill Max Heap
        pair<char, int> temp1;
        m_heap.get_min(temp1);
        x_heap.insert(temp1.first, temp1.second);
        int new_pair_freq = temp1.first;

        pair<char, int> temp2;
        while (!m_heap.isEmpty())
        {
            new_pair_freq = x_heap.top();
            m_heap.get_min(temp2);
            new_pair_freq += temp2.second;
            x_heap.insert(temp2.first, temp2.second);
            x_heap.insert(0, new_pair_freq);
        }
        // data.push_path(x_heap);
        // data.display_frequency();
    }
    void store_max_heap(ofstream &fout)
    {
        fout << curr_size << endl;
        for (int i = 0; i < curr_size; i++)
        {
            fout << array[i].second << " ";
        }
        fout << endl;
        for (int i = 0; i < curr_size; i++)
        {
            fout << array[i].first;
        }
        fout << '~' << endl;
    }
    void input_max_heap(ifstream &fin, char array2[])
    {
        int inputs;
        fin >> inputs;
        int *array0 = new int[inputs];
        for (int i = 0; i < inputs; i++)
        {
            fin >> array0[i];
        }
        char *array1 = new char[inputs + 2];
        fin.getline(array1, 10000, '~');
        // for (int i = 2; i < inputs + 2; i++)
        // {
        //     char pta = array1[i];
        //     cout << pta;
        // }
        // cout << "Hdhd";
        char temp[1];
        fin.getline(temp, 1);
        fin.getline(array2, 30000);
        curr_size = inputs;
        while (curr_size > size)
            grow();
        int k = 0;
        int i = 0;
        for (int q = 2; q < inputs + 2; q++)
        {
            char temp;
            int temp2;
            temp = array1[q];
            temp2 = array0[i];
            array[k].first = temp;
            array[k].second = temp2;
            k++;
            i++;
        }
        cout << array2;
    }

    void decode_data(ofstream &fout, char array2[])
    {
        int i = 0;
        int iterator = 0;
        while (array2[i] != 0)
        {
            pair<char, int> temp;
            if (array2[i] == '0')
            {
                iterator = left(iterator);
                temp = get_pair(iterator);
            }
            else if (array2[i] == '1')
            {
                iterator = right(iterator);
                temp = get_pair(iterator);
            }
            if (temp.first != 0)
            {
                fout << temp.first;
                iterator = 0;
            }
            i++;
        }
    }

    pair<char, int> get_pair(int i)
    {
        return array[i];
    }
};