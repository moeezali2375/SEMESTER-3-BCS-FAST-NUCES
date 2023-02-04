//=======================================
//
//              #####    ####  ######
//              ##  ##  ##       ##
//              #####    ###     ##
//              ##  ##     ##    ##
//              #####   ####     ##
//
//=======================================
#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
    BST tree;
    tree.insertion(5);
    tree.insertion(10);
    tree.insertion(4);
    tree.insertion(3);

    int choice;
    do
    {
        cout << "0. Exit!\n";
        cout << "1. Insertion!\n";
        cout << "2. Deletion!\n";
        cout << "3. Search!\n";
        cout << "4. Print!\n";
        cout << "5. Height!\n";
        cout << "6. Number of nodes!\n";
        cout << "7. Leaf Nodes!\n";
        cout << "8. Print 2D!\n";
        cin >> choice;
        if (choice == 0)
        {
            cout << "Program Closed!\n";
            choice = 0;
        }
        else if (choice == 1)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            tree.insertion(key);
        }
        else if (choice == 2)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            tree.deletion(key);
        }
        else if (choice == 3)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            int index = tree.search(key);
            cout << "The data is at the index: " << index << endl;
        }
        else if (choice == 4)
        {
            tree.in_order();
            tree.post_order();
            tree.pre_order();
        }
        else if (choice == 5)
        {
            cout << "The height of the tree is: " << tree.get_height() << endl;
        }
        else if (choice == 6)
        {
            // 0 height is for root node
            int height;
            cout << "Enter the height: ";
            cin >> height;
            cout << "The number of the nodes in the height are: " << tree.get_level(height);
            cout << endl;
        }
        else if (choice == 7)
        {
            cout << "The number of leaf nodes are: " << tree.leaf_nodes() << endl;
        }
        else if (choice == 8)
        {
            cout << "Printing in 2D: ";
            tree.print2d(0, 5);
        }

    } while (choice != 0);
}