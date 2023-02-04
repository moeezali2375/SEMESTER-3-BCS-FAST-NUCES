#include <iostream>
#include <cstring>
#include "queue.cpp"
using namespace std;

int get_max(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}

void radixsort(int array[], int size)
{
    int key = 1;
    int max = get_max(array, size);
    while (max / 10 > 0)
    {
        key++;
        max /= 10;
    }
    for (int i = 0; i < key; i++)
    {
        int s = size;
        // queue<int> *queues = new queue<int>[10];
        queue <int> queues[10];
        for (int j = 0; j < size; j++) //300,11,5,20,1104
        {
            int key2 = 0;
            int value = array[j];
            int position = 0;
            while (key2 <= i)
            {
                position = value % 10;
                value /= 10;
                key2++;
            }
            queues[position].enqueue(array[j]);
        }
        int l = 0;
        for (int k = 0; k < size; k++)
        {
            if (queues[l].isEmpty())
            {
                k--;
                l++;
            }
            else
            {
                int new_value = 0;
                queues[l].dequeue(new_value);
                array[k] = new_value;
            }
        }
        delete[] queues;
    }

    cout << "The sorted array is: \n";
    for (int i = 0; i < size; i++)
    {
    :
        cout << array[i] << ",";
    }
    cout << endl;
}

int get_length(string a)
{
    int i = 0;
    while (a[i] != 0)
    {
        i++;
    }
    return i;
}

int get_string_max(string array[], int size)
{
    int max = get_length(array[0]);
    for (int i = 0; i < size; i++)
    {
        if (max < get_length(array[i]))
            max = get_length(array[i]);
    }
    return max;
}

void radixsort_string(string array[], int size)
{
    int key = 1;
    int max = get_string_max(array, size);
    key = max;
    int s = max - 1;
    for (int i = 0; i < key; i++)
    {
        queue<string> *queues = new queue<string>[26];
        for (int j = 0; j < size; j++)
        {
            int position = int(array[j][s]);
            position -= 97;
            queues[position].enqueue(array[j]);
        }
        s--;
        int l = 0;
        for (int k = 0; k < size; k++)
        {
            if (queues[l].isEmpty())
            {
                k--;
                l++;
            }
            else
            {
                string new_value;
                queues[l].dequeue(new_value);
                array[k] = new_value;
            }
        }
        delete[] queues;
    }

    cout << "The sorted array is: \n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;
}

int main()
{
    //===========================
    //
    //  ##  ##     ##  ######
    //  ##  ####   ##    ##
    //  ##  ##  ## ##    ##
    //  ##  ##    ###    ##
    //  ##  ##     ##    ##
    //
    //===========================

    int array_n[] = {300, 11, 5, 20, 1104};
    int size_n = 5;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    radixsort(array_n, size_n);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    //====================================================
    //
    //   ####  ######  #####    ##  ##     ##   ####
    //  ##       ##    ##  ##   ##  ####   ##  ##
    //   ###     ##    #####    ##  ##  ## ##  ##  ###
    //     ##    ##    ##  ##   ##  ##    ###  ##   ##
    //  ####     ##    ##   ##  ##  ##     ##   ####
    //
    //====================================================

    string array[] = {"hello", "arsln", "apple", "hella", "helpp"};
    int size = 5;
    radixsort_string(array, size);


    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}