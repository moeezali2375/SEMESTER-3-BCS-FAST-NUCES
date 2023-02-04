
#include "header.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

//========================================
//
//  ###    ###    ###    ##  ##     ##
//  ## #  # ##   ## ##   ##  ####   ##
//  ##  ##  ##  ##   ##  ##  ##  ## ##
//  ##      ##  #######  ##  ##    ###
//  ##      ##  ##   ##  ##  ##     ##
//
//========================================

BST::BST()
{
    root = NULL;
}

BST::BST(BST &s)
{
    copy_helper(root, s.root);
}

void BST::copy_helper(node *&root, node *s_root)
{
    if (s_root != NULL)
    {
        node *new_node = new node(s_root->data);
        root = new_node;
        copy_helper(root->left, s_root->left);
        copy_helper(root->right, s_root->right);
    }
}

BST::~BST()
{
    delete_helper(root);
}

void BST::delete_helper(node *&root)
{
    if (root == NULL)
        return;
    delete_helper(root->left);
    delete_helper(root->right);
    delete root;
    root = nullptr;
}

node *BST::search(int key)
{
    node *temp = root;
    if (temp == NULL)
        return NULL;
    else
    {
        while (temp != NULL)
        {
            if (temp->data == key)
                return temp;
            if (key < temp->data)
            {
                temp = temp->left;
            }
            else
                temp = temp->right;
        }
        return NULL;
    }
}

void BST::insert(int key)
{
    if (root == NULL)
    {
        node *new_node = new node(key);
        root = new_node;
        return;
    }
    node *temp = root;
    node *prev = NULL;
    int flag1 = 0;
    int flag2 = 0;
    while (temp != NULL)
    {
        prev = temp;
        flag1 = 0;
        flag2 = 0;
        if (temp->data == key)
        {
            cout << "Can't enter the data already present in the BST\n";
            return;
        }
        if (key < temp->data)
        {
            flag1 = 1;
            temp = temp->left;
        }
        else
        {
            flag2 = 1;
            temp = temp->right;
        }
    }
    node *new_node = new node(key);
    if (flag1)
    {
        prev->left = new_node;
    }
    else if (flag2)
    {
        prev->right = new_node;
    }
}

void BST::delete_node(int key)
{
    delete_node(root, key);
}

void BST::delete_node(node *&root, int key)
{
    if (root == nullptr)
        return;
    else if (key < root->data)
    {
        delete_node(root->left, key);
    }
    else if (key > root->data)
    {
        delete_node(root->right, key);
    }
    else if (key == root->data)
    {
        // CASE1
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        // RIGHT
        else if (root->left == nullptr && root->right != nullptr)
        {
            node *right = root->right;
            delete root;
            root = right;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            node *left = root->left;
            delete root;
            root = left;
        }
        else if (root->left != nullptr && root->right != nullptr)
        {
            int predecessor = get_predecessor(root->left);
            root->data = predecessor;
            delete_node(root->left, predecessor);
        }
    }
}

void BST::print_pre_order()
{
    print_pre_order(root);
}

void BST::print_pre_order(node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    print_pre_order(temp->left);
    print_pre_order(temp->right);
}

void BST::print_pre_order_iterative()
{
    if (root == NULL)
        return;
    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        node *curr = st.top();
        cout << curr->data << " ";
        st.pop();
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

void BST::print_in_order()
{
    print_in_order(root);
}

void BST::print_in_order(node *temp)
{
    if (temp != NULL)
    {
        print_in_order(temp->left);
        cout << temp->data << " ";
        print_in_order(temp->right);
    }
}

void BST::print_in_order_iterative()
{
    if (root == NULL)
    {
        cout << "BST is empty!\n";
        return;
    }
    stack<node *> s;
    node *temp = root;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
    }

    node *top = s.top();
    while (!s.empty())
    {
        top = s.top();
        s.pop();
        cout << top->data << " ";
        if (top->right != NULL)
            s.push(top->right);
    }
}

void BST::print_post_order()
{
    print_post_order(root);
}

void BST::print_post_order(node *temp)
{
    if (temp == NULL)
        return;
    print_post_order(temp->left);
    print_post_order(temp->right);
    cout << temp->data << " ";
}

void BST::print_post_order_iterative()
{
    node *temp = root;
    if (temp == nullptr)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    stack<node *> stack1;
    stack<node *> stack2;
    stack1.push(temp);
    while (!stack1.empty())
    {
        node *top = stack1.top();
        stack1.pop();
        stack2.push(top);
        if (top->left != nullptr)
            stack1.push(top->left);
        if (top->right != nullptr)
            stack1.push(top->right);
    }
    while (!stack2.empty())
    {
        node *top = stack2.top();
        stack2.pop();
        cout << top->data << " ";
    }
}

//! REAL
void BST::update_key(int key1, int key2)
{
    this->delete_node(key1);
    this->insert(key2);
}

BST &BST::operator=(BST &s)
{
    cout << "Assignment operator called!" << endl;
    if (this->root != nullptr)
        delete this;
    copy_helper(this->root, s.root);
    return *this;
}

