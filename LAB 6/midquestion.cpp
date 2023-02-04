#include <iostream>
using namespace std;
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
    void delete_sub();
};
template <typename T>
void doubly_list<T>::delete_sub()
{
    iterator i;
    i = this->begin();
    iterator j;
    j = NULL;
    int flag = 0;
    for (; i != NULL; i++)
    {
        if (flag == 1)
            i--;
        if (*i == 1)
        {
            flag = 0;
            j = i;
            j++;
            if (j == NULL)
                return;
            else if (*j == 1)
                continue;
            else if (*j == 0)
            {
                while (j != NULL && *j != 1)
                {
                    j++;
                }
                if (j == NULL)
                {
                    iterator temp2 = i;
                    temp2--;
                    tail = temp2.curr;
                    tail->next = NULL;
                    while (i != NULL)
                    {
                        iterator temp = i++;
                        delete temp.curr;
                        temp = NULL;
                    }
                    delete i.curr;
                    temp2.curr->next = NULL;
                }
                else
                {
                    if (i.curr == this->head)
                    {
                        if (j != NULL)
                        {
                            this->head = j.curr;
                            j--;
                            head->prev = NULL;
                            j.curr->next = NULL;
                            while (i != NULL)
                            {
                                iterator temp = i;
                                i++;
                                delete temp.curr;
                            }
                            i.curr = head;
                            flag = 1;
                        }
                        else
                            head = NULL;
                    }
                    else if (*j == 1)
                    {
                        cout << "Hehe oi" << endl;
                        // --j;
                        while (i != j)
                        {
                            node *temp = i.curr;
                            i++;
                            temp->prev->next = temp->next;
                            temp->next->prev = temp->prev;
                            delete temp;
                        }
                        i--;
                    }
                }
            }
        }
    }
}

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
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
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

int main()
{
    doubly_list<int> a;
    a.insert(1);
    a.insert(0);
    a.insert(0);
    a.insert(0);
    a.insert(1);
    a.insert(1);
    a.insert(1);
    a.insert(0);
    a.insert(0);
    a.insert(0);
    a.insert(1);
    a.insert(1);
    a.insert(0);
    a.insert(0);
    a.insert(0);
    a.print_forward();
    a.delete_sub();
    a.print_forward();
}