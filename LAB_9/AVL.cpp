#include "AVL.h"
#include <iostream>
using namespace std;

//=========================================================================================
//
//              #####  ##   ##  ##     ##   ####  ######  ##   #####   ##     ##   ####
//              ##     ##   ##  ####   ##  ##       ##    ##  ##   ##  ####   ##  ##
//              #####  ##   ##  ##  ## ##  ##       ##    ##  ##   ##  ##  ## ##   ###
//              ##     ##   ##  ##    ###  ##       ##    ##  ##   ##  ##    ###     ##
//              ##      #####   ##     ##   ####    ##    ##   #####   ##     ##  ####
//
//=========================================================================================

node::node(int data)
{
    this->data = data;
    left = nullptr;
    right = nullptr;
    lh = 0;
    rh = 0;
}

node ::~node()
{
    left = nullptr;
    right = nullptr;
}

AVL::AVL()
{
    root = nullptr;
}

AVL::~AVL()
{
    node *temp = root;
    destroy(temp);
}

void AVL::destroy(node *&temp)
{
    if (temp == nullptr)
        return;
    destroy(temp->left);
    destroy(temp->right);
    delete temp;
    temp = nullptr;
}

int AVL::get_height(node *temp)
{
    if (temp == nullptr)
        return -1;
    int l = get_height(temp->left);
    int r = get_height(temp->right);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}

int AVL::get_predecessor(node *temp)
{
    while (temp->right != nullptr)
        temp = temp->right;
    return temp->data;
}

int AVL::get_balance(node *temp)
{
    if (temp == nullptr)
        return 0;
    return temp->lh - temp->rh;
}

void AVL::print2d()
{
    cout << "Print2D: " << endl;
    print2d(root, 5);
}

void AVL::print2d(node *temp, int space)
{
    if (temp == nullptr)
        return;
    space += 5;
    print2d(temp->right, space);
    cout << endl;
    for (int i = 5; i < space; i++)
        cout << ' ';
    cout << temp->data << endl;
    print2d(temp->left, space);
}

void AVL::left_rotate(node *&temp)
{
    node *right = temp->right;
    node *sub_tree = temp->right->left;

    temp->right = sub_tree;
    right->left = temp;

    temp = right;

    temp->left->lh = get_height(temp->left->left) + 1;
    temp->left->rh = get_height(temp->left->right) + 1;
    temp->lh = get_height(temp->left) + 1;
    temp->rh = get_height(temp->right) + 1;
}

void AVL::right_rotate(node *&temp)
{
    node *left = temp->left;
    node *sub_tree = temp->left->right;

    temp->left = sub_tree;
    left->right = temp;

    temp = left;

    temp->right->lh = get_height(temp->right->right) + 1;
    temp->right->rh = get_height(temp->right->left) + 1;
    temp->lh = get_height(temp->left) + 1;
    temp->rh = get_height(temp->right) + 1;
}

void AVL::insert_node(int data)
{
    insert_node(root, data);
}

void AVL::insert_node(node *&temp, int data)
{
    if (temp == nullptr)
    {
        node *new_node = new node(data);
        temp = new_node;
        return;
    }
    else
    {
        if (data < temp->data)
            insert_node(temp->left, data);
        else
            insert_node(temp->right, data);
    }
    temp->lh = get_height(temp->left) + 1;
    temp->rh = get_height(temp->right) + 1;
    int bf = temp->lh - temp->rh;
    // Rotations
    if (bf > 1 && data < temp->left->data)
    {
        cout << "RIGHT ROTATE!\n";
        right_rotate(temp);
    }
    else if (bf < -1 && data > temp->right->data)
    {
        cout << "LEFT ROTATE!\n";
        left_rotate(temp);
    }
    else if (bf > 1 && data > temp->left->data)
    {
        cout << "LEFT, RIGHT ROTATE!\n";
        left_rotate(temp->left);
        right_rotate(temp);
    }
    else if (bf < -1 && data < temp->right->data)
    {
        cout << "RIGHT, LEFT ROTATE!\n";
        right_rotate(temp->right);
        left_rotate(temp);
    }
}

void AVL::delete_node(int data)
{
    delete_node(root, data);
}

void AVL::delete_node(node *&temp, int data)
{
    if (temp == nullptr)
    {
        cout << "No data found" << endl;
        return;
    }
    if (data < temp->data)
        delete_node(temp->left, data);
    else if (data > temp->data)
        delete_node(temp->right, data);
    else if (temp->data == data)
    {
        // CASE1 (no child)
        if (temp->left == nullptr && temp->right == nullptr)
        {
            delete temp;
            temp = nullptr;
            return;
        }
        // CASE2 (one child)
        else if (temp->left == nullptr && temp->right != nullptr)
        {
            node *del = temp;
            temp = temp->right;
            delete del;
            del = nullptr;
        }
        else if (temp->left != nullptr && temp->right == nullptr)
        {
            node *del = temp;
            temp = temp->left;
            delete del;
            del = nullptr;
        }
        // CASE3 (two child)
        else if (temp->left != nullptr && temp->right != nullptr)
        {
            temp->data = get_predecessor(temp->left);
            delete_node(temp->left, temp->data);
        }
    }

    temp->lh = get_height(temp->left);
    temp->rh = get_height(temp->right);
    int bf = temp->lh - temp->rh;

    // ROTATIONS
    if (bf > 1 && get_balance(temp->left) >= 0)
    {
        cout << "RIGHT ROTATE!\n";
        right_rotate(temp);
    }
    else if (bf > 1 && get_balance(temp->left) < 0)
    {
        cout << "LEFT, RIGHT ROTATE!\n";
        left_rotate(temp->left);
        right_rotate(temp);
    }
    else if (bf < -1 && get_balance(temp->right) <= 0)
    {
        cout << "LEFT ROTATE!\n";
        left_rotate(temp);
    }
    else if (bf < -1 && get_balance(temp->right) > 0)
    {
        cout << "RIGHT, LEFT ROTATE!\n";
        right_rotate(temp->right);
        left_rotate(temp);
    }
}
