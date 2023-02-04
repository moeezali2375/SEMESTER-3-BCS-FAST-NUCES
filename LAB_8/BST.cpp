//==================================================================================
//
//              #####  ##   ##  ##     ##   ####  ######  ##   #####   ##     ##
//              ##     ##   ##  ####   ##  ##       ##    ##  ##   ##  ####   ##
//              #####  ##   ##  ##  ## ##  ##       ##    ##  ##   ##  ##  ## ##
//              ##     ##   ##  ##    ###  ##       ##    ##  ##   ##  ##    ###
//              ##      #####   ##     ##   ####    ##    ##   #####   ##     ##
//
//==================================================================================

#include <iostream>
#include "BST.h"
using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    Node *temp = this->get_root();
    this->destructor(temp);
}

void BST::delete_node_helper(Node *&curr, Node *&prev, int key, int &flag)
{
    if (curr == nullptr)
        return;
    if (curr->data == key)
        return;
    prev = curr;
    flag = 0;
    if (curr->data > key)
    {
        curr = curr->left;
        flag = 1;
    }
    else
    {
        curr = curr->right;
        flag = 2;
    }
    delete_node_helper(curr, prev, key, flag);
}

void BST::delete_node(Node *curr, Node *prev, int key)
{
    int flag = 0;
    this->delete_node_helper(curr, prev, key, flag);
    if (curr == nullptr)
        cout << "No data found in the BST\n";
    else
    {
        cout << "Data found\n";
        //! CASE0:
        if (prev == nullptr && curr->left == nullptr && curr->right == nullptr)
        {
            delete curr;
        }
        //! CASE1:
        else if (curr->left == nullptr && curr->right == nullptr)
        {
            cout << "Deletion at leaf Node!\n";
            if (flag == 1)
                prev->left = nullptr;
            else if (flag == 2)
                prev->right = nullptr;
            delete curr;
            curr = nullptr;
        }
        //! CASE2:
        else if (curr->right == nullptr && curr->left != nullptr)
        {
            bool two_nodes = 0;
            Node *temp_x = curr;
            if (flag == 1)
                prev->left = curr->left;
            else if (flag == 2)
                prev->right = curr->left;
            else
            {
                two_nodes = 1;
                temp_x = temp_x->left;
            }
            delete curr;
            curr = nullptr;
            if (two_nodes == 1 && prev == NULL)
            {
                curr = temp_x;
                root = curr;
            }
        }
        else if (curr->right != nullptr && curr->left == nullptr)
        {
            bool two_nodes = 0;
            Node *temp_x = curr;
            if (flag == 1)
                prev->left = curr->right;
            else if (flag == 2)
                prev->right = curr->right;
            else
            {
                two_nodes = 1;
                temp_x = temp_x->right;
            }
            delete curr;
            curr = nullptr;
            if (two_nodes == 1 && prev == NULL)
            {
                curr = temp_x;
                root = curr;
            }
        }
        //! CASE3:
        else
        {
            Node *predecessor = get_predecessor(curr->left, prev);
            curr->data = predecessor->data;
            if (prev == NULL)
            {
                Node *del = curr->left;
                curr->left = curr->left->left;
                delete del;
            }
            else
            {
                delete predecessor;
                prev->right = NULL;
            }
        }
    }
}

Node *BST::get_predecessor(Node *temp, Node *&prev)
{
    if (temp->right == nullptr)
        return temp;
    prev = temp;
    return get_predecessor(temp->right, prev);
}

void BST::destructor(Node *temp)
{
    if (temp == nullptr)
        return;
    destructor(temp->left);
    destructor(temp->right);
    cout << "Deleting: " << temp->data << endl;
    delete temp;
}

BST::BST(BST &s)
{
    if (this->root != nullptr)
    {
        this->root = nullptr;
    }
    Node *temp = s.get_root();
    for (int i = 0; i <= height(s.get_root()); i++)
    {
        cout << "Copying level: " << i << endl;
        copy_helper(temp, i);
    }
}

void BST::copy_helper(Node *temp, int level)
{
    if (temp == nullptr)
    {
        return;
    }
    if (level == 0)
    {
        this->insert(temp->data);
    }
    copy_helper(temp->left, level - 1);
    copy_helper(temp->right, level - 1);
}
Node *BST::get_root()
{
    return root;
}

int BST::height(Node *temp)
{
    if (temp == nullptr)
        return -1;
    int left_h = 0;
    int right_h = 0;
    left_h = height(temp->left);
    right_h = height(temp->right);
    if (left_h > right_h)
        return left_h + 1;
    return right_h + 1;
}

void BST::level_order_printing(Node *temp)
{
    for (int i = 0; i <= this->height(temp); i++)
    {
        cout << "Level: " << i << endl;
        this->print_level(temp, i);
        cout << endl;
    }
}

void BST::print_level(Node *temp, int level)
{
    if (temp == nullptr)
        return;
    if (level == 0)
        cout << temp->data << " ";
    print_level(temp->left, level - 1);
    print_level(temp->right, level - 1);
}

bool BST::insert(int data)
{
    Node *new_node = new Node(data);
    Node *temp = root;
    if (root == nullptr)
    {
        root = new_node;
        return true;
    }
    Node *prev = nullptr;
    int flag = 0;
    while (temp != nullptr)
    {
        prev = temp;
        if (temp->data == data)
            return false;
        else if (data < temp->data)
        {
            flag = 1;
            temp = temp->left;
        }
        else
        {
            flag = 2;
            temp = temp->right;
        }
    }
    if (flag == 1)
    {
        prev->left = new_node;
    }
    else if (flag == 2)
    {
        prev->right = new_node;
    }
    return true;
}

void BST::in_order_printing(Node *root)
{
    if (root != nullptr)
    {
        in_order_printing(root->left);
        cout << root->data << " ";
        in_order_printing(root->right);
    }
}

Node *BST::search(int value)
{
    if (root == nullptr)
        return nullptr;
    Node *temp = root;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        prev = temp;
        if (temp->data == value)
            return temp;
        else if (value < temp->data)
        {
            temp = temp->left;
        }
        else if (value > temp->data)
        {
            temp = temp->right;
        }
    }
    return nullptr;
}

int BST::countNodes(Node *temp)
{
    // int count = 0;
    // int count2 = 0;
    // if (temp != nullptr)
    // {
    //     count = countNodes(temp->left);
    //     if (temp != nullptr)
    //         count++;
    //     count2 = countNodes(temp->right);
    // }
    // return count + count2;
    int count = 0;
    if (temp == nullptr)
        return count;
    count++;
    count += countNodes(temp->left);
    count += countNodes(temp->right);
    return count;
}

int BST::leafCount(Node *temp)
{
    // if (temp == nullptr)
    //     return 0;
    // else if (temp->left == nullptr && temp->right == nullptr)
    //     return 1;
    // return leafCount(temp->left) + leafCount(temp->right);
    if (temp == nullptr)
        return 0;
    if (temp->left == nullptr && temp->right == nullptr)
        return 1;
    int left_nodes = leafCount(temp->left);
    int right_nodes = leafCount(temp->right);
    return left_nodes + right_nodes;
}

void BST::print2d(Node *temp, int space)
{
    if (temp == nullptr)
        return;
    space += SPACE;
    print2d(temp->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
        cout << ' ';
    cout << temp->data << endl;
    print2d(temp->left, space);
}