#include <iostream>
#include <fstream>
#include "frequency.cpp"
using namespace std;
int main()
{

    //! Declarations
    string input;
    cout << "Enter the name of the file for input: ";
    cin >> input;
    string output;
    cout << "Enter the name of the file for output: ";
    cin >> output;
    ifstream fin(input);
    ofstream fout(output);
    max_heap x_heap;
    char coded_data[30000];

    //! Load Min Heap and data
    x_heap.input_max_heap(fin, coded_data);

    //! Iterate through Code
    x_heap.decode_data(fout, coded_data);
}
