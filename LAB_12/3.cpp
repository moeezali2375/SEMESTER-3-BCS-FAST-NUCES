#include <iostream>
#include <vector>
using namespace std;

class minHeap
{
public:
    minHeap()
    {
    }
    minHeap(int *arr, int N)
    {
        int j = 1;
        for (int i = 0; i < N; i++)
        {
            v.push_back(arr[i]);
        }
        buildMinHeap();
    }
    void buildMinHeap()
    {
        int N = v.size();
        N--;
        for (int i = 0; i < N; i++)
        {
            bubble_down(i);
        }
    }
    void insert(const int &x)
    {
        v.push_back(x);
        int N = v.size();
        N--;
        for (int i = N; i >= 0; i--)
        {
            bubble_down(i);
        }
    }
    bool isEmpty() const
    {
        if (v.empty())
            return true;
        else
            return false;
    }
    const int &getMin() const
    {
        return v[0];
    }

    void deleteMin()
    {
        int n = v.size();
        int leafdata = v[n - 1];
        v[0] = leafdata;
        v.resize(n - 1);
        bubble_down(0);
    }
    void deleteAll(int key)
    {
        {
            int c = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == key)
                    c++;
            }
            for (int i = 0; i < c; i++)
            {
                int j = 0;
                for (j; j < v.size(); j++)
                {
                    if (v[j] == key)
                    {
                        v[j] = -1;
                        break;
                    }
                }
                bubble_up(j);
                deleteMin();
            }
        }
    }
    void print()
    {
        vector<int>::iterator iter;
        for (iter = v.begin(); iter != v.end(); ++iter)
        {
            cout << *iter << "  ";
        }
    }

private:
    vector<int> v;
    void bubble_up(int i)
    {
        if (i <= 0)
            return;
        int large = i;
        int parent = (i - 1) / 2;
        if (i != 0 && v[i] < v[parent]) // calculte the largest of parent and child
        {
            large = parent;
        }
        if (large != i)
        {
            swap(v[large], v[i]);
            bubble_up(large);
        }
    }
    void bubble_down(int i)
    {
        {
            int N = v.size();
            int min = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < N && v[l] < v[min])
                min = l;

            if (r < N && v[r] < v[min])
                min = r;

            if (min != i)
            {
                swap(v[i], v[min]);

                bubble_down(min);
            }
        }
    }
};
// void heapSortMin(int* arr, int size, int sorting_order)
//{
//	minHeap obj2(arr, size);
//	int s = size;
//	while (s > 1)
//	{
//		swap(arr[s], arr[1]);
//		s--;
//
//		obj2.bubble_down(arr, s, 1);
//	}
// }
void Heap_sort(int *arr, int size, int sorting_order)
{
    minHeap obj2(arr, size);
    if (sorting_order == 1)
    {
        while (!obj2.isEmpty())
        {
            int s = obj2.getMin();
            cout << s << " ";
            obj2.deleteMin();
        }
    }
    else
    {
        int *n = new int[size];
        int l = size - 1;
        while (!obj2.isEmpty())
        {
            int store = obj2.getMin();
            n[l] = store;
            l--;
            obj2.deleteMin();
        }
        for (int i = 0; i < 7; i++)
        {
            cout << n[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "the array is" << endl;
    int array[] = {10, 40, 50, 50, 60, 15, 20};
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "after converting to min heap " << endl;
    minHeap obj(array, 7);
    obj.print();
    cout << endl;
    cout << endl
         << "after delete all" << endl;
    obj.deleteAll(50);
    obj.print();
    cout << endl;
    cout << "after inserting 100" << endl;
    obj.insert(100);
    obj.print();

    cout << endl;
    cout << "after deleting " << endl;
    obj.deleteMin();
    obj.print();
    cout << endl;
    int x = obj.getMin();
    cout << "the minimum value of the min heap is " << x << endl;
    cout << "the first 3 min are " << endl;
    int arr[] = {10, 4, 5, 30, 3, 300};
    minHeap m(arr, 6);
    for (int i = 0; i < 3; ++i)
    {
        cout << obj.getMin() << " ";
        obj.deleteMin();
    }

    cout << endl;
    cout << "heap sort " << endl;
    int a[] = {10, 4, 5, 30, 3, 300};
    Heap_sort(a, 6, 1);

    return 0;
}