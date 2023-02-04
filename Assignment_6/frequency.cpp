#include <iostream>
#include <string>
#include "maxheap.cpp"
using namespace std;
class frequency
{
public:
    char *letter;
    int *freq;
    string *path;
    int size;
    int curr_size;

    frequency()
    {
        letter = new char[1];
        freq = new int[1];
        path = new string[1];
        size = 1;
        curr_size = 0;
    }
    ~frequency()
    {
        // delete[] path;
        delete[] letter;
        delete[] freq;
    }
    void grow_array()
    {
        int new_size = size * 2;
        char *new_letter = new char[new_size];
        int *new_freq = new int[new_size];
        string *new_path = new string[new_size];
        for (int i = 0; i < size; i++)
        {
            new_letter[i] = letter[i];
            new_freq[i] = freq[i];
            new_path[i] = path[i];
        }
        size = new_size;
        delete[] letter;
        delete[] freq;
        delete[] path;
        letter = new_letter;
        freq = new_freq;
        path = new_path;
    }
    void push_letter_freq(char a, int f)
    {
        if (curr_size == size)
            grow_array();
        letter[curr_size] = a;
        freq[curr_size] = f;
        curr_size++;
    }
    void display_frequency()
    {
        for (int i = 0; i < curr_size; i++)
        {
            cout << letter[i] << "  " << freq[i] << " " << path[i] << endl;
        }
    }
    bool check_back(char array[], int current)
    {
        char value = array[current];
        current--;
        while (current >= 0)
        {
            if (array[current] == value)
                return false;
            current--;
        }
        return true;
    }
    int count_forward(char array[], int current)
    {
        char value = array[current];
        current++;
        int frequency = 1;
        while (array[current] != 0)
        {
            if (array[current] == value)
            {
                frequency++;
            }
            current++;
        }
        return frequency;
    }
    void fill_frequency_values(char array[])
    {
        int i = 0;
        while (array[i] != 0)
        {
            if (check_back(array, i))
            {
                push_letter_freq(array[i], count_forward(array, i));
            }
            i++;
        }
    }
    void push_path(max_heap &s)
    {
        int i = 0;
        while (i < curr_size)
        {
            char temp = letter[i];
            int temp2 = freq[i];
            string temp3;
            s.path_append(0, temp, temp2, temp3);
            reverse(temp3.begin(), temp3.end());
            path[i] = temp3;
            i++;
        }
    }
    string find_code(char a)
    {
        for (int i = 0; i < curr_size; i++)
        {
            if (letter[i] == a)
                return path[i];
        }
        return NULL;
    }
};
