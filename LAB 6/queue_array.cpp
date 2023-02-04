//=========================================================
//                                                         
//               #####   ##   ##  #####  ##   ##  #####  
//              ##   ##  ##   ##  ##     ##   ##  ##     
//              ##   ##  ##   ##  #####  ##   ##  #####  
//               #####   ##   ##  ##     ##   ##  ##     
//              ##        #####   #####   #####   #####  
//                                                         
//=========================================================

#include <iostream>
using namespace std;
template <typename T>
class queue
{
private:
    T *array;
    int size;
    int front;
    int rear;

public:
    queue(int s);
    ~queue();
    bool isEmpty();
    bool isFull();
    void enqueue(T value);
    void dequeue(T &value);
    void print();
};

template <typename T>
queue<T>::queue(int s)
{
    size = s;
    array = new T[size];
    front = rear = -1;
}

template <typename T>
queue<T>::~queue()
{
    delete[] array;
}

template <typename T>
bool queue<T>::isEmpty()
{
    if (rear == -1)
        return true;
    return false;
}

template <typename T>
bool queue<T>::isFull()
{
    if (rear == size)
        return true;
    return false;
}

template <typename T>
void queue<T>::enqueue(T value)
{
    if (isFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        rear = front = 0;
    }
    array[rear++] = value;
}

template <typename T>
void queue<T>::dequeue(T &value)
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
        value = array[front++];
}

template <typename T>
void queue<T>::print()
{
    cout << "First-Out<-";
    for (int i = front; i < rear; i++)
    {
        cout << array[i] << "<-";
    }
    cout << "First-in" << endl;
}

// int main()
// {
//     queue<int> a(5);
//     for (int i = 99; i < 99 + 5; i++)
//         a.enqueue(i);
//     a.print();
//     int j;
//     a.dequeue(j);
//     cout << endl
//          << j << endl;
//     a.print();
//     a.dequeue(j);
//     cout << endl
//          << j << endl;
//     a.print();
//     a.dequeue(j);
//     cout << endl
//          << j << endl;
//     a.print();
//     a.dequeue(j);
//     cout << endl
//          << j << endl;
//     a.print();
//     a.dequeue(j);
//     cout << endl
//          << j << endl;
//     a.print();
//     a.dequeue(j);
// }