
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
    void operator--()
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
    int search_element(T key)
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
    Vector<int> v1;
    cin >> v1;
    cout << v1;
}