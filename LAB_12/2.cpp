#include <iostream>
using namespace std;
struct node
{
    node *next;
    int key;
    int value;
    int present;
    node()
    {
        next = NULL;
        key = value = 0;
        present = 0;
    }
    node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
        present = 0;
    }
};
class HashTable
{
private:
    int size; // Size will always be odd
    node *arr;
    int c_method;
    bool re_hash;

public:
    // loading f is the no of elements divided by the size of
    HashTable(bool f, int c)
    {
        size = 13;
        arr = new node[size];
        c_method = c;
        re_hash = f;
    }
    float cal_lf()
    {
        float c = 1;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].value != 0)
            {
                c++;
            }
        }
        c = c / size;
        return c;
    }
    float loading_factor()
    {
        float ans = cal_lf();
        return ans;
    }
    void call_rehashing()
    {
        node *store_arr = new node[size * 2];
        size *= 2;
        for (int i = 0; i < size / 2; i++)
        {
            if (arr[i].present == 1)
            {
                insertion(arr[i].key, arr[i].value, store_arr);
            }
        }
        arr = store_arr;
    }
    int hash_func(int k)
    {
        return k % size;
    }
    int hash_func_2(int k)
    {
        return (1 + k % (size - 2));
    }
    int call_probing(int k, int ind) // we will add probe into the home index and then we will check if there is data or not
    {
        if (c_method == 1)
        {
            return ind;
        }
        else if (c_method == 2) // prob with the step
        {
            return (ind * 3);
        }
        else if (c_method == 3)
        {
        }
        else if (c_method == 4) // double hashing
        {
            return (ind * hash_func_2(k));
        }
    }
    void linear_probing(int key, int val, node *n)
    {
        int index = hash_func(key);
        if (n[index].value == 0)
        {
            n[index].value = val;
            n[index].present = 1;
            n[index].key = key;
        }
        else
        {
            index = call_probing(key, index);
            int p = index;
            while (n[index].present != 0)
            {
                index = call_probing(key, p);
                p++;
            }
            n[index].key = key;
            n[index].value = val;
            n[index].present = 1;
        }
    }
    void probing_with_steps(int key, int val, node *n)
    {
        int index = hash_func(key);
        if (n[index].value == 0)
        {
            n[index].value = val;
            n[index].key = key;
            n[index].present = 1;
        }
        else
        {
            int j = 0;
            int v = 0;
            v = call_probing(key, v);
            while (n[(index + v) % size].present != 0)
            {
                v++;
                j++;
                v = call_probing(key, j);
            }
            n[(index + v) % size].value = val;
            n[(index + v) % size].key = key;
            n[(index + v) % size].present = 1;
        }
    }
    void double_hashing(int key, int val, node *n)
    {
        int index = hash_func(key);
        if (n[index].value == 0)
        {
            n[index].value = val;
            n[index].key = key;
            n[index].present = 1;
        }
        else
        {
            int time = 0;
            int h_2_save = hash_func_2(key);
            h_2_save = time * h_2_save;
            while (n[(index + h_2_save) % size].value != 0)
            {
                time++;
                h_2_save = hash_func_2(key);
                h_2_save = time * h_2_save;
            }
            n[(index + h_2_save) % size].value = val;
            n[(index + h_2_save) % size].key = key;
            n[(index + h_2_save) % size].present = 1;
        }
    }

    void insertion(int key, int val, node *n)
    {

        int h_index = hash_func(key);

        if (c_method == 1)
        {
            linear_probing(key, val, n);
        }
        else if (c_method == 2)
        {
            probing_with_steps(key, val, n);
        }
        else if (c_method == 4)
        {
            double_hashing(key, val, n);
        }
    }
    void insertion(int key, int val)
    {
        if (re_hash)
        {
            float save_lf = 0;
            save_lf = loading_factor();
            if (save_lf > 0.5)
            {
                call_rehashing();
            }
        }
        int h_index = hash_func(key);

        if (c_method == 1)
        {
            // LINEAR PROBING
            if (arr[h_index].value == 0)
            {
                arr[h_index].value = val;
                arr[h_index].key = key;
                arr[h_index].present = 1;
            }
            else
            {
                h_index = call_probing(key, h_index);
                int p = h_index;
                while (arr[h_index].present != 0)
                {
                    h_index = call_probing(key, p);
                    p++;
                }
                arr[h_index].value = val;
                arr[h_index].key = key;
                arr[h_index].present = 1;
            }
        }
        else if (c_method == 2) // probing with steps
        {
            if (arr[h_index].value == 0)
            {
                arr[h_index].value = val;
                arr[h_index].key = key;
                arr[h_index].present = 1;
            }
            else
            {
                int j = 0;
                int v = 0;
                v = call_probing(key, v);
                while (arr[(h_index + v) % size].present != 0)
                {
                    v++;
                    j++;
                    v = call_probing(key, j);
                }

                arr[(h_index + v) % size].value = val;
                arr[(h_index + v) % size].key = key;
                arr[(h_index + v) % size].present = 1;
            }
        }
        else if (c_method == 3)
        {
        }
        else if (c_method == 4) // double hashing
        {
            if (arr[h_index].value == 0)
            {
                arr[h_index].value = val;
                arr[h_index].key = key;
                arr[h_index].present = 1;
            }
            else
            {
                int time = 0;
                int h_2_save = hash_func_2(key);
                h_2_save = time * h_2_save;
                while (arr[(h_index + h_2_save) % size].present != 0)
                {
                    time++;
                    h_2_save = hash_func_2(key);
                    h_2_save = time * h_2_save;
                }
                arr[(h_index + h_2_save) % size].value = val;
                arr[(h_index + h_2_save) % size].key = key;
                arr[(h_index + h_2_save) % size].present = 1;
            }
        }
    }
    void update(int key, int new_val)
    {
        int h_i = hash_func(key);
        if (c_method == 1)
        {
            while (arr[h_i].key != key)
            {
                h_i++;
            }
            arr[h_i].value = new_val;
        }
        else if (c_method == 2)
        {
            int j = 0;
            int v = 0;
            while (arr[(h_i + v) % size].key != key)
            {
                v++;
                j++;
                v = call_probing(key, j);
            }
            arr[(h_i + v) % size].value = new_val;
        }
        else if (c_method == 3)
        {
        }
        else if (c_method == 4)
        {
            int time = 0;
            int h_2_save = hash_func_2(key);
            h_2_save = time * h_2_save;
            while (arr[(h_i + h_2_save) % size].key != key)
            {
                time++;
                h_2_save = hash_func_2(key);
                h_2_save = time * h_2_save;
            }
            arr[(h_i + h_2_save) % size].value = new_val;
        }
    }
    void deletion(int key)
    {
        int h_i = hash_func(key);
        if (c_method == 1)
        {
            while (arr[h_i].key != key)
            {
                h_i++;
            }
            arr[h_i].value = -1;
            arr[h_i].key = 0;
            arr[h_i].present = 0;
        }
        else if (c_method == 2)
        {
            int j = 0;
            int v = 0;
            while (arr[(h_i + v) % size].key != key)
            {
                v++;
                j++;
                v = call_probing(key, j);
            }
            arr[(h_i + v) % size].value = -1;
            arr[(h_i + v) % size].key = 0;
            arr[(h_i + v) % size].present = 0;
        }
        else if (c_method == 3)
        {
        }
        else if (c_method == 4)
        {
            int time = 0;
            int h_2_save = hash_func_2(key);
            h_2_save = time * h_2_save;
            while (arr[(h_i + h_2_save) % size].key != key)
            {
                time++;
                h_2_save = hash_func_2(key);
                h_2_save = time * h_2_save;
            }
            arr[(h_i + h_2_save) % size].value = -1;
            arr[(h_i + h_2_save) % size].key = 0;
            arr[(h_i + h_2_save) % size].present = 0;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].value << " ";
        }
    }
};
int main()
{
    

    HashTable h(1, 4);
    h.insertion(0, 10);
    h.insertion(100, 30);
    h.insertion(5, 20);
    h.insertion(15, 40);
    h.insertion(20, 88);
    cout << endl;
    cout << "after insertion" << endl;
    h.display();
    cout << endl;
    cout << "after deleting 20" << endl;
    h.deletion(20);
    h.display();
    cout << endl;
    cout << "after update" << endl;
    h.display();
    h.update(20, 1);
    h.display();
    cout << endl;
    h.display();
}