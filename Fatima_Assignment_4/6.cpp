#include <iostream>
using namespace std;

bool is_safe(int **arr, int s, int r, int c);

bool setting_queens(int **arr, int s, int r)
{
    if (r == s)
        return true;
    for (int j = 0; j < s; j++)
    {
        if (is_safe(arr, s, r, j))
        {
            arr[r][j] = 1;
            if (setting_queens(arr, s, r + 1))
                return true;
            arr[r][j] = 2;
        }
    }
    return false;
}

bool is_safe(int **arr, int s, int r, int c)
{
    int i = 0;
    while (i < s)
    {
        if (arr[i][c] == 1)
            return false;
        i++;
    }
    i = r;
    int j = c;
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j--;
    }
    i = r;
    j = c;
    while (i >= 0 && j < s)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}

int *queen_array(int &s)
{
    cout << "Enter the s: ";
    cin >> s;
    int **arr;
    arr = new int *[s];
    for (int i = 0; i < s; i++)
    {
        arr[i] = new int[s];
        for (int j = 0; j < s; j++)
        {
            arr[i][j] = 0;
        }
    }
    cout << "Setting queens!\n";
    setting_queens(arr, s, 0);
    int *array = new int[s];
    int k = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << arr[i][j] << " ";
            if (arr[i][j] == 1)
                array[k++] = j;
        }
        delete arr[i];
        cout << endl;
    }
    delete[] arr;
    return array;
}

int main()
{
    int s;
    int *array = queen_array(s);
    cout << "Queen position is: " << endl;
    for (int i = 0; i < s; i++)
    {
        cout << "Row " << i + 1 << ": " << array[i] + 1 << endl;
    }
}