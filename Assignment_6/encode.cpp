#include <iostream>
#include <fstream>
#include "frequency.cpp"
//hehebilli5499

using namespace std;
int main()
{

    string file_name;
    cout << "Enter the name of input file: ";
    cin >> file_name;
    string binary_file_name;
    cout << "Enter the name of binary file: ";
    cin >> binary_file_name;

    ifstream fin(file_name);
    ofstream fout(binary_file_name);
    // ifstream fin("input.txt");
    // ofstream fout("coded.txt");

    //! DECLARATIONs
    char array[5000];
    frequency data;
    min_heap m_heap;
    max_heap x_heap;

    // DRIVERS
    fin.getline(array, 5000);
    cout << array << endl;
    data.fill_frequency_values(array);

    //! Min Heap Insert
    {
        int i = 0;
        while (i < data.curr_size)
        {
            m_heap.insert(data.letter[i], data.freq[i]);
            i++;
        }
    }

    //! Max Heap Conversion into binary tree
    {
        x_heap.encode_data(x_heap, m_heap);
        cout << "Max: " << endl;
        x_heap.display_max_heap();
        cout << "Frequency: " << endl;
    }

    //! Store Max Heap into File
    {
        x_heap.store_max_heap(fout);
    }

    //! Code Path
    {
        data.push_path(x_heap);
        data.display_frequency();
    }

    //! Convert to Binary Code
    {
        int i = 0;
        while (array[i] != 0)
        {
            string temp = data.find_code(array[i]);
            fout << temp;
            i++;
        }
    }
}

