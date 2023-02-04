#include <iostream>
using namespace std;

template <typename T>
class doubly_list
{
private:
    class node
    {
        friend class doubly_list<T>;
        T data;
        node *next;
        node *prev;
        node(T val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
    };

private:
    node *head;
    node *tail;

public:
    class iterator
    {
    protected:
        node *curr;
        friend class doubly_list<T>;

    public:
        iterator()
        {
            curr = NULL;
        }
        iterator(node *p)
        {
            curr = p;
        }
        T &operator*();
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        bool operator==(const iterator &a) const;
        bool operator!=(const iterator &a) const;
    };

public:
    doubly_list();
    ~doubly_list();
    void insert(T value);
    void print_forward();
    void print_backward();
    int getsize();
    bool search(T value);
    void erase(T value);
    void ordered_insert_iterator(iterator &a);
    iterator begin();
    iterator end();
    iterator endd();
};

template <typename T>
doubly_list<T>::doubly_list()
{
    head = NULL;
    tail = NULL;
}

template <typename T>
doubly_list<T>::~doubly_list()
{
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
}

template <typename T>
void doubly_list<T>::insert(T value)
{
    node *new_node = new node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        while (curr != NULL)
        {
            if (value < curr->data && prev == NULL)
            {
                new_node->next = curr;
                curr->prev = new_node;
                new_node->prev = prev;
                head = new_node;
                break;
            }
            if (value < curr->data)
            {
                new_node->next = curr;
                new_node->prev = prev;
                curr->prev = new_node;
                prev->next = new_node;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            tail->next = NULL;
        }
    }
}

template <typename T>
void doubly_list<T>::print_forward()
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
void doubly_list<T>::print_backward()
{
    node *curr = tail;
    while (curr != NULL)
    {
        cout << curr->data << "<-";
        curr = curr->prev;
    }
    cout << "NULL" << endl;
}

template <typename T>
int doubly_list<T>::getsize()
{
    int counter = 0;
    node *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        counter++;
    }
    return counter;
}

template <typename T>
bool doubly_list<T>::search(T value)
{
    if (head != NULL)
    {
        bool find = false;
        T end = tail->data;
        if (end / 2 < value)
        {
            node *cur = tail;
            while (cur != NULL && find == false)
            {
                if (cur->data == value)
                    find = true;
                cur = cur->prev;
            }
            return find;
        }
        else
        {
            node *cur = head;
            while (cur != NULL && find == false)
            {
                if (cur->data == value)
                    find = true;
                cur = cur->next;
            }
            return find;
        }
    }
    return 0;
}

template <typename T>
void doubly_list<T>::erase(T value)
{
    node *curr = head;
    node *priv = NULL;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            if (curr == head)
            {
                head = head->next;
                delete curr;
                head->prev = NULL;
                break;
            }
            else
            {
                priv->next = curr->next;
                if (curr == tail)
                {
                    delete tail;
                    tail = priv;
                }
                else
                {
                    curr->next->prev = priv;
                    delete curr;
                }
                break;
            }
        }
        priv = curr;
        curr = curr->next;
    }
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::begin()
{
    return head;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::end()
{
    return NULL;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::endd()
{
    return tail;
}

template <typename T>
T &doubly_list<T>::iterator::operator*()
{
    return curr->data;
}

template <typename T>
typename doubly_list<T>::iterator &doubly_list<T>::iterator::operator++()
{
    if (curr != NULL)
        this->curr = this->curr->next;
    return *this;
}


template <typename T>
typename doubly_list<T>::iterator &doubly_list<T>::iterator::operator--()
{
    if (curr != NULL)
        curr = curr->prev;
    return *this;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::iterator::operator--(int)
{
    iterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::iterator::operator++(int)
{
    iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
bool doubly_list<T>::iterator::operator==(const iterator &a) const
{
    if (this->curr == a.curr)
        return true;
    return false;
}

template <typename T>
bool doubly_list<T>::iterator ::operator!=(const iterator &a) const
{
    if (*this == a)
        return false;
    return true;
}

template <typename T>
void doubly_list<T>::ordered_insert_iterator(iterator &a)
{
    doubly_list<T>::node *new_node = new node(*a);
    insert(*a);
}

// int main()
// {
//     doubly_list<int> a;
//     a.insert(100);
//     a.insert(2);
//     a.insert(0);
//     a.insert(96);
//     a.insert(4);
//     a.insert(5);
//     a.insert(6);
//     a.print_forward();
//     a.erase(4);
//     a.print_forward();
//     a.erase(96);
//     a.print_forward();
//     a.erase(0);
//     a.print_forward();
//     a.print_backward();
//     cout << a.search(5);
//     // Iterator class driver
//     //  doubly_list<int>::iterator x = a.begin();
//     //  cout << *x << endl;
//     //  cout << *x++ << endl;
//     //  cout << *x << endl;
//     //  cout << *++x << endl;
//     //  cout << *++x << endl;

//     // Iterator class bool drivers
//     // doubly_list<int>::iterator x = a.begin();
//     // doubly_list<int>::iterator y = a.end();
//     // if (x != y)
//     //     cout << "galat";
//     // else if (x == y)
//     //     cout << "huihui";
// }