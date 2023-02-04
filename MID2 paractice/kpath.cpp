#include <iostream>
#include "BST.h"
#include "BST.cpp"
using namespace std;

int main()
{
    BST tree;
    tree.insert(8);
    tree.insert(6);
    tree.insert(19);
    tree.insert(2);
    tree.insert(7);
    tree.insert(18);
    tree.insert(22);
    tree.insert(1);
    tree.insert(4);
    tree.insert(15);
    tree.insert(17);
    tree.insert(29);
    tree.insert(0);
    tree.insert(5);
    // tree.print2d(tree.get_root(), 5);
    tree.printkpath(tree.get_root(), 5);
}