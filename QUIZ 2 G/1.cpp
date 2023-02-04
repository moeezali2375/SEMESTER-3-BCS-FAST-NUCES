#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
template <typename T>
class list
{
public:
    class node
    {
        T data;
        node *next;
        node(T data, node *p)
        {
            this->data = data;
            next = p;
        }
        friend class list<T>;
    };
    // Other Functions of Link list
    void printList();
    void InsertatTail(T value);
    list()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~list();
    node *get_head()
    {
        return head;
    }
    void *fun(node *&head, node *prev, int value)
    {
        if (head->data == value && prev == NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            // this->fun(head, prev, value);
        }
        else if (head->data == value)
        {
            node *temp = head;
            head = head->next;
            prev->next = head;
            delete temp;
            if (head == NULL)
                return head;
            else
                ;
        }
        prev = head;
        this->fun(head->next, prev, value);
        return head;
    }

private:
    node *head;
    node *tail;
};

// Destructor
template <typename T>
list<T>::~list()
{
    node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
// print list
template <typename T>
void list<T>::printList()
{

    node *current;
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// insertnode at tail
template <typename T>
void list<T>::InsertatTail(T value)
{
    node *nnode = new node(value, nullptr);
    if (head == nullptr)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        tail->next = nnode;
        tail = nnode;
    }
}
// template<typename T>

int main()
{
    list<int> l1;
    l1.InsertatTail(6);
    l1.InsertatTail(2);
    l1.InsertatTail(6);
    l1.InsertatTail(3);
    l1.InsertatTail(4);
    l1.InsertatTail(5);
    l1.InsertatTail(6);
    l1.printList();
    list<int>::node *ptr = l1.get_head();
    list<int>::node *ptr2 = NULL;
    l1=l1.fun(ptr, ptr2, 6);

    l1.printList();
}