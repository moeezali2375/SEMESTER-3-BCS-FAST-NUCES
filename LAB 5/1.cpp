#include <iostream>
using namespace std;
template <typename T>
class Stack
{
public:
    struct node
    {
        friend class Stack;
        T data;
        node *next;

    public:
        node(T val)
        {
            data = val;
            next = NULL;
        }
    };

private:
    node *top; // we will treat it as HEAD
    int size;
    int current_size;

public:
    Stack();
    Stack(int size);
    ~Stack();
    bool push(T val);
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
    top = NULL;
    this->size = size;
    current_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    for (int i = 0; i < this->current_size; i++)
    {
        delete top;
        top = top->next;
    }
}

template <typename T>
bool Stack<T>::push(T val)
{
    if (current_size == size)
    {
        cout << "Stack Full!" << endl;
        return false;
    }
    node *new_node = new node(val);
    node *temp = top;
    top = new_node;
    new_node->next = temp;
    current_size++;
    return true;
}

template <typename T>
bool Stack<T>::pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty!" << endl;
        return false;
    }
    cout << "POP: " << top->data << endl;
    node *temp = top;
    top = top->next;
    delete temp;
    current_size--;
    return true;
}

template <typename T>
bool Stack<T>::topp(T &value)
{
    if (top == NULL)
    {
        cout << "Stack is Empty!" << endl;
        return false;
    }
    value = top->data;
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
    node *temp = top;
    for (int i = 0; i < current_size; i++)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Stack<int> a(5);
    int choice = -1;
    while (choice != 0)
    {
        cout << "0.Exit" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Top" << endl;
        cout << "4.Is_Empty" << endl;
        cout << "5.Is_Full" << endl;
        cout << "6.Display Stack" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "Program exited!" << endl;
            break;
        }
        case 1:
        {
            cout << "Enter the value you want to push: ";
            int val;
            cin >> val;
            a.push(val);
            break;
        }
        case 2:
        {
            a.pop();
            break;
        }
        case 3:
        {
            int top_value;
            if (a.topp(top_value))
                cout << "The top value is: " << top_value << endl;
            else
                ;
            break;
        }
        case 4:
        {
            if (a.isEmpty())
                cout << "The stack is empty" << endl;
            else
                cout << "The stack is not empty" << endl;
            break;
        }
        case 5:
        {
            if (a.isFull())
                cout << "The stack is Full" << endl;
            else
                cout << "The stack is not Full" << endl;
            break;
        }
        case 6:
        {
            a.display();
            break;
        }
        }
    }
}