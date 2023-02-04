#include <iostream>
#include "minheap.h"
#include "minheap.cpp"
using namespace std;
int main()
{
    int choice;
    int key;
    min_heap heep(10);
    heep.insert(6);
    heep.insert(33);
    heep.insert(21);
    heep.insert(40);
    heep.insert(50);
    heep.insert(27);
    heep.insert(66);
    heep.insert(81);
    heep.insert(75);
    do
    {
        cout << "Please select a choice!\n";
        cout << "0. Exit\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Extract Min\n";
        cout << "5. Height of Heap\n";
        cout << "6. Print\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            choice = 0;
            break;
        case 1:
            cout << "Enter the data you want to insert: ";
            cin >> key;
            heep.insert(key);
            break;
        case 2:
            cout << "Enter the data you want to search: ";
            cin >> key;
            cout << "The data is at the index: " << heep.search(key) << endl;
            break;
        case 3:
            cout << "Enter the data you want to delete: ";
            cin >> key;
            heep.delete_key(key);
            break;
        case 4:
            cout << "The minimum element is: ";
            cout << heep.extract_min() << endl;
            break;
        case 5:
            cout << "The height of the tree is: ";
            cout << heep.height() << endl;
            break;
        case 6:
            cout << "The current heap structure is: \n";
            heep.print();
            break;
        default:
            cout << "Select a valid choice!\n";
            break;
        }

    } while (choice != 0);
    cout << "Program closed successfully!\n";
    return 0;
}