#pragma once
#include <iostream>
using namespace std;

template <class T>
class ndArray
{
private:
    T *ptr;
    int totalDimensions;
    int *dimensions;
    int memoryLength;
    int *location;

public:
    ndArray()
    {
        ptr = nullptr;
        totalDimensions = 0;
        dimensions = nullptr;
        memoryLength = 0;
    }
    ndArray(int *dimensions, int totalDimensions)
    {
        this->dimensions = new int[totalDimensions];
        this->totalDimensions = totalDimensions;
        memoryLength = 1;
        for (int i = 0; i < totalDimensions; i++)
        {
            this->dimensions[i] = dimensions[i];
            memoryLength *= dimensions[i];
        }

        ptr = new T[memoryLength];
        for (int j = 0; j < memoryLength; j++)
            ptr[j] = 0;
    }
    ndArray<T>(const ndArray &obj)
    {
        totalDimensions = obj.totalDimensions;
        dimensions = new int[totalDimensions];
        for (int i = 0; i < totalDimensions; i++)
            dimensions[i] = obj.dimensions[i];

        memoryLength = obj.memoryLength;
        ptr = new T[memoryLength];
        for (int j = 0; j < memoryLength; j++)
            ptr[j] = obj.ptr[j];
    }

    void Insert(int value, int *location)
    {
        int index = 0;
        int x = 0;
        int temp = 1;
        for (; x < totalDimensions; x++)
        {
            temp = location[x];
            for (int i = x + 1; i < totalDimensions; i++)
            {
                temp *= dimensions[i];
            }
            index += temp;
        }
        ptr[index] = value;
    }

    void Delete(int value)
    {
        for (int i = 0; i < memoryLength; i++)
        {
            if (ptr[i] == value)
                ptr[i] = -1;
        }
    }

    void Shrink()
    {
        dimensions[0] /= 2;
        memoryLength = 1;
        for (int i = 0; i < totalDimensions; i++)
            memoryLength *= dimensions[i];

        T *temp = new T[memoryLength];
        for (int i = 0; i < memoryLength; i++)
            temp[i] = ptr[i];

        delete[] ptr;
        ptr = new T[memoryLength];
        for (int i = 0; i < memoryLength; i++)
            ptr[i] = temp[i];

        delete[] temp;
    }

    void Extend()
    {
        dimensions[0] *= 2;
        int old_memory = memoryLength;
        T *temp = new T[memoryLength];
        for (int i = 0; i < memoryLength; i++)
            temp[i] = ptr[i];
        memoryLength = 1;
        for (int i = 0; i < totalDimensions; i++)
            memoryLength *= dimensions[i];

        delete[] ptr;
        ptr = new T[memoryLength];
        for (int i = 0; i < old_memory; i++)
            ptr[i] = temp[i];

        delete[] temp;
    }

    T &operator()(int *location)
    {
        int index = 0;
        int x = 0;
        int temp = 1;
        for (; x < totalDimensions; x++)
        {
            temp = location[x];
            for (int i = x + 1; i < totalDimensions; i++)
            {
                temp *= dimensions[i];
            }
            index += temp;
        }
        return ptr[index];
    }

    T &operator[](int i)
    {
        if (totalDimensions == 1)
        {
            return ptr[i];
        }
    }

    T &operator()(int i, int j)
    {
        if (totalDimensions == 2)
        {
            int index = 0;
            int x = 0;
            int temp = 1;
            for (; x < totalDimensions; x++)
            {
                temp = location[x];
                for (int i = x + 1; i < totalDimensions; i++)
                {
                    temp *= dimensions[i];
                }
                index += temp;
            }
            return ptr[index];
        }
    }

    T &operator()(int i, int j, int k)
    {
        if (totalDimensions == 3)
        {
            int index = 0;
            int x = 0;
            int temp = 1;
            for (; x < totalDimensions; x++)
            {
                temp = location[x];
                for (int i = x + 1; i < totalDimensions; i++)
                {
                    temp *= dimensions[i];
                }
                index += temp;
            }
            return ptr[index];
        }
    }

    friend ostream &operator<<(ostream &out, const ndArray<T> arr)
    {
        int ind = 0;
        if (arr.totalDimensions == 2)
        {
            for (int i = 0; i < arr.dimensions[0]; i++)
            {
                for (int j = 0; j < arr.dimensions[1]; j++)
                {
                    if (arr.ptr[ind] != 6574)
                        out << arr.ptr[ind] << "  ";
                    else
                        out << "0 ";
                    ind++;
                }
                out << endl;
            }
        }
        else if (arr.totalDimensions == 3)
        {
            for (int k = 0; k < arr.dimensions[0]; k++)
            {
                for (int i = 0; i < arr.dimensions[1]; i++)
                {
                    for (int j = 0; j < arr.dimensions[2]; j++)
                    {
                        if (arr.ptr[ind] != 6574)
                            out << arr.ptr[ind] << "  ";
                        else
                            out << "0 ";
                        ind++;
                    }
                    out << endl;
                }
                out << endl
                    << endl;
            }
        }
        else
        {
            for (int i = 0; i < arr.memoryLength; i++)
            {
                if (arr.ptr[i] != 6574)
                    out << arr.ptr[i] << " ";
                else
                    out << "0 ";
            }
        }

        return out;
    }

    ~ndArray()
    {
        if (totalDimensions > 0)
        {
            delete[] dimensions;
            totalDimensions = 0;
        }
        if (memoryLength > 0)
        {
            delete[] ptr;
            memoryLength = 0;
        }
    }
};