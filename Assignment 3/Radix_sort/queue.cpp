#include <iostream>
using namespace std;
template <typename T>
class list
{
public:
    class node
    {
    public:
        T data;
        node *next;
        friend class list<T>;
        node(T value)
        {
            data = value;
            next = NULL;
        }
    };
    node *head;
    node *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
    ~list()
    {
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }
    void insert(T value)
    {
        node *new_node = new node(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            head->next = NULL;
        }
        else
        {
            tail->next = new_node;
            new_node->next = NULL;
            tail = new_node;
        }
    }
    void delete_head(T &return_value)
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        return_value = temp->data;
        delete temp;
    }
};

template <typename T>
class queue
{
    list<T> a;
    typename list<T>::node *rear;
    typename list<T>::node *front;
    friend class list<T>;

public:
    queue()
    {
        this->rear = a.tail;
        this->front = a.head;
    }
    void enqueue(T value)
    {
        a.insert(value);
        this->rear = a.tail;
        this->front = a.head;
    }
    void dequeue(T &value)
    {
        a.delete_head(value);
        this->rear = a.tail;
        this->front = a.head;
    }
    bool isEmpty()
    {
        if (rear == NULL && front == NULL)
        {
            return 1;
        }
        return 0;
    }
    void print()
    {
        typename list<T>::node *temp = front;
        while (front != NULL)
        {
            cout << front->data << "->";
            front = front->next;
        }
    }
};

// int main()
// {
//     char word[] = "hello";
//     queue<string> queues;
//     queues.enqueue(word);
//     queues.print();
// }