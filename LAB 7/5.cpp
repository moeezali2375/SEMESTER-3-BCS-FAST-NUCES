#include <iostream>
#include <cstring>
using namespace std;
void delete_duplicates(char *array)
{
    if (array[0] == '\0')
        return;
    if (array[0] == array[1])
    {
        int i = 0;
        while (array[i] != 0)
        {
            array[i] = array[i + 1];
            i++;
        }
        delete_duplicates(array);
    }
    delete_duplicates(array + 1);
}
int main()
{
    string name = "moeez";
    char *ptr = &name[0];
    delete_duplicates(ptr);
    cout << name << endl;
}