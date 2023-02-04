#include <iostream>
#include "1.cpp"
using namespace std;

template <typename T>
void printList(doubly_list<T> &a)
{
    cout << "USER-DEFINED PRINTER" << endl;
    for (typename doubly_list<T>::iterator i = a.begin(); i != a.end(); i++)
    {
        cout << *i << "->";
    }
    cout << "NULL" << endl;
}

template <typename T>
void unionList(doubly_list<T> &a, doubly_list<T> &b, doubly_list<T> &c)
{
    for (typename doubly_list<T>::iterator i = b.begin(); i != b.end(); i++)
    {
        int flag = 0;
        for (typename doubly_list<T>::iterator j = c.begin(); j != c.end(); j++)
        {
            if (*i == *j)
            {
                a.ordered_insert_iterator(i);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            a.ordered_insert_iterator(i);
        }
    }
    for (typename doubly_list<T>::iterator i = c.begin(); i != c.end(); i++)
    {
        int flag = 0;
        for (typename doubly_list<T>::iterator j = b.begin(); j != b.end(); j++)
        {
            if (*i == *j)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            a.ordered_insert_iterator(i);
        }
    }
}

template <typename T>
void intersectionList(doubly_list<T> &a, doubly_list<T> &b, doubly_list<T> &c)
{
    for (typename doubly_list<T>::iterator i = b.begin(); i != b.end(); i++)
    {
        for (typename doubly_list<T>::iterator j = c.begin(); j != c.end(); j++)
        {
            if (*i == *j)
            {
                a.ordered_insert_iterator(i);
            }
        }
    }
}

template <typename T>
void differenceList(doubly_list<T> &a, doubly_list<T> &b, doubly_list<T> &c)
{
    for (typename doubly_list<T>::iterator i = b.begin(); i != b.end(); i++)
    {
        int flag = 0;
        for (typename doubly_list<T>::iterator j = c.begin(); j != c.end(); j++)
        {
            if (*i == *j)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            a.ordered_insert_iterator(i);
        }
    }
}

template <typename T>
void bubble_sort(doubly_list<T> &a)
{
    int size = getsize(a);
    typename doubly_list<T>::iterator start = a.begin();
    typename doubly_list<T>::iterator end = a.endd();
    while (start != end)
    {
        swap(*start, *end);
        start++;
        end--;
    }
}

template <typename T>
int getsize(doubly_list<T> &a)
{
    int counter = 0;
    typename doubly_list<T>::iterator i = a.begin();
    for (; i != a.end(); i++)
        counter++;
    return counter;
}

int main()
{
    doubly_list<int> a;
    a.insert(100);
    a.insert(2);
    a.insert(0);
    a.insert(96);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    cout << "A:" << endl;
    printList<int>(a);

    doubly_list<int> b;
    b.insert(0);
    b.insert(96);
    b.insert(100);
    b.insert(200);
    cout << "B:" << endl;
    printList<int>(b);

    // UNION
    // doubly_list<int> c;
    // unionList<int>(c, b, a);
    // cout << "C:" << endl;
    // printList<int>(c);

    // INTERSECTION
    // doubly_list<int> c;
    // intersectionList<int>(c, b, a);
    // cout << "C:" << endl;
    // printList<int>(c);

    // DIFFERENCE
    // doubly_list<int> c;
    // differenceList<int>(c, a, b);
    // cout << "C:" << endl;
    // printList<int>(c);

    // BUBBLE SORT
    // bubble_sort(a);
    // printList<int>(a);
}