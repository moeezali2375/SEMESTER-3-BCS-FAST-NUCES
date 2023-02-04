#include <iostream>
// #include <string>
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
        // cout << "Stack Full!" << endl;
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
    // cout << "POP: " << top->data << endl;
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
        // cout << "Stack is Empty!" << endl;
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

bool checkParenthesis(char *array)
{
    Stack<char> a(strlen(array));
    bool flag = 1;
    for (int i = 0; i < strlen(array); i++)
    {
        char check = ' ';
        if (array[i] == '(' || array[i] == '{' || array[i] == '[')
            a.push(array[i]);
        else if (array[i] == ')' && a.topp(check))
        {
            if (check == '(')
                a.pop();
            else
                return false;
        }
        else if (array[i] == '}' && a.topp(check))
        {
            if (check == '{')
                a.pop();
            else
                return false;
        }
        else if (array[i] == ']' && a.topp(check))
        {
            if (check == '[')
                a.pop();
            else
                return false;
        }
    }
    if (a.isEmpty())
        return true;
    return false;
}

void infix_to_postfix(char *array)
{
    Stack<char> a(strlen(array));
    char *new_array = new char[1000];
    int j = 0;
    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i] == '+' || array[i] == '*' || array[i] == '/' || array[i] == '-')
            a.push(array[i]);
        else if (array[i] == ' ')
            continue;
        else
            new_array[j++] = array[i];
    }
    while (!a.isEmpty())
    {
        char temp;
        a.topp(temp);
        a.pop();
        new_array[j++] = temp;
    }
    delete[] array;
    array = new_array;
    cout << array << endl;
}

void evaluate_postfix(char *postfix)
{
    int i = 0, v1 = 0, v2 = 0, res = 0;
    Stack<int> val(strlen(postfix));
    while (postfix[i] != 0)
    {
        if (postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '+')
        {
            val.topp(v1);
            val.pop();
            val.topp(v2);
            val.pop();
            if (postfix[i] == '+')
                res = v2 + v1;
            else if (postfix[i] == '*')
                res = v2 * v1;
            else if (postfix[i] == '-')
                res = v2 - v1;
            else if (postfix[i] == '/')
                res = v2 / v1;
            val.push(res);
        }
        else if (postfix[i] == ' ')
            continue;
        else
        {
            res = (int)postfix[i];
            res -= 48;
            cout << "push: " << res << endl;
            val.push(res);
        }
        i++;
    }
    val.topp(v1);
    cout << "answer of " << postfix << " is  :  " << v1 << endl;
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
        cout << "7.Check Parenthesis" << endl;
        cout << "8. Infix to postfix" << endl;
        cout << "8. Evaluate postfix" << endl;
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
        case 7:
        {
            cout << "Please enter the string: " << endl;
            cin.ignore();
            char *array = new char[1000];
            cin.getline(array, 1000);
            cout << "The array is: ";
            cout << array << endl;
            if (checkParenthesis(array))
                cout << "The statement is true!" << endl;
            else
                cout << "The statement is false!" << endl;
            break;
        }
        case 8:
        {
            cout << "Please enter the string: " << endl;
            cin.ignore();
            char *array = new char[1000];
            cin.getline(array, 1000);
            cout << "The array is: ";
            cout << array << endl;
            infix_to_postfix(array);
            break;
        }
        case 9:
        {
            cout << "Please enter the string: " << endl;
            cin.ignore();
            char *array = new char[1000];
            cin.getline(array, 1000);
            cout << "The array is: ";
            cout << array << endl;
            evaluate_postfix(array);
            break;
        }
        }
    }
}