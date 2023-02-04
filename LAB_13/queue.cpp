#include <iostream>
#define SPACE 10
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
        data = 0;
    }
};

class BST
{
public:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    void createtree(int arr[], int first, int last)
    {

        // 2,3,4,9,21,25,26,27
        if (first >= last)
        {
            return;
        }
        else
        {
            int mid = (last + first) / 2;

            Node *n = new Node;
            n->data = arr[mid];

            if (root == NULL)
            {
                root = n;
            }
            else
            {
                Node *temp = root;
                while (temp != NULL)
                {

                    if (temp->left != NULL)
                    {
                        if (n->data < temp->data)
                        {
                            temp = temp->left;
                        }
                    }

                    if (temp->right != NULL)
                    {
                        if (n->data > temp->data)
                        {
                            temp = temp->right;
                        }
                    }

                    if (temp->data > n->data && temp->left == NULL)
                    {
                        temp->left = n;
                        break;
                    }

                    if (temp->data < n->data && temp->right == NULL)
                    {
                        temp->right = n;
                        break;
                    }
                }
            }
            createtree(arr, first, mid);
            createtree(arr, mid + 1, last);
        }
    }

    void print2D(Node *r, int space)
    {
        if (r == NULL)
            return;

        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->data << "\n";
        print2D(r->left, space);
    }
};

int main()
{
    BST obj;
    int arr[8] = {2, 3, 4, 9, 21, 25, 26, 27};
    obj.createtree(arr, 0, 7);
    obj.print2D(obj.root, 5);
}