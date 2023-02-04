#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    T *top;
    int size;
    int current_size;

public:
    Stack();
    Stack(int size);
    ~Stack();
    bool push(T &val);
    bool pop();
    bool topp(T &val);
    bool isEmpty();
    bool isFull();
    void display();
};

template <typename T>
Stack<T>::Stack()
{
    top = NULL;
    size = 0;
    current_size = 0;
}

template <typename T>
Stack<T>::Stack(int size)
{
    this->size = size;
    top = new T[size];
    current_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    if (size > 0)
        delete[] top;
}

template <typename T>
bool Stack<T>::push(T &val)
{
    int flag = 0;
    if (current_size == size)
    {

        flag = 1;
    }
    if (flag == 1)
    {
        for (int i = 1; i < size ; i++)
            top[i - 1] = top[i];
        top[current_size-1] = val;
    }
    else
        top[current_size++] = val;
    return true;
}

template <typename T>
bool Stack<T>::pop()
{
    if (current_size == 0)
    {
        cout << "Stack is Empty!" << endl;
        return false;
    }
    // cout << "POP: " << top[--current_size] << endl;
    --current_size;
    return true;
}

template <typename T>
bool Stack<T>::topp(T &value)
{
    if (current_size == 0)
    {
        cout << "Stack is Empty!" << endl;
        return false;
    }
    value = top[current_size - 1];
    return true;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return (this->current_size == 0);
}

template <typename T>
bool Stack<T>::isFull()
{
    return (this->current_size == size);
}

template <typename T>
void Stack<T>::display()
{
    for (int i = 0; i < current_size; i++)
    {
        cout << top[i] << "->";
    }
    cout << "NULL" << endl;
}