bool BST::operator==(BST &s)
{
    return this->equality_check(root, s.root);
}

bool BST::equality_check(node *root, node *s_root)
{
    if (root == NULL && s_root == NULL)
        return true;
    if (root != NULL && s_root == NULL)
        return false;
    if (root == NULL && s_root != NULL)
        return false;
    if (root->data != s_root->data)
        return false;
    bool flag1, flag2;
    flag1 = equality_check(root->left, s_root->left);
    flag2 = equality_check(root->right, s_root->right);
    if (flag1 && flag2)
        return true;
    return false;
}

int BST::count_nodes()
{
    if (root == NULL)
        return 0;
    int count = 0;
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *top = s1.top();
        s1.pop();
        count++;
        if (top->left != NULL)
            s1.push(top->left);
        if (top->right != NULL)
            s1.push(top->right);
    }
    return count;
}

void BST::mirror_bst()
{
    mirror_bst(root);
}

void BST::mirror_bst(node *&temp)
{
    if (temp == NULL)
        return;
    mirror_bst(temp->left);
    mirror_bst(temp->right);
    swap(temp->left, temp->right);
}

int BST::max_width()
{
    int height = tree_height(root) + 1;
    int *array = new int[height];
    int max = 0;
    for (int i = 0; i < height; i++)
    {
        array[i] = 0;
        width_calculator(root, i, array[i]);
        if (array[i] > max)
            max = array[i];
    }
    delete[] array;
    return max;
}

void BST::width_calculator(node *temp, int level, int &width)
{
    if (temp == NULL)
        return;
    if (level == 0)
        width++;
    width_calculator(temp->left, level - 1, width);
    width_calculator(temp->right, level - 1, width);
}

void BST::path_sum()
{
    vector<int> sum;
    int current_sum = 0;
    path_sum(sum, root, current_sum);
    current_sum = sum.size();
    for (int i = 0; i < current_sum; i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
}

void BST::path_sum(vector<int> &sum, node *root, int current_sum)
{
    if (!root)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        sum.push_back(current_sum + root->data);
        return;
    }
    current_sum += root->data;
    path_sum(sum, root->left, current_sum);
    path_sum(sum, root->right, current_sum);
}

bool BST::isBST()
{
    int total = count_nodes();
    int *array = new int[total];
    int I = 0;
    isBST_helper(root, array, I);
    for (int i = 0; i < total - 1; i++)
    {
        if (array[i] >= array[i + 1])
        {
            delete[] array;
            array = NULL;
            return false;
        }
    }
    delete[] array;
    array = NULL;
    return true;
}

void BST::isBST_helper(node *temp, int *array, int &i)
{
    if (temp == NULL)
        return;
    isBST_helper(temp->left, array, i);
    array[i++] = temp->data;
    isBST_helper(temp->right, array, i);
}

void BST::make_skew()
{
    node *temp;
    int flag = 0;
    make_skew(root, flag, temp);
}

void BST::make_skew(node *root, int &flag, node *&temp)
{
    if (!root)
        return;
    make_skew(root->left, flag, temp);
    if (!flag)
    {
        flag = 1;
        this->root = root;
        root->left = nullptr;
        temp = root;
    }
    else
    {
        temp->right = root;
        root->left = nullptr;
        temp = root;
    }
    make_skew(root->right, flag, temp);
}

int BST::common_ancestor(int key1, int key2)
{
    int common = root->data;
    queue<node *> q1;
    queue<node *> q2;
    search_with_queue(root, q1, key1);
    search_with_queue(root, q2, key2);
    while (!q1.empty() && !q2.empty())
    {
        node *temp1 = q1.front();
        node *temp2 = q2.front();
        q1.pop();
        q2.pop();
        if (temp1->data == temp2->data)
            common = temp1->data;
    }
    return common;
}

void BST::search_with_queue(node *temp, queue<node *> &q1, int key)
{
    if (temp == NULL)
    {
        return;
    }
    if (temp->data == key)
    {
        return;
    }
    if (key < temp->data)
    {
        q1.push(temp);
        search_with_queue(temp->left, q1, key);
    }
    else if (key > temp->data)
    {
        q1.push(temp);
        search_with_queue(temp->right, q1, key);
    }
}

//! HELPERS
void BST::print2d()
{
    print2d(root, 5);
}

void BST::print2d(node *temp, int space)
{
    if (temp == NULL)
        return;
    space += 5;
    print2d(temp->right, space);
    cout << endl;
    for (int i = 5; i < space; i++)
        cout << ' ';
    cout << temp->data << endl;
    print2d(temp->left, space);
}

node *BST::get_root()
{
    return root;
}

int BST::tree_height(node *temp)
{
    if (temp == NULL)
        return -1;
    int l_h = 0;
    int r_h = 0;
    l_h = tree_height(temp->left);
    r_h = tree_height(temp->right);
    if (l_h > r_h)
        return l_h + 1;
    return r_h + 1;
}

int BST::get_predecessor(node *temp)
{
    while (temp->right != NULL)
        temp = temp->right;
    return temp->data;
}

node::node(int data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}
