#include <iostream>
using namespace std;
int count_paths(int rows, int columns)
{
    if (rows == 1 || columns == 1)
        return 1;
    return count_paths(rows - 1, columns) + count_paths(rows, columns - 1);
}

int main()
{
    int rows, columns;
    cout << "Position: " << endl;
    cin >> rows >> columns;
    cout << "The paths are: " << count_paths(rows, columns) << endl;
}
