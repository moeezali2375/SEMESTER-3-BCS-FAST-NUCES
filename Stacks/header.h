#include <iostream>
using namespace std;
template <typename T>

class stacks
{
private:
    T top;
    T *array;
    int length;

public:
    stacks(int size);
    ~stacks();
    bool isEmpty();
    bool isFull();
    void push(T value);
    T pop();
    void peek(int index);
    int count_stack();
    void display_stack();
};

template <typename T>
stacks<T>::stacks(int size)
{
    top = -1;
    length = size;
    array = new T[--size];
    while (size >= 0)
        array[size--] = 0;
}

template <typename T>
stacks<T>::~stacks()
{
    delete[] array;
}

template <typename T>
bool stacks<T>::isEmpty()
{
    return (top == 0);
}

template <typename T>
bool stacks<T>::isFull()
{
    return (top == length);
}

template <typename T>
void stacks<T>::push(T value)
{
    array[top++] = value;
}

template <typename T>
T stacks<T>::pop()
{
    char temp = array[top];
    array[top] = 0;
    top--;
    return temp;
}

template <typename T>
void stacks<T>::peek(int index)
{
    if (index > 0 && index <= length)
    {
        cout << "PEEKING: " << endl;
        cout << array[index] << endl;
    }
}

template <typename T>
int stacks<T>::count_stack()
{
    return top;
}

template <typename T>
void stacks<T>::display_stack()
{
    cout << "Stack is: " << endl;
    int counter = count_stack();
    while (counter >= 0)
        cout << array[--counter] << "\n|\n";
    cout << "NULL" << endl;
}