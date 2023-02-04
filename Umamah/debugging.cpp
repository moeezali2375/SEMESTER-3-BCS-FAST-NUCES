#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class list
{
    Node *head;
    Node *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int e)
    {
        Node *n = new Node;
        n->data = e;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            head->next = NULL;
            tail = n;
        }
        else if (head != NULL)
        {
            Node *curr = head;
            Node *prev = head;
            if (e < head->data)
            {
                n->next = head;
                head = n;
            }
            else
            {
                int flag = 0;
                while (curr != NULL)
                {
                    if (e < curr->data)
                    {
                        n->next = curr;
                        prev->next = n;
                        break;
                        flag = 1;
                    }
                    prev = curr;
                    curr = curr->next;
                }
                if (curr == NULL)
                {
                    tail->next = n;
                    n->next = NULL;
                    tail = n;
                }
            }
        }
    }

    void print()
    {
        cout << "\n**Display**\n";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    list obj;
    obj.insert(6);
    obj.insert(4);
    obj.insert(5);
    obj.insert(8);
    obj.print();
}