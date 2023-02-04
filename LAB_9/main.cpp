#include "AVL.h"
#include "AVL.cpp"
using namespace std;
int main()
{
    AVL tree;

    tree.insert_node(5);
    tree.insert_node(3);
    tree.insert_node(4);
    // tree.print2d();
    // cout << " \t" << endl;
    // tree.delete_node(45);
    // tree.print2d();

    int choice = -1;
    do
    {
        int data;
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print\n";
        cout << "0. Exit\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the data to insert: ";
            cin >> data;
            tree.insert_node(data);
        }
        if (choice == 2)
        {
            cout << "Enter the data to delete: ";
            cin >> data;
            tree.delete_node(data);
        }
        if (choice == 3)
        {
            tree.print2d();
        }
        if (choice == 0)
        {
            cout << "Program closed!\n";
            break;
        }
    } while (choice != 0);
}
