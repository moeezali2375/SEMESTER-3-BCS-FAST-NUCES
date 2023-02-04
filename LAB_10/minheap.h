//=================================================
//
//              ##   ##  #####    ###    #####
//              ##   ##  ##      ## ##   ##  ##
//              #######  #####  ##   ##  #####
//              ##   ##  ##     #######  ##
//              ##   ##  #####  ##   ##  ##
//
//=================================================

#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class min_heap
{
    vector<T> array;
    int size;
    int current_size;

public:
    //! HELPERS
    int parent(int i);
    int left(int i);
    int right(int i);
    bool empty();
    void heapify_down(int i);
    void heapify_up(int i);
    //! FUNCTIONS
    min_heap(int size);
    min_heap(T *array, int size);
    ~min_heap();
    void insert(T data);
    int search(T key);
    int search(int i, T key);
    T get_min();
    void delete_key(int key);
    T extract_min();
    int height();
    void print();
};