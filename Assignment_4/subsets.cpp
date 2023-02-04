#include <iostream>
using namespace std;
void subsets(int parent_array[], int new_array[], int size, int r, int I, int i);

void subsets(int parent_array[], int new_array[], int size, int r, int I, int i)
{
    if (I == r)
    {
        for (int j = 0; j < r; j++)
            cout << " " << new_array[j];
        cout << endl;
        return;
    }

    if (i == size)
        return;

    new_array[I] = parent_array[i];
    subsets(parent_array, new_array, size, r, I + 1, i + 1);

    subsets(parent_array, new_array, size, r, I, i + 1);
}

void printCombination(int parent_array[], int size, int r)
{

    int new_array[r];
    subsets(parent_array,new_array, size, r, 0,  0);
}

int main()
{
    int parent_array[] = {1, 2, 3, 4, 5};
    int r = 3;
    cout << sizeof(parent_array[0]) << endl;
    cout << sizeof(parent_array) << endl;
    int size = sizeof(parent_array) / sizeof(parent_array[0]);
    printCombination(parent_array, size, r);
    return 0;
}
