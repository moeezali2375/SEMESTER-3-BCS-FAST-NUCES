#include <iostream>
using namespace std;
class node
{
public:
    char data;
    node *next;
    node()
    {
        next = NULL;
    }
};
class linkedList
{
private:
    node *head;

public:
    linkedList()
    {
        head = NULL;
    }
    void InsertAtHead(char const val)
    {
        node *n = new node;
        n->data = val;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }
    void InsertAtTail(char const val)
    {
        node *n = new node;
        n->data = val;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n;
            n->next = NULL;
        }
    }
    void print() const
    {
        node *n = head;
        while (n != NULL)
        {
            cout << n->data << "   ";
            n = n->next;
        }
    }
    void DeleteFromHead()
    {
        node *n = head;
        head = head->next;
        delete n;
    }
    void DeleteFromTail()
    {
        node *n = head;
        while (n->next->next != NULL)
        {
            n = n->next;
        }
        delete n->next;
    }
    int totalCount() const
    {
        node *st = head;
        int count = 0;
        while (st != NULL)
        {
            st = st->next;
            count++;
        }
        return count;
    }
    void split(linkedList &firstHalf, linkedList &secondHalf)
    {
        int total = totalCount() - 1;
        node *n = head;
        for (int i = 1; i <= total / 2; i++)
            n = n->next;
        secondHalf.head = n->next;
        n->next = NULL;
        firstHalf.head = n;
    }
    void merge(linkedList &firstHalf, linkedList &secondHalf)
    {
        node *n = firstHalf.head;
        while (n->next != NULL)
            n = n->next;
        n->next = secondHalf.head;
    }
};
int main()
{
    linkedList obj;
    char val;
    cout << "Enter a Value for head  : " << endl;
    cin >> val;
    obj.InsertAtHead(val);

    cout << "Enter a Value for tail : " << endl;
    cin >> val;
    obj.InsertAtTail(val);

    cout << "Data in link list" << endl;
    obj.print();
    cout << endl;

    cout << "Size of link list is :  " << obj.totalCount() << endl;

    linkedList first, second;
    obj.split(first, second);

    cout << "Data in  first half of link list" << endl;
    first.print();
    cout << endl;

    cout << "Data in second half of link list" << endl;
    second.print();
    cout << endl;

    first.merge(first, second);

    cout << "Data in link list" << endl;
    first.print();
    cout << endl;

}
