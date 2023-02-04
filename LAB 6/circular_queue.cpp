//=================================================================================================================================
//                                                                                                                                 
//               ####  ##  #####     ####  ##   ##  ##        ###    #####               #####   ##   ##  #####  ##   ##  #####  
//              ##     ##  ##  ##   ##     ##   ##  ##       ## ##   ##  ##             ##   ##  ##   ##  ##     ##   ##  ##     
//              ##     ##  #####    ##     ##   ##  ##      ##   ##  #####              ##   ##  ##   ##  #####  ##   ##  #####  
//              ##     ##  ##  ##   ##     ##   ##  ##      #######  ##  ##              #####   ##   ##  ##     ##   ##  ##     
//               ####  ##  ##   ##   ####   #####   ######  ##   ##  ##   ##  ########  ##        #####   #####   #####   #####  
//                                                                                                                                 
//=================================================================================================================================

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
    if (rear == front && rear != -1)
        return true;
    return false;
}

template <typename T>
void queue<T>::enqueue(T value)
{
    if (front != 0 && front != -1 &&rear==size)
    {
        rear = 0;
    }
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
    if (front == -1)
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    else if (front < rear)
    {
        cout << "First-Out<-";
        for (int i = front; i < rear; i++)
        {
            cout << array[i] << "<-";
        }
        cout << "First-in" << endl;
    }
    else
    {
        cout << "First-Out<-";
        for (int i = front; i < size; i++)
        {
            cout << array[i] << "<-";
        }
        for (int i = 0; i < rear; i++)
        {
            cout << array[i] << "<-";
        }
        cout << "First-in" << endl;
    }
}

int main()
{
    queue<int> q(5);

    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    // Display elements present in Circular Queue
    q.print();

    // Deleting elements from Circular Queue
    int d;
    q.dequeue(d);
    cout << "Delete 1: " << d << endl;
    q.dequeue(d);
    cout << "Delete 2: " << d << endl;
    q.print();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);

    q.print();
    return 0;
}
