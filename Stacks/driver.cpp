#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    cout << "WELCOME!" << endl;
    stacks<char> a(5);
    int choice = -1;
    cout << a.pop();
    while (choice != 0)
    {
        cout << "1. Push?" << endl;
        cout << "2. Pop?" << endl;
        cout << "3. isEmpty?" << endl;
        cout << "4. isFull?" << endl;
        cout << "5. Peek?" << endl;
        cout << "6. Count?" << endl;
        cout << "7. Display Stack?" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the element you want to enter: " << endl;
            char c;
            cin >> c;
            a.push(c);
            break;
        case 2:
            cout << "POP: " << a.pop() << endl;
            break;
        case 3:
            if (a.isEmpty())
                cout << "List is Empty\n";
            else
                cout << "List is not Empty\n";
            break;
        case 4:
            if (a.isFull())
                cout << "List is Full\n";
            else
                cout << "List is not Full\n";
            break;
        case 5:
            cout << "Enter the value you want to Peek for: ";
            int peek;
            cin >> peek;
            a.peek(peek);
            break;
        case 6:
            cout << "The total values in the stack are: " << a.count_stack() << endl;
            break;
        case 7:
            a.display_stack();
            break;
        default:
            cout << "Please select a correct choice!" << endl;
        }
    }
}