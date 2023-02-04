#include <iostream>
using namespace std;
class BST
{
    int *array;
    int size;
    int current_size;
    void grow()
    {
        int *temp = new int[2 * size];
        for (int i = 0; i < size; i++)
            temp[i] = array[i];
        for (int i = size; i < 2 * size; i++)
            temp[i] = INT_MAX;
        size = 2 * size;
        delete array;
        array = temp;
    }

public:
    BST()
    {
        array = new int[1];
        array[0] = INT_MAX;
        size = 1;
        current_size = 0;
    }
    ~BST()
    {
        delete[] array;
    }
    int left_child(int i)
    {
        return (2 * i) + 1;
    }
    int right_child(int i)
    {
        return (2 * i) + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void insertion(int key)
    {
        grow();
        insertion(key, 0);
    }
    void insertion(int key, int i)
    {
        if (array[i] == INT_MAX || array[i] == INT_MIN)
        {
            array[i] = key;
            current_size = i;
            return;
        }
        if (array[i] == key)
        {
            cout << "Can't insert the data, already exists!" << endl;
            return;
        }
        else if (key < array[i])
        {
            insertion(key, left_child(i));
        }
        else
        {
            insertion(key, right_child(i));
        }
    }
    void in_order()
    {
        cout << "Inorder printing!" << endl;
        in_order(0);
        cout << endl;
    }
    void in_order(int i)
    {
        if (array[i] == INT_MAX)
            return;
        in_order(left_child(i));
        cout << array[i] << " ";
        in_order(right_child(i));
    }
    void post_order()
    {
        cout << "Postorder printing!" << endl;
        post_order(0);
        cout << endl;
    }
    void post_order(int i)
    {
        if (array[i] == INT_MAX)
            return;
        post_order(left_child(i));
        post_order(right_child(i));
        cout << array[i] << " ";
    }
    void pre_order()
    {
        cout << "Preorder printing!" << endl;
        pre_order(0);
        cout << endl;
    }
    void pre_order(int i)
    {
        if (array[i] == INT_MAX)
            return;
        cout << array[i] << " ";
        pre_order(left_child(i));
        pre_order(right_child(i));
    }
    void print2d(int i, int space)
    {
        if (array[i] == INT_MAX)
            return;
        space += 5;
        print2d(right_child(i), space);
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << ' ';
        cout << array[i] << endl;
        print2d(left_child(i), space);
    }

    int get_predecessor(int i)
    {
        while (array[right_child(i)] != INT_MAX)
            i = right_child(i);
        return array[i];
    }
    void deletion(int key)
    {
        deletion(key, 0);
    }
    void deletion(int key, int i)
    {
        if (key < array[i])
            deletion(key, left_child(i));
        else if (key > array[i])
            deletion(key, right_child(i));
        else if (array[i] == key)
        {
            if (array[left_child(i)] == INT_MAX && array[right_child(i)] == INT_MAX)
                array[i] = INT_MAX;
            else if (array[left_child(i)] == INT_MAX && array[right_child(i)] != INT_MAX)
            {
                array[i] = array[right_child(i)];
                array[right_child(i)] = INT_MAX;
            }
            else if (array[left_child(i)] != INT_MAX && array[right_child(i)] == INT_MAX)
            {
                array[i] = array[left_child(i)];
                array[left_child(i)] = INT_MAX;
            }
            else
            {
                int predecessor = get_predecessor(left_child(i));
                array[i] = predecessor;
                deletion(predecessor, left_child(i));
            }
        }
    }
    int search(int key)
    {
        return search(key, 0);
    }
    int search(int key, int i)
    {
        if (array[i] == INT_MAX)
            return -1;
        if (array[i] == key)
        {
            return i;
        }
        else if (key < array[i])
            return search(key, left_child(i));
        else
            return search(key, right_child(i));
    }
    int get_height()
    {
        return get_height(0);
    }
    int get_height(int i)
    {
        if (array[i] == INT_MAX)
            return -1;
        int lh = get_height(left_child(i));
        int rh = get_height(right_child(i));
        if (lh > rh)
            return lh + 1;
        return rh + 1;
    }
    int get_level(int height)
    {
        int count = 0;
        get_level(0, height, count);
        return count;
    }
    void get_level(int i, int level, int &count)
    {
        if (array[i] == INT_MAX)
            return;
        if (level == 0)
            count++;
        get_level(left_child(i), level - 1, count);
        get_level(right_child(i), level - 1, count);
    }
    int leaf_nodes()
    {
        int count = 0;
        leaf_nodes(0, count);
        return count;
    }
    void leaf_nodes(int i, int &count)
    {
        if (array[i] == INT_MAX)
            return;
        if (array[left_child(i)] == INT_MAX && array[right_child(i)] == INT_MAX)
            count++;
        leaf_nodes(left_child(i), count);
        leaf_nodes(right_child(i), count);
    }
};