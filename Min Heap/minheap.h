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
using namespace std;

class min_heap
{
    int *array;
    int size;
    int current_size;

public:
    //! HELPERS
    int parent(int i);
    int left(int i);
    int right(int i);
    bool empty();
    void heapify(int i);
    //! FUNCTIONS
    min_heap(int size);
    min_heap(min_heap &s);
    ~min_heap();
    void insert(int data);
    int search(int key);
    void delete_key(int key);
    int extract_min();
    int height();
    void print();
};