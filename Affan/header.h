#pragma once
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};
class BST
{
    node *root;

public:
    BST(); // con
    BST(BST &dummy);
    node *deep_copy(node *dummy);

    ~BST(); // dest
    void DEST(node *cur);

    node *getroot();

    node *search(int v);
    node *recsearch(node *r, int v);

    void insert(int v);

    node *deleteNode(node *r, int v);
    node *minValueNode(node *n);

    void preorderprint(node *r);
    void inorderprint(node *r);
    void postorderprint(node *r);

    int height(node *r);
    void printCurrentLevel(node *root, int level);
    void printLevelOrder(node *root);

    void updatekey(node *root, node *key1, node *key2);

    BST *operator=(BST n);

    bool operator==(BST b);
    bool isEqual(node *n1, node *n2);

    int countnodes(node *r);
    void LVRForCount(node *curr, int &c);

    bool isEmpty();
    void treeprint(node *root, int level);

    void mirror(node *roo);

    void skew(node *root);

    node *comonanmcestor(node *r, int n1, int n2);

    int currentlvlhelper(node *root, int level, int c);
    int width(node *root);

    bool isBST(node *root, node *min, node *max);
    node *Min(node *root);
    node *Max(node *root);
};
BST::BST()
{
    root = NULL;
}

BST::BST(BST &dummy)
{

    root = deep_copy(dummy.root);
}

node *BST::deep_copy(node *dummy)
{
    if (dummy)
    {
        node *temp = new node(dummy->data);
        temp->left = deep_copy(dummy->left);
        temp->right = deep_copy(dummy->right);
        return temp;
    }
    else
    {
        return NULL;
    }
}

BST::~BST()
{
    DEST(root);
}

void BST::DEST(node *cur)
{
    if (cur != nullptr)
    {

        if ((cur->left == NULL) && (cur->right == NULL))
        {
            delete cur;
            cur = NULL;
        }
        else
        {
            DEST(cur->left);
            DEST(cur->right);
            /*delete cur;
            cur = NULL;*/
        }
    }
}

node *BST::getroot()
{
    return root;
}

bool BST::isEmpty()
{
    if (root == NULL)
        return true;
    return false;
}

void BST::treeprint(node *root, int space)
{

    // Base case
    if (root == NULL)
    {
        /*for (int i = 10; i < space; i++)
            cout << " ";
        cout << "null" << endl;*/
        return;
    }
    space += 5;
    treeprint(root->right, space);
    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->data << " -{ "
         << "\n";
    treeprint(root->left, space);
}

void BST::insert(int v)
{
    node *n = new node(v);
    if (root == NULL)
    {
        root = n;
        return;
    }
    node *curr = root;
    node *prev;
    while (curr != NULL)
    {
        prev = curr;
        if (v == curr->data)
            return;
        else if (v < curr->data && curr->left == NULL)
        {
            curr->left = n;
            break;
        }
        else if (v < curr->data)
        {
            curr = curr->left;
        }
        else if (v > curr->data && curr->right == NULL)
        {
            curr->right = n;
            break;
        }
        else if (v > curr->data)
        {
            curr = curr->right;
        }
    }
}

void BST::preorderprint(node *r)
{
    if (r == NULL)
        return;
    cout << r->data << "   ";
    preorderprint(r->left);
    preorderprint(r->right);
}

void BST::inorderprint(node *r)
{
    if (r == NULL)
        return;
    inorderprint(r->left);
    cout << r->data << "   ";
    inorderprint(r->right);
}

void BST::postorderprint(node *r)
{
    if (r == NULL)
        return;
    postorderprint(r->left);
    postorderprint(r->right);
    cout << r->data << "   ";
}

node *BST::search(int v)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        node *curr = root;
        while (curr != NULL)
        {
            if (curr->data == v)
            {
                return curr;
            }
            else if (curr->data > v)
            {
                curr = curr->right;
            }
            else if (curr->data < v)
            {
                curr = curr->left;
            }
        }
    }
    // return NULL;
}

node *BST::recsearch(node *r, int v)
{
    if (r == NULL || r->data == v)
        return r;
    else if (v < r->data)
    {
        return recsearch(r->left, v);
    }
    else
        return recsearch(r->right, v);
}

