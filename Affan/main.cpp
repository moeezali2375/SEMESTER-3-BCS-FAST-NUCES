#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(8);
    tree.insert(13);
    tree.insert(7);
    tree.insert(9);
    tree.insert(12);
    tree.insert(15);

    tree.treeprint(tree.getroot(), 0);
    BST tree2(tree);

    cout << "\nCHECKING COPY CoNSTRUCTOR\n";
    tree.treeprint(tree2.getroot(), 0);

    cout << "\ninorder print\n";
    tree.inorderprint(tree.getroot());

    cout << "\nlevel order print:\n";
    tree.printLevelOrder(tree.getroot());

    cout << "\nchecking search:\n";
    node *search = NULL;
    search = tree.recsearch(tree.getroot(), 15);
    cout << search << endl;

    cout << "\nchecking count nodes:\n";
    int count = tree.countnodes(tree.getroot());
    cout << "total number of counts:" << count << "\n";

    cout << "\nchecking delete \n";
    tree.deleteNode(tree.getroot(), 8);
    tree.treeprint(tree.getroot(), 0);
}