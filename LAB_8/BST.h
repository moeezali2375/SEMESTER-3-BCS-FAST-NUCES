#pragma once
#include <iostream>
using namespace std;

static int flag = 0;
//=======================================
//
//              #####    ####  ######
//              ##  ##  ##       ##
//              #####    ###     ##
//              ##  ##     ##    ##
//              #####   ####     ##
//
//=======================================

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    ~Node()
    {
        left = nullptr;
        right = nullptr;
    }
};

int SPACE = 5;
class BST
{
    Node *root;

public:
    BST();
    ~BST();
    void destructor(Node *temp); // LRV
    BST(BST &s);                 // Traversal
    Node *get_root();
    Node *get_predecessor(Node *temp, Node *&prev);
    void delete_node_helper(Node *&curr, Node *&prev, int key, int &flag);
    void delete_node(Node *curr, Node *prev, int key);
    bool insert(int data);
    void in_order_printing(Node *root);    // LVR
    void level_order_printing(Node *root); // traversal + recursion
    void print_level(Node *root, int level);
    int height(Node *temp);                  // LRV
    void print2d(Node *temp, int space);     // RVL
    Node *search(int value);                 // Traversal
    int countNodes(Node *temp);              // LVR
    void copy_helper(Node *temp, int level); // level order
    int leafCount(Node *temp);               // LRV
    void fun(Node *root, int key, int &value)
    {
        if (root == NULL)
            return;
        if (root->data >= key)
        {
            value = root->data;
            if (root->data == key)
                return;
            flag = 1;
        }
        if (key < root->data)
            fun(root->left, key, value);
        else
            fun(root->right, key, value);
        if (flag == 0)
        {
            value = -1;
            return;
        }
    }
    int findvalue(Node *r, int key, int s)
    {
        if (r == NULL)
            return s;
        else
        {
            if (r->data == key)
                return key;
            else if (r->data > key)
            {
                if (r->data < s)
                    s = r->data;
                return findvalue(r->left, key, s);
            }
            else if (r->data < key)
                return findvalue(r->right, key, s);
        }
        return 0;
    }
};