node *BST::minValueNode(node *n)
{
    node *current = n;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *BST::deleteNode(node *r, int v)
{

    if (r == NULL)
    {
        return NULL;
    }

    else if (v < r->data)
    {
        r->left = deleteNode(r->left, v);
    }

    else if (v > r->data)
    {
        r->right = deleteNode(r->right, v);
    }

    else
    {
        if (r->left == NULL)
        {
            node *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL)
        {
            node *temp = r->left;
            delete r;
            return temp;
        }
        else
        {
            node *temp = minValueNode(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
    }
    return r;
}

int BST::height(node *r)
{
    if (r == NULL)
        return -1;
    else
    {
        int left = height(r->left);
        int right = height(r->right);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

void BST::printLevelOrder(node *root)
{
    int h = height(root);

    for (int i = 0; i <= h; i++)
        printCurrentLevel(root, i);
}

void BST::printCurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
        cout << root->data << " ";
    else
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void BST::updatekey(node *root, node *key1, node *key2)
{
    if (!search(key1->data))
    {
        cout << "data not found...";
        return;
    }
    deleteNode(root, key1->data);
    insert(key2->data);
}

BST *BST::operator=(BST n)
{
    if (this->root != NULL)
        delete this;
    this->root = deep_copy(n.root);
    return this;
}

bool BST::operator==(BST b)
{
    if (isEqual(this->root, b.root))
        return true;
    else
        return false;
}

bool BST::isEqual(node *n1, node *n2)
{
    if (n1 == NULL || n2 == NULL)
        return (n1 == n2);
    return (n1->data == n1->data) && isEqual(n1->left, n2->left) && isEqual(n1->right, n2->right);
}

int BST::countnodes(node *root)
{
    int c = 0;
    LVRForCount(root, c);
    return c;
}
void BST::LVRForCount(node *curr, int &c)
{
    if (curr == NULL)
        return;
    else
    {
        c++;
        LVRForCount(curr->left, c);
        LVRForCount(curr->right, c);
    }
}

void BST::mirror(node *roo)
{
    if (roo == NULL)
    {
        return;
    }
    else
    {
        node *temp;
        mirror(roo->left);
        mirror(roo->right);
        temp = roo->left;
        roo->left = roo->right;
        roo->right = temp;
    }
}

void BST::skew(node *r)
{
    if (r == NULL)
    {
        return;
    }
    skew(r->left);
    node *rn = r->left;
    node *ln = r->right;
    node *head = root;
    node *prev = NULL;
    if (head != NULL)
    {
        head = r;
        head->left = NULL;
        prev = head;
    }
    else
    {
        prev->right = head;
        head->left = NULL;
        prev = head;
    }
    skew(ln);
}

node *BST::comonanmcestor(node *r, int n1, int n2)
{
    if (r == NULL)
        return r;
    if (r->data == n1 || r->data == n2)
    {
        return r;
    }
    node *l = comonanmcestor(r->left, n1, n2);
    node *ri = comonanmcestor(r->right, n1, n2);
    if (!l && !ri)
    {
        return r;
    }
    else if (l != NULL && ri == NULL)
    {
        return l;
    }
    else if (ri != NULL && l == NULL)
    {
        return ri;
    }
    else
        return NULL;
}

int BST::currentlvlhelper(node *root, int level, int c)
{
    if (root == NULL)
        return 0;
    if (level == c)
        return 1;
    return currentlvlhelper(root->left, level, c + 1) +
           currentlvlhelper(root->right, level, c + 1);
}

int BST::width(node *root)
{
    int h = height(root);
    int *arr = new int[h + 1];
    for (int i = 0; i < h + 1; i++)
    {
        arr[i] = currentlvlhelper(root, i, 0);
    }
    int max = arr[0];
    for (int i = 0; i < h + 1; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

bool BST::isBST(node *root, node *min, node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min->data && root->data <= max->data)
    {
        bool left = isBST(root->left, Min(this->root), Max(this->root));
        bool right = isBST(root->right, Min(this->root), Max(this->root));
        return left && right;
    }
    else
    {
        return false;
    }
}
node *BST::Min(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *BST::Max(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}