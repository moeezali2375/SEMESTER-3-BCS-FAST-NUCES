#include <iostream>
using namespace std;
template <typename T>

class doubly_list
{
public:
    friend class doubly_list<T>;
    class node
    {
    public:
        T data;
        node *next;
        node *prev;
        node()
        {
            // data = NULL;
            next = NULL;
            prev = NULL;
        }
        node(T value)
        {
            data = value;
            next = NULL;
            prev = NULL;
        }
    };
    node dummy_head;

public:
    class iterator
    {
        node *curr;
        friend class doubly_list<T>;

    public:
        // FUNCTIONS
        iterator();
        iterator(node *pointer);
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        T &operator*();
        bool operator==(const iterator &a) const;
        bool operator!=(const iterator &a) const;
    };
    // FUNCTIONS
    doubly_list();
    void insert_at_head(T val);
    void delete_from_head();
    void delete_all(T val);
    void replace_all(T value, T replace);
    void swap(T first, T second);
    void display();
    iterator begin();
    iterator end();
    void insert(iterator &position, T value);
    void insert_multiple(iterator &position);
    void delete_node(iterator &position);
    void delete_node_multiple(iterator &position);
    void delete_in_range(iterator &start, iterator &end);
    iterator search(T value);
    iterator *search_multiple(T value, int &size);
    doubly_list<T> &operator=(doubly_list<T> a)
    {
        doubly_list<T>::iterator i = a.begin();
        doubly_list<T>::iterator j = this->begin();
        while (this->dummy_head.next != NULL)
        {
            this->delete_from_head();
        }
        while (i != NULL)
        {
            this->insert(j,*i++);
        }
        return *this;
    }
};

template <typename T>
doubly_list<T>::doubly_list()
{
    dummy_head = NULL;
    dummy_head.next = NULL;
    dummy_head.prev = NULL;
}

template <typename T>
void doubly_list<T>::insert_at_head(T val)
{
    node *new_node = new node(val);
    if (dummy_head.next == NULL)
    {
        dummy_head.next = new_node;
        new_node->prev = &dummy_head;
    }

    else
    {
        node *temp;
        temp = dummy_head.next;
        dummy_head.next = new_node;
        new_node->prev = &dummy_head;
        new_node->next = temp;
        temp->prev = new_node;
    }
}

template <typename T>
void doubly_list<T>::delete_from_head()
{
    node *temp = dummy_head.next;
    temp = temp->next;
    delete dummy_head.next;
    dummy_head.next = temp;
}

template <typename T>
void doubly_list<T>::delete_all(T val)
{
    node *temp = dummy_head.next;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (temp == dummy_head.next)
            {
                this->delete_from_head();
                temp = temp->next;
            }
            else if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                delete temp;
                temp = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                node *del = temp;
                temp = temp->next;
                delete del;
            }
        }
        else
            temp = temp->next;
    }
}

template <typename T>
void doubly_list<T>::replace_all(T value, T replace)
{
    if (dummy_head.next != NULL)
    {
        node *temp = dummy_head.next;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                temp->data = replace;
            }
            temp = temp->next;
        }
    }
}

template <typename T>
void doubly_list<T>::swap(T first, T second)
{
    node *temp = dummy_head.next;
    node *find1 = NULL;
    node *find2 = NULL;
    node *temp1 = NULL;
    node *temp2 = NULL;
    while (temp != NULL)
    {
        if (temp->data == first)
        {
            find1 = temp;
            break;
        }
        temp = temp->next;
    }
    while (temp != NULL)
    {
        if (temp->data == second)
        {
            find2 = temp;
            break;
        }
        temp = temp->next;
    }
    if (find1 == NULL || find2 == NULL)
    {
        cout << "Error 404!\nNo data found!\n";
    }
    else
    {
        temp1 = find2->prev;
        temp2 = find2->next;
        // FIRST
        if (find1->prev != NULL)
            find1->prev->next = find2;
        else
            dummy_head.next = find2;
        find2->prev = find1->prev;
        find2->next = find1->next;
        find1->next->prev = find2;
        // SECOND
        temp1->next = find1;
        find1->prev = temp1;
        find1->next = temp2;
        if (temp2 != NULL)
            temp2->prev = find2;
    }
}

