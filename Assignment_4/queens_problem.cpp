#include <iostream>
using namespace std;

bool is_saaf_rasta(int **array, int size, int row, int col)
{
    int i = 0;
    while (i < size)
    {
        if (array[i][col] == 1)
            return false;
        i++;
    }
    i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        if (array[i][j] == 1)
            return false;
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i >= 0 && j < size)
    {
        if (array[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}

bool place_queens(int **array, int size, int row)
{
    if (row == size)
        return true;
    for (int j = 0; j < size; j++)
    {
        if (is_saaf_rasta(array, size, row, j))
        {
            array[row][j] = 1;
            if (place_queens(array, size, row + 1))
                return true;
            array[row][j] = 2;
        }
    }
    return false;
}

int *queen_array(int &size)
{
    cout << "Enter the size of the board: ";
    cin >> size;
    int **array;
    array = new int *[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            array[i][j] = 0;
        }
    }
    cout << "Placing queens in the board!\n";
    place_queens(array, size, 0);
    int *column_array = new int[size];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << array[i][j] << " ";
            if (array[i][j] == 1)
                column_array[k++] = j;
        }
        delete array[i];
        cout << endl;
    }
    delete[] array;
    return column_array;
}

int main()
{
    int size;
    int *column_array = queen_array(size);
    cout << "The columns in which the queen is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Row " << i + 1 << ": " << column_array[i] + 1 << endl;
    }
}