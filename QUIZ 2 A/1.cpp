#include <iostream>
using namespace std;
class single_list
{
    class node
    {
    public:
        int data;
        node *next;
        friend class single_list;
        node(int data)
        {
            next = NULL;
            this->data = data;
        }
    };
    node *head;

public:
    single_list()
    {
        head = NULL;
    }
    single_list(single_list &s)
    {
        head = NULL;
        node *temp = s.head;
        while (temp != NULL)
        {
            this->insert(temp->data);
            temp = temp->next;
        }
    }
    void insert(int data)
    {
        node *new_node = new node(data);
        if (head == NULL)
        {
            head = new_node;
            head->next = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void print_list()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse()
    {
        node *curr = head;
        node *prev = nullptr;
        node *temp = head;
        if (head != nullptr && head->next != nullptr)
        {
            while (temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
                prev->next = curr;
                curr = prev;
            }
            head->next = nullptr;
            head = curr;
        }
    }
    int get_length()
    {
        int counter = 0;
        node *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool checkpalindrome(single_list l1, single_list l2)
    {
        int length = l1.get_length();
        node *temp1 = l1.head;
        node *temp2 = l2.head;
        for (int i = 0; i < length / 2; i++)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

int main()
{
    single_list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(1);
    single_list l2 = l1;
    l2.reverse();
    cout << l1.checkpalindrome(l1, l2);
}