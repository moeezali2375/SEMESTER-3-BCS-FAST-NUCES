
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    T *arrayPtr;
    int capacity;
    int curr_elements;

public:
    Vector()
    {
        capacity = 2;
        arrayPtr = new T[2];
        curr_elements = 0;
        for (int i = 0; i < 2; i++)
        {
            arrayPtr[i] = 0;
        }
    }
    Vector(int c)
    {
        capacity = c;
        arrayPtr = new T[c];
        curr_elements = 0;
        for (int i = 0; i < c; i++)
        {
            arrayPtr[i] = 0;
        }
    }
    ~Vector()
    {
        delete[] arrayPtr;
    }
    Vector(Vector &s)
    {
        capacity = s.capacity;
        curr_elements = s.curr_elements;
        arrayPtr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            this->arrayPtr[i] = s.arrayPtr[i];
        }
    }
    void operator+(int a)
    {
        curr_elements++;
        if (curr_elements > capacity)
        {
            int temp = capacity;
            capacity *= 2;
            T *new_array = new T[capacity];
            for (int i = 0; i < temp; i++)
            {
                new_array[i] = arrayPtr[i];
            }
            new_array[temp] = a;
            delete[] arrayPtr;
            arrayPtr = new_array;
        }
        else
        {
            arrayPtr[curr_elements - 1] = a;
        }
    }
    void operator!()
    {
        curr_elements--;
        arrayPtr[curr_elements] = 0;
    }
    void operator+(Vector a)
    {
        int *new_array = new T[capacity + a.capacity];
        for (int i = 0; i < capacity; i++)
            new_array[i] = arrayPtr[i];
        for (int i = capacity, k = 0; i < capacity + a.capacity; i++, k++)
        {
            new_array[i] = a.arrayPtr[k];
        }
        delete[] arrayPtr;
        arrayPtr = new_array;
        capacity = capacity + a.capacity;
        curr_elements = curr_elements + a.curr_elements;
    }
    void operator=(Vector a)
    {
        delete[] arrayPtr;
        capacity = a.capacity;
        curr_elements = a.curr_elements;

        arrayPtr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arrayPtr[i] = a.arrayPtr[i];
        }
    }
    bool operator[](int a)
    {
        if (a > capacity)
            return true;
        return false;
    }
    friend istream &operator>>(istream &cin, Vector &a)
    {
        cout << "Enter the " << a.capacity << " elements of the vector: ";
        for (int i = 0; i < a.capacity; i++)
        {
            cin >> a.arrayPtr[i];
        }
        cout << "Size full";
        a.curr_elements = a.capacity;
        return cin;
    }
    friend ostream &operator<<(ostream &out, Vector &a)
    {
        cout << "The capacity of the Vector is: " << a.capacity << endl;
        cout << "The current elements of the Vector are: " << a.curr_elements << endl;
        cout << "The Array is: " << endl;
        for (int i = 0; i < a.capacity; i++)
        {
            cout << a.arrayPtr[i] << " ";
        }
        cout << endl;

        return out;
    }
};

int main()
{
    Vector<char> v1;
    cin >> v1;
    cout << v1;
    v1 + 70;
    cout << v1;
}