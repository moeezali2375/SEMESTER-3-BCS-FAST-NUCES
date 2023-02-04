#pragma once
#include <iostream>
struct node
{
    int data;
    node *left;
    node *right;
    int lh;
    int rh;
    node(int data);
    ~node();
};

class AVL
{
    node *root;

public:
    //! FUNCTIONS:
    AVL();
    ~AVL();
    void destroy(node *&temp);
    int get_height(node *temp);
    int get_predecessor(node *temp);
    int get_balance(node *temp);
    void print2d();
    void print2d(node *temp, int space);
    void left_rotate(node *&temp);
    void right_rotate(node *&temp);
    void insert_node(int data);
    void insert_node(node *&temp, int data);
    void delete_node(int data);
    void delete_node(node *&temp, int data);
};
