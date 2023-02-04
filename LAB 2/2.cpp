#include <iostream>
#include "1.cpp"
using namespace std;

int main()
{
    int arr[100];
    int index[100];
    cout << "Enter the Number of Dimensions: " << endl;
    int dimensions = 0;
    cin >> dimensions;
    cout << "Enter the Numbers in each Dimension: " << endl;
    for (int i = 0; i < dimensions; i++)
        cin >> arr[i];

    ndArray<int> obj(arr, dimensions);
    cout << "The Initialized Array is : " << endl;
    cout << obj << endl;
    cout << "Enter Index for the Number to be Inserted: " << endl;
    for (int i = 0; i < dimensions; i++)
    {
        cin >> index[i];
    }
    cout << "Enter Number to be Inserted: ";
    int num;
    cin >> num;
    obj.Insert(num, index);
    cout << endl
         << "Inserted Array is : " << endl
         << obj;
    cout << "Deleted Array is : " << endl;
    obj.Delete(5);
    cout << obj << endl;
    cout << "Extended Array is : " << endl;
    obj.Extend();
    cout << obj << endl;
    cout << "Shrinked Array is : " << endl;
    obj.Shrink();
    cout << obj << endl;
    ndArray<int> obj2(obj);
    cout << "Copied Obj is : " << endl;
    cout << obj2 << endl;
    cout << endl;
    return 0;
}