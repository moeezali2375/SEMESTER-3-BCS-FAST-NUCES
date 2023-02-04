
//====================================================
//
//              ###    ###    ###    ##  ##     ##
//              ## #  # ##   ## ##   ##  ####   ##
//              ##  ##  ##  ##   ##  ##  ##  ## ##
//              ##      ##  #######  ##  ##    ###
//              ##      ##  ##   ##  ##  ##     ##
//
//====================================================
#include <iostream>
#include "BST.h"
#include "BST.cpp"
using namespace std;
int main()
{
    BST tree;
    int answer = 0;
    tree.insert(25);
    tree.insert(8);
    tree.insert(43);
    tree.insert(3);
    tree.insert(15);
    tree.insert(27);
    tree.insert(65);
    tree.insert(19);
    // CASE2:
    //  tree.insert(50);
    //  tree.insert(40);
    //  tree.insert(30);
    //  tree.insert(20);
    //  tree.insert(35);

    int check = -1;

    Node *temp2 = nullptr;
    Node *temp = nullptr;
    while (check != 0)
    {
        //!
        cout << "1. Insert\n";
        cout << "2. In Order Print\n";
        cout << "3. Level Order Print\n";
        cout << "4. Search\n";
        cout << "5. Count Nodes\n";
        cout << "6. Leaf Count\n";
        cout << "7. Print Graphically\n";
        cout << "8. Height\n";
        cout << "9. Copy Constructor\n";
        cout << "10. Deletion\n";
        cout << "0. Exit\n";
        cin >> check;
        if (check == 1)
        {
            int data;
            cout << "Enter the data you want to insert: ";
            cin >> data;
            if (tree.insert(data))
                cout << "Data inserted successfully!\n";
            else
                cout << "Data not inserted\n";
        }
        else if (check == 2)
        {
            cout << "In order Printing!" << endl;
            temp = tree.get_root();
            tree.in_order_printing(temp);
            cout << "\n";
        }
        else if (check == 3)
        {
            cout << "Level order printing\n";
            temp = tree.get_root();
            tree.level_order_printing(temp);
        }
        else if (check == 4)
        {
            int data;
            cout << "Enter the data you want to search for: ";
            cin >> data;
            temp = tree.search(data);
            if (temp != nullptr)
            {
                cout << "Data found\n";
                cout << temp << endl;
            }
            else
                cout << "No data found\n";
        }
        else if (check == 5)
        {
            cout << "Counting nodes\n";
            temp = tree.get_root();
            cout << "The nodes in the binary tree are: " << tree.countNodes(temp) << endl;
        }
        else if (check == 6)
        {
            cout << "Counting leafs\n";
            temp = tree.get_root();
            cout << "Total leaves of the tree are: " << tree.leafCount(temp) << endl;
        }
        else if (check == 7)
        {
            cout << "Printing graphical representation!\n";
            temp = tree.get_root();
            tree.print2d(temp, 5);
        }
        else if (check == 8)
        {
            cout << "Height\n";
            temp = tree.get_root();
            cout << "The maximum height of the tree is: " << tree.height(temp) << endl;
        }
        else if (check == 9)
        {
            BST tree2 = tree;
            cout << "Checking copy constructor\n";
            cout << "Tree 2: " << endl;
            tree2.print2d(tree2.get_root(), 5);
        }
        else if (check == 10)
        {
            int data;
            cout << "Deletion\n";
            cout << "Enter the data you want to delete: ";
            cin >> data;
            temp = tree.get_root();
            temp2 = NULL;
            tree.delete_node(temp, temp2, data);
        }
        else if (check == 0)
        {
            cout << "Checking destructor\n";
            break;
        }
        else if (check == 11)
        {
            cout << "Enter the key: ";
            int key;
            cin >> key;
            answer = 0;
            tree.fun(tree.get_root(), key, answer);
            // answer = tree.findvalue(tree.get_root(), key, 1000);
            cout << "Fun: " << answer << endl;
        }
        else
        {
            cout << "Select a valid check\n";
        }
    }
}