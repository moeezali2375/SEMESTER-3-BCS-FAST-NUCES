#include <iostream>
#include "header.h"
#include "definitions.cpp"
using namespace std;
int main()
{
    BST t1;

    int choice = -1;
    node *search = NULL;
    node *temp;
    int key1;
    int key2;
    int data;
    t1.insert(50);
    t1.insert(30);
    t1.insert(20);
    t1.insert(40);
    t1.insert(60);
    t1.insert(55);
    t1.insert(90);
    //! Assignment operator check
    // t1.print2d();
    BST t2;
    t2 = t1;
    // t2.print2d();
    t1.insert(100);
    while (choice != 0)
    {
        cout << "0.  Destructor\n";
        cout << "1.  Search\n";
        cout << "2.  Insert\n";
        cout << "3.  Delete Node\n";
        cout << "4.  Print in Order\n";
        cout << "5.  Print Post Order\n";
        cout << "6.  Print Pre Order\n";
        cout << "7.  Print 2D\n";
        cout << "8.  Update Key\n";
        cout << "9.  Equality check\n";
        cout << "10. Count Nodes\n";
        cout << "11. Mirror BST\n";
        cout << "12. Find width\n";
        cout << "13. Path Sum\n";
        cout << "14. Make skew\n";
        cout << "15. BST check\n";
        cout << "16. Common Ancestor\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Program closing\n";
            break;
        case 1:
            cout << "Enter the node you want to search for: ";
            cin >> key1;
            search = t1.search(key1);
            if (search != NULL)
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case 2:
            cout << "Enter the data you want to insert: ";
            cin >> data;
            t1.insert(data);
            cout << "Data entered successfully\n";
            break;
        case 3:
            cout << "Enter the node you want to delete: ";
            cin >> data;
            temp = t1.get_root();
            t1.delete_node(temp, data);
            break;
        case 4:
            cout << "Printing in order\n";
            t1.print_in_order();
            // t1.print_in_order_iterative();
            cout << endl;
            break;
        case 5:
            cout << "Printing Post Order\n";
            // t1.print_post_order();
            t1.print_post_order_iterative();
            cout << endl;
            break;
        case 6:
            cout << "Printing Pre Order\n";
            // t1.print_pre_order()
            t1.print_pre_order_iterative();
            cout << endl;
            break;
        case 7:
            cout << "Printing Graphically\n";
            t1.print2d();
            break;
        case 8:
            cout << "Enter the key1!" << endl;
            cin >> key1;
            cout << "Enter the key2!" << endl;
            cin >> key2;
            t1.update_key(key1, key2);
            break;
        case 9:
            if (t2 == t1)
                cout << "Both trees are equal!\n";
            else
                cout << "Trees are not equal!\n";
            break;
        case 10:
            cout << "Total number of nodes in the tree are: ";
            cout << t1.count_nodes();
            cout << endl;
            break;
        case 11:
            cout << "Mirror BST!\n";
            t1.mirror_bst();
            t1.print2d();
            choice = 0;
            break;
        case 12:
            cout << "The width of the tree is: ";
            cout << t1.max_width();
            cout << endl;
            break;
        case 13:
            cout << "Path Sum!\n";
            t1.path_sum();
            break;
        case 14:
            cout << "Make Skew!\n";
            t1.make_skew();
            t1.print2d();
            choice = 0;
            break;
        case 15:
            if (t1.isBST())
                cout << "Tree is BST !\n";
            else
                cout << "Tree is not a BST! \n";
            break;
        case 16:
            cout << "Enter the first node: ";
            cin >> key1;
            cout << "Enter the second node: ";
            cin >> key2;
            cout << "Common Ancestor is: " << t1.common_ancestor(key1, key2) << endl;
            break;
        }
    }
}