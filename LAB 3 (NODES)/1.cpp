#include <iostream>
#include <stack>
using namespace std;
class node
{
    int data;
    node *next;
    friend class linked_list;
};
class linked_list
{
    node *head;
    node *tail;

public:
    // void delete_node_hehe(int key)
    // {
    //     stack<node *> s1;
    //     node *curr = head;
    //     while (curr != nullptr)
    //     {
    //         if (curr->data == key)
    //             s1.push(curr);
    //     }

    //     if (delete_ptr == null)
    //         ;
    //     else
    //     {
    //     }
    // }
    linked_list();
    bool is_empty();
    void insert_at_head(int data);
    void insert_at_tail(int data);
    void print_forward();
    void delete_from_head();
    void delete_from_tail();
    int get_middle();
    int size();
    void insert_after(int val, int key);
    void insert_before(int val, int key);
    int get_max();
    int get_min();
    int get_average();
    bool swap(int left, int right);
    ~linked_list()
    {
        node *curr = head;
        node *prev = head;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        cout << "DESTROYED" << endl;
    }
};

linked_list::linked_list()
{
    head = NULL;
    tail = NULL;
}

bool linked_list::is_empty()
{
    if (head == NULL && tail == NULL)
        return true;
    return false;
}

void linked_list::insert_at_head(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty() == 1)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void linked_list::insert_at_tail(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty() == 1)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

void linked_list::print_forward()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void linked_list::delete_from_head()
{
    node *prev = head;
    head = head->next;
    delete prev;
}

void linked_list ::delete_from_tail()
{
    node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    temp->next = NULL;
    tail = temp;
    cout << tail->data << endl;
}

int linked_list::get_middle()
{
    node *temp = head;
    int c = size();
    for (int i = 0; i < c / 2; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

int linked_list::size()
{
    node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void linked_list::insert_after(int val, int key)
{
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            node *new_node = new node();
            new_node->data = key;
            new_node->next = curr->next;
            curr->next = new_node;
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL)
    {
        insert_at_tail(key);
    }
}

void linked_list::insert_before(int val, int key)
{
    node *curr = head;
    if (curr->data == val)
    {
        insert_at_head(key);
    }
    else
    {
        node *prev = head;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
            if (curr->data == val)
            {
                node *new_node = new node;
                new_node->data = key;
                prev->next = new_node;
                new_node->next = curr;
                break;
            }
        }
        if (curr->next == NULL)
        {
            insert_at_tail(key);
        }
    }
}

int linked_list::get_max()
{
    node *curr = head;
    int max = curr->data;
    while (curr != NULL)
    {
        if (curr->data > max)
            max = curr->data;
        curr = curr->next;
    }
    return max;
}

int linked_list::get_min()
{
    node *curr = head;
    int min = curr->data;
    while (curr != NULL)
    {
        if (curr->data < min)
            min = curr->data;
        curr = curr->next;
    }
    return min;
}

int linked_list::get_average()
{
    int sum = 0;
    int counter = size();
    node *curr = head;
    while (curr != NULL)
    {
        sum += curr->data;
        curr = curr->next;
    }
    sum /= counter;
    return counter;
}

bool linked_list::swap(int left, int right)
{
    node *left_node;
    node *right_node;
    node *left_prev;
    node *right_prev;
    node *curr = head;
    int total = size();
    for (int i = 0; i < total; i++)
    {
        if (i == left - 1)
        {
            left_prev = curr;
        }
        if (i == left)
        {
            left_node = curr;
        }
        if (i == right - 1)
        {
            right_prev = curr;
        }
        if (i == right)
        {
            right_node = curr;
        }
        curr = curr->next;
    }
    int temp = left_node->data;
    left_node->data = right_node->data;
    right_node->data = temp;

    return 1;
}

int main()
{
    linked_list a;
    a.insert_at_tail(1);
    a.insert_at_tail(4);
    a.insert_at_tail(0);
    a.insert_at_tail(1);
    a.insert_at_tail(6);
    a.print_forward();
    // a.insert_after(0, 69);
    // a.print_forward();
    // a.insert_at_head(5);
    // a.insert_at_head(10);
    // a.insert_at_head(10);
    // a.insert_at_head(10);
    // a.insert_at_tail(0);
    // a.insert_at_tail(2);
    // a.delete_from_tail();
    // a.print_forward();
    // a.delete_from_head();
    // a.delete_from_tail();
    // a.insert_after(0, 69);
    // a.insert_before(10, 96);
    // a.print_forward();
    // a.swap(1, 3);
    // a.print_forward();
    // cout << a.get_max();
    // cout << a.get_min();
    // cout << a.get_average();
    // cout << a.get_middle();
}