template <typename T>
void doubly_list<T>::display()
{
    node *temp = dummy_head.next;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::begin()
{
    return dummy_head.next;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::end()
{
    return NULL;
}

template <typename T>
doubly_list<T>::iterator::iterator()
{
    curr = NULL;
}

template <typename T>
doubly_list<T>::iterator::iterator(node *pointer)
{
    curr = pointer;
}

template <typename T>
typename doubly_list<T>::iterator &doubly_list<T>::iterator ::operator++()
{
    if (curr != NULL)
    {
        curr = curr->next;
    }
    return *this;
}

template <typename T>
typename doubly_list<T>::iterator &doubly_list<T>::iterator::operator--()
{
    if (curr != NULL)
    {
        curr = curr->prev;
    }
    return *this;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::iterator::operator++(int)
{
    iterator temp = *this;
    if (curr != NULL)
        curr = curr->next;
    return temp;
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::iterator::operator--(int)
{
    iterator temp = *this;
    if (curr != NULL)
        curr = curr->prev;
    return temp;
}

template <typename T>
T &doubly_list<T>::iterator::operator*()
{
    return curr->data;
}

template <typename T>
bool doubly_list<T>::iterator::operator!=(const iterator &a) const
{
    return (curr != (a.curr));
}

template <typename T>
bool doubly_list<T>::iterator::operator==(const iterator &a) const
{
    return (curr == (a.curr));
}

template <typename T>
void doubly_list<T>::insert(doubly_list<T>::iterator &position, T value)
{
    if (position == NULL)
    {
        insert_at_head(value);
        position = this->dummy_head.next;
    }
    else
    {
        node *new_node = new node(value);
        new_node->next = position.curr->next;
        if (position.curr->next != NULL)
            position.curr->next->prev = new_node;
        position.curr->next = new_node;
        new_node->prev = position.curr;
        position++;
    }
}

template <typename T>
void doubly_list<T>::insert_multiple(doubly_list<T>::iterator &position)
{
    cout << "How many nodes you want to enter?\n";
    int counter;
    cin >> counter;
    T value;
    while (counter != 0)
    {
        cout << "Enter the value: ";
        cin >> value;
        this->insert(position, value);
        counter--;
    }
}

template <typename T>
void doubly_list<T>::delete_node(doubly_list<T>::iterator &position)
{
    if (position != NULL)
    {
        if (position.curr->prev != &dummy_head)
        {
            doubly_list<T>::iterator temp = position;
            position.curr->prev->next = position.curr->next;
            if (position.curr->next != NULL)
                position.curr->next->prev = position.curr->prev;
            position--;
            delete temp.curr;
        }
        else
        {
            this->delete_from_head();
            position = NULL;
        }
    }
}

template <typename T>
void doubly_list<T>::delete_node_multiple(doubly_list<T>::iterator &position)
{
    node *curr = position.curr;
    --position;
    position.curr->next = NULL;
    curr->prev->next = NULL;
    while (curr != NULL)
    {
        node *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

template <typename T>
void doubly_list<T>::delete_in_range(doubly_list<T>::iterator &start, doubly_list<T>::iterator &end)
{
    if (end.curr == NULL)
        this->delete_node_multiple(start);
    else
    {
        while (start != end)
        {
            this->delete_node(end);
        }
        this->delete_node(end);
    }
}

template <typename T>
typename doubly_list<T>::iterator doubly_list<T>::search(T value)
{
    doubly_list<T>::iterator i = this->begin();
    while (i != NULL)
    {
        if (*i == value)
            return i;
        i++;
    }
    return NULL;
}

template <typename T>
typename doubly_list<T>::iterator *doubly_list<T>::search_multiple(T value, int &size)
{
    doubly_list<T>::iterator *array = new doubly_list<T>::iterator[1];
    doubly_list<T>::iterator i = this->begin();
    int j = 0;
    size = 0;
    while (i != this->end())
    {
        if (*i == value)
        {
            if (j >= size)
                grow(array, size);
            array[j] = i;
            j++;
        }
        i++;
    }
    return array;
}

template <typename T>
void grow(T *&array, int &size)
{
    T *new_array = new T[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    size++;
    array = new_array;
}

// int main()
// {
//     doubly_list<int> a;
//     a.insert_at_head(1);
//     a.insert_at_head(1);
//     a.insert_at_head(1);
//     doubly_list<int> b;
//     b = a;
//     b.display();
//     cout << endl;
//     a.insert_at_head(2);
//     b.display();
// }

// int main()
// {

//     doubly_list<int> a;
//     a.insert_at_head(9);
//     a.insert_at_head(7);
//     a.insert_at_head(8);
//     a.display();
//     cout << endl;
//     doubly_list<int>::iterator temp = a.begin();
//     cout << *temp++ << endl;
//     cout << *temp++ << endl;
//     cout << *temp++ << endl;
//     if (temp == NULL)
//         cout << "Fuck";
// }
// // DRIVER
// int main()
// {
//     doubly_list<char> a;
//     a.insert_at_head('c');
//     a.insert_at_head('b');
//     a.insert_at_head('a');
//     a.insert_at_head('c');
//     a.insert_at_head('d');
//     a.insert_at_head('c');
//     a.insert_at_head('e');
//     a.insert_at_head('c');
//     a.insert_at_head('x');
//     a.insert_at_head('y');
//     a.insert_at_head('c');
//     a.display();
//     cout << endl;
//     // a.swap('c', 'x');
//     a.delete_all('c');
//     a.display();
//     // a.delete_all();
//     // a.replace_all('e', 'f');
//     // a.swap('c', 'a');
//     // doubly_list<char>::iterator i = a.begin();
//     // i++;
//     // i++;
//     // i++;
//     // i++;
//     // i++;
//     // i++;
//     // i++;
//     // i++;
//     // i++;
//     // cout << *i << endl;
//     // a.insert(i,'x');
//     // a.insert_multiple(i);
//     // cout << *i << endl;
//     // a.display();
//     // cout << *i << endl;
//     // a.delete_node_multiple(i);
//     // a.delete_node(i);
//     // doubly_list<char>::iterator j = i;
//     // // i++;
//     // j = i;
//     // j++;
//     // j++;
//     // j++;
//     // i = a.begin();
//     // j = i;
//     // j++;
//     // j++;
//     // cout << *i << endl;
//     // cout << *j << endl;
//     // a.delete_in_range(i, j);

//     // a.display();
//     // cout << *i << endl;
//     // cout << *j << endl;
//     // // a.display();
//     // doubly_list<char>::iterator i = a.begin();
//     // cout << *i << endl;
//     // cout << *i++;
//     // cout << *i--;
//     // cout << *i--;
//     // cout << (i == j);
//     // a.insert_multiple(i);
//     // doubly_list<char>::iterator *array;
//     // int size;
//     // array = a.search_multiple('c', size);
//     // for (int i = 0; i < size; i++)
//     // {
//     //     cout << *array[i] << endl;
//     // }
//     //! PRINT FILE
//     // doubly_list<char>::iterator i = a.begin();
//     // doubly_list<char>::iterator temp = a.begin();
//     // while (++temp != NULL)
//     // {
//     //     i = temp;
//     //     ++temp;
//     // }
//     // while (i != NULL)
//     // {
//     //     cout << *i;
//     //     --i;
//     // }
// }
