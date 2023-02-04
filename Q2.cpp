#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

template <typename T>
class list
{
public:
    class node
    {
        T data;
        node *next;
        node *prev;
        node(T data, node *p, node *q)
        {
            this->data = data;
            next = p;
            prev = q;
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
        listiterator() { current = nullptr; }
        // Parameterized Constructor used in begin and end functions
        listiterator(node *p) { current = p; }
        // Dereference operation to provide access of data to user
        T &operator*() const { return current->data; }
        // Move forward Pre-increment
        listiterator &operator++()
        {
            if (current != nullptr)
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
        // Move backword Pre-decrement
        listiterator &operator--()
        {
            // if (current != head)
            this->current = this->current->prev;
            return *this;
        }
        // Move backward Post-decrement
        listiterator operator--(int)
        {
            listiterator old = *this;
            --(*this);
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
    listiterator end() { return 0; }

    // Other Functions of Link list
    void printForward();
    void printBackward();
    void Insert(T value);
    void InsertatTail(T value);
    bool Search(T value) const;
    void erase(T value);
    void setList()
    {
        head = nullptr;
        tail = nullptr;
    }
    node *start() { return head; }
    list()
    {
        head = nullptr;
        tail = nullptr;
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
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// print list in Forward direction
template <typename T>
void list<T>::printForward()
{
    node *current;
    current = head;
    while (current != nullptr)
    {
        cout << " -> " << current->data;
        current = current->next;
    }
}

// print list in Backward direction
template <typename T>
void list<T>::printBackward()
{
    node *ptr = tail;
    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->prev;
    }
    cout << "NULL" << endl;
}

// insertnode in order
template <typename T>
void list<T>::Insert(T value)
{
    node *nnode = new node(value, nullptr, nullptr);
    if (head == nullptr)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        node *ptr = head;
        while (ptr)
        {
            if (ptr->data > value)
            {
                nnode->prev = ptr->prev;
                nnode->next = ptr;
                if (head == ptr)
                    head = nnode;
                else
                    nnode->prev->next = nnode;
                ptr->prev = nnode;
                return;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        InsertatTail(value);
    }
}

// insertnode at tail
template <typename T>
void list<T>::InsertatTail(T value)
{
    node *nnode = new node(value, nullptr, nullptr);
    if (head == nullptr)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        tail->next = nnode;
        nnode->prev = tail;
        tail = nnode;
    }
}

// search value in list
template <typename T>
bool list<T>::Search(T value) const
{
    if (head == nullptr)
        return false;

    node *ptr;
    // if ( (value - head->data) < (tail->data - value) )
    //{
    ptr = head;
    while (ptr)
    {
        if (ptr->data == value)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
    /* }
     else
     {
         ptr = tail;
         while (ptr)
         {
             if (ptr->data == value)
             {
                 return true;
             }
             ptr = ptr -> prev;
         }
         return false;
     }*/
}

// Erase/ Delete node
template <typename T>
void list<T>::erase(T value)
{
    if (Search(value)) // if value exists in list
    {
        node *ptr = head;
        while (ptr)
        {
            if (ptr->data == value)
            {
                if (ptr == head)
                {
                    head = head->next;
                    if (head)
                        head->prev = nullptr;
                    delete ptr;
                    return;
                }
                else if (ptr == tail)
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete ptr;
                    return;
                }
                else
                {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    delete ptr;
                    return;
                }
            }
            ptr = ptr->next;
        }
    }
}

class HashTable
{
private:
    int size; // Size will always be odd
    list<string> **arr;

public:
    HashTable(int S)
    {
        if (S % 2 == 0) // making sure size is odd.
            S++;

        size = S;
        arr = new list<string> *[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = new list<string>;
            arr[i]->setList();
        }
    }

    int HashFunction(string str)
    {
        int a = 33;
        long summation = 0;

        for (int i = 0; i < str.size(); i++)
        {
            summation = summation + (str[i] * pow(a, i));
        }

        return summation % size;
    }

    void insert(string str)
    {
        int idx = HashFunction(str);

        arr[idx]->InsertatTail(str);
        // cout<<idx;
    }

    void Delete(string str)
    {
        int idx = HashFunction(str);

        arr[idx]->erase(str);
    }

    void Update(string S1, string S2)
    {
        int idx = HashFunction(S1);

        if (arr[idx]->Search(S1) == true)
        {
            arr[idx]->erase(S1);
            arr[idx]->InsertatTail(S2);
        }
    }

    list<string>::listiterator access(string S1)
    {
        int idx = HashFunction(S1);
        list<string>::listiterator X = arr[idx]->begin();

        for (; X != arr[idx]->end(); X++)
        {
            if (*X == S1)
                break;
        }
        return X;
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << endl
                 << i << " : ";
            arr[i]->printForward();
        }
    }
};

int main()
{

    HashTable S(9);
    S.insert("Fasih");
    S.insert("moeez");
    S.insert("Salman");
    S.insert("SamiUllah");
    S.insert("Hassan");
    S.insert("Haris");
    S.insert("Faizan");
    S.insert("Sohaib");

    S.Print();

    cout << "\n\nAfter deletion and update : \n";

    S.Delete("Salman");
    S.Delete("SamiUllah");
    S.Delete("Hassan");
    S.Update("Haris", "Ali");
    S.Update("Faizan", "Qasim");

    S.Print();
    cout << endl;
}
