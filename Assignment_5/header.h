#pragma once
#include <stack>
#include <queue>
using namespace std;
//=======================================
//
//              #####    ####  ######
//              ##  ##  ##       ##
//              #####    ###     ##
//              ##  ##     ##    ##
//              #####   ####     ##
//
//=======================================
struct node
{
    int data;
    node *left;
    node *right;
    node(int data);
};
class BST
{
private:
    node *root;

public:
    //! HELPERS
    node *get_root();
    int tree_height(node *temp);
    int get_predecessor(node *temp);
    //! FUNCTIONS
    BST();
    BST(BST &s);
    void copy_helper(node *&root, node *s_root);
    ~BST();
    void delete_helper(node *&root);
    node *search(int key);
    void insert(int key);
    void delete_node(int key);
    void delete_node(node *&root, int key);
    void print_pre_order();
    void print_pre_order(node *temp);
    void print_pre_order_iterative();
    void print_in_order();
    void print_in_order(node *temp);
    void print_in_order_iterative();
    void print_post_order();
    void print_post_order(node *temp);
    void print_post_order_iterative();
    void print2d();
    void print2d(node *temp, int space);
    //! REAL
    void update_key(int key1, int key2);
    BST &operator=(BST &s);
    bool operator==(BST &s);
    bool equality_check(node *root, node *s_root);
    int count_nodes();
    void mirror_bst();
    void mirror_bst(node *&temp);
    int max_width();
    void width_calculator(node *temp, int level, int &width);
    void path_sum();
    void path_sum(vector<int> &sum, node *root,int current_sum);
    bool isBST();
    void isBST_helper(node *temp, int *array, int &i);
    void make_skew();
    void make_skew(node *root, int &flag, node *&temp);
    int common_ancestor(int key1, int key2);
    void search_with_queue(node *temp, queue<node *> &s1, int key);
};