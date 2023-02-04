#include <iostream>
using namespace std;
template <class T>
class ex
{
private:
    struct node
    {
        T data;
        struct node *next;
    };
    struct node *head, *front, *rear;

public:
    ex()
    {
        head = new node;
        head->next = NULL;
        front = rear = head;
    }
    void enqueue(T x);
    T dequeue();
    void print();
    void move_next();
};

template <class T>
void ex<T>::enqueue(T x)
{
    node *p;
    p = new node;
    p->data = x;
    if (head->next == NULL)
    {
        front = rear = p;
        head->next = p;
        p->next = p;
    }
    else
    {
        rear->next = p;
        p->next = front;
        rear = rear->next;
    }
}

template <class T>
T ex<T>::dequeue()
{
    node *t;
    T x;
    t = front;
    x = t->data;
    front = front->next;
    rear->next = front;
    delete (t);
    return x;
}

template <class T>
void ex<T>::print()
{
    node *p = front;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != rear->next);
}

template <class T>
void ex<T>::move_next()
{
    front = front->next;
    rear = rear->next;
}

/////////////////Application file
// int main()
// {
//     ex<int> e;
//     int m, n, i, d;
//     cout << "Enter the number of people";
//     cin >> n;
//     cout << "Enter the number of passes";
//     cin >> m;
//     for (i = 1; i <= n; i++)
//         e.enqueue(i);
//     cout << "The players are";
//     e.print();
//     cout << "Eliminated in order";
//     while (n > 1)
//     {
//         for (i = 1; i <= m; i++)
//             e.move_next();
//         d = e.dequeue();
//         cout << d << endl;
//         n--;
//     }
//     d = e.dequeue();
//     cout << "Winning player:	" << d << endl;
// }