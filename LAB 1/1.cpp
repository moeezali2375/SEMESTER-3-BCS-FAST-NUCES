#include <iostream>
using namespace std;
class Vector
{
private:
    int *arrayPtr;
    int capacity;
    int curr_elements;

public:
    Vector()
    {
        capacity = 2;
        arrayPtr = new int[2];
        curr_elements = 0;
        for (int i = 0; i < 2; i++)
        {
            arrayPtr[i] = 0;
        }
    }
    Vector(int c)
    {
        capacity = c;
        arrayPtr = new int[c];
        curr_elements = 0;
        for (int i = 0; i < c; i++)
        {
            arrayPtr[i] = 0;
        }
    }
    ~Vector()
    {
        if (capacity > 0)
            delete[] arrayPtr;
    }
    Vector(Vector &s)
    {
        capacity = s.capacity;
        curr_elements = s.curr_elements;
        arrayPtr = new int[capacity];
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
            int *new_array = new int[capacity];
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
    void operator--()
    {
        if (curr_elements > 0)
        {
            arrayPtr[curr_elements - 1] = 0;
            curr_elements--;
        }
        else
        {
            cout << "Exception occurred!\n";
        }
    }
    void operator!()
    {
        curr_elements--;
        arrayPtr[curr_elements] = 0;
    }
    void operator+(Vector a)
    {
        int *new_array = new int[capacity + a.capacity];
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
        arrayPtr = new int[capacity];
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
    int get_capacity()
    {
        return capacity;
    }
    void sort_element()
    {
        for (int i = 0; i < curr_elements - 1; i++)
        {
            for (int j = i + 1; j > 0; j--)
            {
                if (arrayPtr[j] < arrayPtr[j - 1])
                    swap(arrayPtr[j], arrayPtr[j - 1]);
            }
        }
    }
    int search_element(int key)
    {
        int low = 0;
        int high = curr_elements - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arrayPtr[mid] == key)
                return mid;
            if (key < arrayPtr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    void delete_first_element()
    {
        if (curr_elements > 0)
        {
            for (int i = 0; i < curr_elements - 1; i++)
            {
                arrayPtr[i] = arrayPtr[i + 1];
            }
            arrayPtr[curr_elements - 1] = 0;
            curr_elements--;
        }
        else
        {
            cout << "Exception!";
        }
    }
    void shuffle_element(int ind1, int ind2)
    {
        if (ind1 > curr_elements || ind2 > curr_elements)
        {
            cout << "Exception!" << endl;
            return;
        }
        else
        {
            swap(arrayPtr[ind1], arrayPtr[ind2]);
        }
    }
    friend istream &operator>>(istream &cin, Vector &a);
    friend ostream &operator<<(ostream &out, Vector &a);
};

ostream &operator<<(ostream &out, Vector &a)
{
    cout << "The capacity of the Vector is: " << a.capacity << endl;
    cout << "The current elements of the Vector are: " << a.curr_elements << endl;
    cout << "The Array is: " << endl;
    for (int i = 0; i < a.curr_elements; i++)
    {
        cout << a.arrayPtr[i] << " ";
    }
    cout << endl;
    return out;
}
istream &operator>>(istream &in, Vector &a)
{
    cout << "Enter the " << a.capacity << " elements of the vector: ";
    for (int i = 0; i < a.capacity; i++)
    {
        cin >> a.arrayPtr[i];
    }
    a.curr_elements = a.capacity;
    cout << "Size full";
    return in;
}

int main()
{
    Vector a;
    // cin >> a;
    a + 100;
    cout << a;
    a + 2;
    cout << a;
    a + 3;
    cout << a;
    a + 5;
    cout << a;
    a.sort_element();
    cout << a;
    a.delete_first_element();
    cout << a;
    --a;
    cout << a;
    // cout << a.search_element(3) << endl;
    // cout << a.get_capacity() << endl;
    // ;
    // cout << a;

    // Vector a1(3);
    // cout << "Vector with default constructor is: " << a1;
    // a1 + 2;
    // cout << a1;
    // a1 + 3;
    // cout << a1;
    // a1 + 4;
    // cout << a1;
    // a1 + 4;
    // cout << a1;
    // !a1;
    // cout << a1;
    // Vector a1;
    // Vector a2;
    // cout << a1 << a2;
    // a1 + 2;
    // cout << a1;
    // a1 + a2;
    // cout << a1;
    // Vector a3;
    // a3 = a1;
    // cout << a3;
}