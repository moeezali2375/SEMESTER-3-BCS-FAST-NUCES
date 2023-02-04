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
class max_heap
{
    int *array;
    int current_size;
    int size;

public:
    //! HELPERS
    int parent(int i);
    int left(int i);
    int right(int i);
    bool empty();
    void heapify(int i);
    //! FUNCTIONS
    max_heap(int size);
    max_heap(max_heap &s);
    ~max_heap();
    void insert(int data);
    int search(int key);
    void delete_key(int key);
    int extract_max();
    int height();
    void print();
};