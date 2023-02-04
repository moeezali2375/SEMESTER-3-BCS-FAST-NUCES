#include <iostream>
#include <list>
using namespace std;

class HASH
{
    int table_size;
    list<int> *array;

public:
    HASH(int size)
    {
        array = new list<int>[size];
        table_size = size;
    }
    void insert(int data)
    {
        int index = data % table_size; //! determines the index location in the table
        array[index].push_front(data);
    }
    bool search(int key)
    {
        int index = key % table_size; //! determines the index location in the table
        for (auto j = array[index].begin(); j != array[index].end(); j++)
        {
            if (*j == key)
                return true;
        }
        return false;
    }
    void remove(int key)
    {
        int index = key % table_size; //! determines the index location in the table
        // If an element is there in the list below command will automatically search and delete it from the list!
        //! EXCEPTION CASE not HANDLED!
        array[index].remove(key);
    }
    void display_table()
    {
        for (int i = 0; i < table_size; i++)
        {
            for (auto j = array[i].begin(); j != array[i].end(); j++)
            {
                cout << *j << "->";
            }
            cout << endl;
        }
    }
};
int main()
{
    HASH table(5);
    table.insert(2);
    table.insert(10);
    table.insert(11);
    table.insert(13);
    table.insert(14);
    table.display_table();
    int choice;
    int key;
    do
    {
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "0. EXIT\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the key: ";
            cin >> key;
            table.insert(key);
            break;
        case 2:
            cout << "Enter the key: ";
            cin >> key;
            if (table.search(key))
                cout << "Element is in the HASH TABLE!\n";
            else
                cout << "No key found in HASH MAP!\n";
            break;
        case 3:
            cout << "Enter the key: ";
            cin >> key;
            table.remove(key);
            break;
        case 4:
            cout << "HASH-MAP: \n";
            table.display_table();
            break;
        case 0:
            cout << "Program Closed Successfully!\n";
            choice = 96;
            break;
        default:
            cout << "Invalid choice, Enter again!\n";
            break;
        }
    } while (choice != 96);
}