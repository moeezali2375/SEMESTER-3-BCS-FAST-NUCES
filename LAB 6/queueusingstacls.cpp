


////===============================================================================================================================================
//                                                                                                                                               
//   #####   ##   ##  #####  ##   ##  #####        ##   ##   ####  ##  ##     ##   ####           ####  ######    ###     ####  ##  ##   ####  
//  ##   ##  ##   ##  ##     ##   ##  ##           ##   ##  ##     ##  ####   ##  ##             ##       ##     ## ##   ##     ## ##   ##     
//  ##   ##  ##   ##  #####  ##   ##  #####        ##   ##   ###   ##  ##  ## ##  ##  ###         ###     ##    ##   ##  ##     ####     ###   
//   #####   ##   ##  ##     ##   ##  ##           ##   ##     ##  ##  ##    ###  ##   ##           ##    ##    #######  ##     ## ##      ##  
//  ##        #####   #####   #####   #####         #####   ####   ##  ##     ##   ####          ####     ##    ##   ##   ####  ##  ##  ####   
//                                                                                                                                               
//===============================================================================================================================================


#include <iostream>
using namespace std;

template <typename T>
class list
{
public:
    class node 
    {
        T  data;
        node* next;
        node* prev;
        node(T data, node* p, node* q) { this->data = data; next = p; prev = q; }
        friend class list<T>;
    };

    //Other Functions of Link list
    void  printForward();
    //void printBackward();
    void  Insert(T value);
    void  InsertatTail(T value);
    bool Search(T value) const;
    void erase();
    bool empty();
    T end();
    list() { head = nullptr; tail = nullptr; }
    ~list();
private:
    node* head;
    node* tail;
};


template <typename T>
class stack
{
    list<T>* ptr;
public:

    stack()
    {
        ptr = new list<T>;
    }

    void push(T val)
    {
        ptr->InsertatTail(val);
    }

    void pop()
    {
        ptr->erase();
    }

    T top()
    {
        return ptr->end();
    }

    bool isEmpty()
    {
        return ptr->empty();
    }

    void Print()
    {
        ptr->printForward();
    }

    ~stack()
    {
        delete ptr;
        ptr = nullptr;
    }
};

// ---------Queue Class------------------------
template <typename T>
class queue
{
private:
    stack<T> Stk;
public:
    bool IsFull()
    {
        return false; //linklist doesnot have size restriction.
    }
    bool IsEmpty()
    {
        return Stk.isEmpty();
    }
    void Enqueue(T val)
    {
        Stk.push(val);
    }
    bool Dequeue(T& val)
    {
        if (Stk.isEmpty())
            return false;
        
        stack<T> Stk2;
        do
        {
            Stk2.push(Stk.top());
            Stk.pop();
        } while (!(Stk.isEmpty()));
        val = Stk2.top();
        Stk2.pop();
        do
        {
            Stk.push(Stk2.top());
            Stk2.pop();
        } while (!(Stk2.isEmpty()));
        return true;
    }
    void Print()
    {
        cout << "Queue: ";
        Stk.Print();
    }
};

//Destructor
template <typename T>
list<T>::~list()
{
    node* temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

//insertnode at tail
template <typename T>
void list<T>::InsertatTail(T value)
{
    node* nnode = new node(value, nullptr, nullptr);
    if (head == nullptr)
    {
        head = nnode;
        tail = nnode;
    }
    else {
        tail->next = nnode;
        nnode->prev = tail;
        tail = nnode;
    }

}

template <typename T>
void list<T>::erase()
{
    if (tail == nullptr) //if no node exists.
    {
        cout << "Error! stack is empty.";
    }
    else if (!tail->prev) //if it is the last node.
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else   //if it is NOT the last node.
    {
        node* ptr = tail->prev;
        if (tail->prev)
            tail->prev->next = nullptr;
        delete tail;
        tail = ptr;

    }
}

template <typename T>
T list<T>::end()
{
    if (tail == nullptr)
    {
        cout << "Error! stack is empty.";
    }
    else
    {
        return tail->data;
    }
    //return 0;
}

//print list in Forward direction
template <typename T>
void list<T>::printForward()
{
    node* current;
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
bool list<T>::empty()
{
    if (tail == nullptr)
        return  true;
    else
        return false;
}


int main()
{
    queue<int> Q;
    int val;
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(6);
    Q.Enqueue(7);
    Q.Enqueue(10);
    Q.Print();
    Q.Dequeue(val);
    Q.Print();
    cout <<"Dequeued value: "<< val<<endl;
    return 0;
}