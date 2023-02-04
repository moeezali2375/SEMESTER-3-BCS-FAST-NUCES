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
    class listiterator
    {
    protected:
        node *current;
        friend class list<T>;

    public:
        // Default Constructor
        listiterator() { current = NULL; }
        // Parameterized Constructor used in begin and end functions
        listiterator(node *p) { current = p; }
        // Dereference operation to provide access of data to user
        T &operator*() const { return current->data; }
        // Move forward Pre-increment
        listiterator &operator++()
        {
            if (current != NULL)
                this->current = this->current->next;
            return *this;
        }
        // Move forward Post-increment
        listiterator operator++(int)
        {

            listiterator old = *this;
            ++(*this);
            return old;
        }
        // If two iterators point to same node
        bool operator==(const listiterator &rhs) const { return current == rhs.current; }
        // If two iterators point to different nodes
        bool operator!=(const listiterator &rhs) const { return !(*this == rhs); }
    };
    // Iterator returned that points to First Node
    listiterator begin() { return head; }
    // Iterator returned that points to Last Node
    listiterator end() { return NULL; }

    // Other Functions of Link list
    void printList();
    void InsertatTail(T value);
    list()
    {
        head = NULL;
        tail = NULL;
    }
    ~list();

private:
    node *head;
    node *tail;
};

// Destructor
template <typename T>
list<T>::~list()
{
    node *temp;
    while (head != NULL)
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
    while (current != NULL)
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
    node *nnode = new node(value, NULL);
    if (head == NULL)
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

int main()
{
    list<int> a;
    a.InsertatTail(6);
    a.InsertatTail(3);
    a.InsertatTail(4);
    a.InsertatTail(8);
    a.InsertatTail(11);

    list<int> b;
    b.InsertatTail(5);
    b.InsertatTail(4);
    b.InsertatTail(3);
    b.InsertatTail(9);
    a.printList();
    b.printList();

    // Print list a using iterator
    for (list<int>::listiterator X = a.begin(); X != a.end(); X++)
        cout << (*X)++ << " -> ";
    cout << "NULL" << endl;

    for (list<int>::listiterator X = a.begin(); X != a.end(); X++)
        cout << (*X) << " -> ";
    cout << "NULL" << endl;

    // Print list b using iterator
    for (list<int>::listiterator X = b.begin(); X != b.end(); X++)
        cout << (*X)-- << " -> ";
    cout << "NULL" << endl;

    for (list<int>::listiterator X = b.begin(); X != b.end(); X++)
        cout << (*X) << " -> ";
    cout << "NULL" << endl;

    return 0;
}