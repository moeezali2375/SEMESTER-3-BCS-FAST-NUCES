#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d, Node *n, Node *p)
    {
        data = d;
        next = n;
    }
};
class Queue
{
public:
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool IsEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    }
    void Enqueue(int val)
    {
        Node *n = new Node;
        n->data = val;
        if (IsEmpty())
        {
            n->next = NULL;
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
            n->next = nullptr;
        }
    }
    int Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Empty!" << endl;
            return 0;
        }
        else
        {
            Node *temp = front;
            front = temp->next;
            cout << "Dequeued values is: " << temp->data << std::endl;
            int return_value = temp->data;
            delete temp;
            return return_value;
        }
    }
    bool Top(int val)
    {
        if (IsEmpty())
        {
            cout << "Underflow" << std::endl;
            return false;
        }
        else if (rear->data == val)
        {
            return true;
        }
        else
            return false;
    }
    void Print()
    {
        if (this->front != nullptr)
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << " " << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
            cout << " Empty!";
    }
    ~Queue()
    {
        if (!IsEmpty())
        {
            Node *temp;
            while (front != NULL)
            {
                temp = front;
                front = front->next;
                delete temp;
            }
        }
    }
};

int getmax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Maximum: " << max << endl;
    return max;
}

void RadixSort(int *arr, int size)
{
    int m = getmax(arr, size);
    int x = 1;
    while (m / 10 > 0)
    {
        m /= 10;
        x++;
    }
    cout << "The total number of digits are: " << x << endl;
    for (int I = 0; I < x; I++)
    {
        Queue *obj = new Queue[10];
        for (int i = 0; i < size; i++)
        {
            int y = 0;
            int value = arr[i];
            int index = 0;
            while (y <= I)
            {
                index = value % 10;
                value /= 10;
                y++;
            }
            obj[index].Enqueue(arr[i]);
        }
        int counter = 0;
        for (int q = 0; q < size; q++)
        {
            if (obj[counter].IsEmpty())
            {
                q--;
                counter++;
            }
            else
            {
                // TODO
                arr[q] = obj[counter].Dequeue();
            }
        }
        delete[] obj;
    }
}
// void RadixSort_String(string arr[], int size)
// {

//     int m = arr->length();
//     cout << "The total number of letters are: " << m << endl;
//     int x = m;
//     int char_index= m - 1;
//     for (int I = 0; I < x; I++)
//     {
//         Queue *obj = new Queue[10]; // USE HERE a string queue to
//         for (int i = 0; i < size; i++)
//         {
//             int index = int(arr[i][char_index]);
//             index -= 97;
//             obj[index].Enqueue(arr[i]);
//         }
//         char_index--;
//         int counter = 0;
//         for (int q = 0; q < size; q++)
//         {
//             if (obj[counter].IsEmpty())
//             {
//                 q--;
//                 counter++;
//             }
//             else
//             {
//                 // TODO
//                 arr[q] = obj[counter].Dequeue();
//             }
//         }
//         delete[] obj;
//     }
// }

int main()
{
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    cout << endl;
    int *arr = new int[size];
    cout << "Enter the values in the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Value[" << i << "]:";
        cin >> arr[i];
    }
    cout << endl;

    RadixSort(arr, size);

    cout << "Before sorting the values stored in the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    return 0;
}

