#include <iostream>
using namespace std;
template <class T>
class list // start list class
{
public:
    list() // default constructor
    {
        this->dummyhead.next = NULL;
        this->dummyhead.prev = NULL;
        // this->dummyhead.data=-1;
    }
    template <class N>
    void insertAtHead(T val) // insert val at head
    {
        //    node<T>*temp=new node<T>(val);
        //    node<T>*previous=&dummyhead;
        //    temp->next=previous->next;
        //    previous->next=temp;
        // idk previous for this func
        node<T> *temp = NULL;
        node<T> *new_node = new node<T>(val);
        temp = dummyhead.next;
        dummyhead.next = new_node;
        new_node->prev = &dummyhead;
        new_node->next = temp;
        if (temp != NULL)
        {
            temp->prev = new_node;
        }
    }
    template <class N>
    void print() // print the values present in linked list
    {
        node<T> *curr = dummyhead.next;
        std::cout << "NULL <= ";
        while (curr != NULL)
        {
            std::cout << curr->data;
            std::cout << " => ";
            curr = curr->next;
        }
        std::cout << " NULL";
    }
    template <class N>
    void deletefromhead() // delete a value from head
    {

        dummyhead.next->prev = &dummyhead;
        node<T> *curr = dummyhead.next;
        dummyhead.next = curr->next;
        auto val = curr->data;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        if (dummyhead.next == NULL)
        {
            std::cout << "\n List is Empty with last node deleted >> " << val << "\n";
        }
        else
            std::cout << "\n Cleared node with data >> " << val << "\n";
    }
    template <class N>
    void deleteall(T val) // delete all values in linked list
    {
        node<T> *curr = dummyhead.next;
        auto count = 0;
        while (curr != NULL)
        {
            if (curr->data == val)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                break;
                node<T> *previous = curr->prev;
                delete curr;
                curr->next = NULL;
                curr->prev = NULL;
                curr = previous;
                curr = curr->next;
            }
            else
                curr = curr->next;
        }
        std::cout << "\n Number of Nodes with value found are >> " << count;
    }

    template <class N>
    void replaceall(T search_item, T replace_item) // replace all elements in list by a specific value
    {
        node<T> *curr = &dummyhead;
        while (curr != NULL)
        {
            if (curr->data == search_item)
            {
                curr->data = replace_item;
            }
            curr = curr->next;
        }
    }
    // template<class N>
    // void swap(T search_node,T swap_node)
    // {
    // node<T>*curr=dummyhead.next;
    // while(curr!=NULL)
    // {
    //     if(curr->data==search_node)
    //     {
    //         node<T>*temp=curr->next;
    //         while(temp!=NULL)
    //         {
    //             if(temp->data==swap_node)
    //         {
    //             node<T>*a=temp; // new node
    //             node<T>*b=curr;
    //             dummyhead.next=curr->next;
    //             temp->next=b;
    //             curr=a->next;
    //             curr->prev=a;
    //             temp->prev=a->prev;
    //             return;
    //             // auto val=temp->data;
    //             // temp->data=curr->data;
    //             // curr->data=val;
    //         }
    //         temp=temp->next;
    //         }
    //         curr=curr->next;
    //     }
    //     else
    //     { std::cout<<"\n Element to swap not found \n";return;
    //     }
    // }
    //}
    template <class N>
    class node // start node class
    {
    private:
        T data;
        node *next;
        node *prev;
        friend class list<T>;

    public:
        // node(T &&d, node<T> *p = NULL, node<T> *n = NULL) : data{std::move(d)}, prev{p}, next{n} {}
        node() // defaukt constructor
        {
            this->next = NULL;
            this->prev = NULL;
            // this->data=NULL;
        }
        node(int val) // parameterized constructor
        {
            this->data = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    // end of node class
    template <class I>
    class iterator // start of iterator class
    {
    private:
        friend class list<T>;
        node<T> *curr;

    public:
        iterator() // default constructor
        {
            this->curr = NULL;
        }
        iterator(node<T> *p) // copy constructor
        {
            this->curr = p;
        }
        // ->>>>>>>>>>>> Operators <<<<<<<<<<<<<-

        iterator &operator++() // increment operator
        {
            if (this->curr != NULL)
            {
                this->curr = this->curr->next;
                return *this;
            }
            return *this;
        }
        iterator &operator--()
        {
            if (this->curr != NULL)
            {
                this->curr = this->curr->prev;
                return *this;
            }
            return *this;
        }
        iterator operator--(int)
        {
            if (this->curr != NULL)
            {
                iterator old = *this;
                --(*this);
                return old;
            }
            return *this;
        }
        bool operator==(const iterator &i) const
        {
            return this->curr == i.curr;
        }
        bool operator!=(const iterator &i) const
        {
            return !(*this == i);
        }
        iterator operator++(int)
        {
            if (this->curr != NULL)
            {
                iterator old = *this;
                ++(*this);
                return old;
            }
            return *this;
        }
        T &operator*()
        {
            return this->curr->data;
        }
    };
    template <class I>
    void insert(iterator<T> &obj, int val)
    {
        node<T> *newNode = new node<T>(val);
        iterator<T> temp = obj.curr;
        temp++;
        obj.curr->next = newNode;
        newNode->prev = obj.curr;
        newNode->next = temp.curr;
        temp.curr->prev = newNode;
        obj++;
    }
    // iterator class end
    // continue to list class
    iterator<T> begin() // begin func for loop
    {
        return this->dummyhead.next;
    }
    iterator<T> end() // end func for lopp
    {
        return NULL;
    }

private:
    node<T> dummyhead;
    // friend class iterator;
};
// end of list class
// start of main function
int main(void)
{
    list<int> s;
    s.insertAtHead<int>(2);
    s.insertAtHead<int>(2);
    s.insertAtHead<int>(3);
    s.print<int>();
    std::cout << "\n\n";
    // s.deleteall<int>(2);
    list<int>::iterator<int> i = s.begin();
    cout << "I: " << *i << endl;
    s.insert<int>(i, 5);
    cout<<"h\n";
    s.print<int>();
    std::cout << "\n\n";
    // cout << *i << endl;
    // ++i;
    // cout << *i << endl;
    // s.print<int>();
    // s.deleteall<int>();
    // s.replaceall<int>(1,69);
    // std::cout<<"\n After replaceing > \n\n";
    // // s.swap<int>(3,2);
    // s.print<int>();
    // std::cout<<"\n\n";
    // auto count=0;
    // list<int>::iterator<int>i=s.begin();
    // std::cout<<*i;
    // i++;
    // std::cout<<std::endl;
    // std::cout<<*i;
    // std::cout<<std::endl;
    // s.insert<int>(i,5);
    //  i++;
    // std::cout<<std::endl;
    // std::cout<<*i;
    // std::cout<<std::endl;

    //  i++;
    // std::cout<<*i;
    // std::cout<<std::endl;
    // error in iterator for reverse iteration i--
    // operator issue
    // ask moeez
    //     for(list<int>::iterator<int> i=s.end();i!=s.begin();i--)
    //     {
    // count++;
    // std::cout<<"\noksi\n";
    //     }
    //     std::cout<<"\n";
    //     std::cout<<"size is >> "<<count;

    // std::cout<<"\n\n";
    // s.print<int>();
    // s.deletefromhead<int>();
    // std::cout<<"\n\n";
    // s.print<int>();
    // s.deletefromhead<int>();
    // std::cout<<"\n\n";
    // s.print<int>();
}