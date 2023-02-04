#include <iostream>
using namespace std;
int count_paths(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    return count_paths(m - 1, n) + count_paths(m, n - 1);
}

int main()
{
    cout << "Enter the position: " << endl;
    int m, n;
    cin >> m >> n;
    cout << "The number of paths are: " << count_paths(m,n) << endl;
}