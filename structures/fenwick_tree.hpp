//
//  fenwick_tree.cpp
//  structures
//
//  Created by jumbuna on 02/06/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>

struct fenwicktree {
    fenwicktree(int*, int);
    ~fenwicktree();
    int leastsignificantbit(int&);
    int sum(int, int);
    void update(int, int);
    void reset();
private:
    int* _array;
    int* _oldarray;
    int _size;
    int _sum(int);
};

fenwicktree::fenwicktree(int* arr, int size)
:_size(size+1)
{
    _oldarray = arr;
    _array = new int[_size];
    for(int i = 0; i <= _size; i++)
        _array[i] = arr[i-1];
    for(int i = 1; i <= _size; i++) {
        int parent = i + leastsignificantbit(i);
        if(parent < _size) {
            _array[parent] += _array[i];
        }
    }
}

fenwicktree::~fenwicktree() {
    delete [] _array;
}

void fenwicktree::reset() {
    for(int i = 1; i < _size; i++) {
        _array[i] = 0;
    }
}

int fenwicktree::leastsignificantbit(int& _i) {
    return (_i & (_i*-1));
}

int fenwicktree::sum(int _start, int _stop) {
    
    return _sum(_stop) - _sum(--_start);
}

int fenwicktree::_sum(int _index) {
    int sum = 0;
    sum += _array[_index];
    while(_index > 0) {
        _index -= leastsignificantbit(_index);
        sum += _array[_index];
    }
    return sum;
}

void fenwicktree::update(int _index, int _value) {
    int incremental = _value - _oldarray[_index-1];
    _array[_index]+= incremental;
    while(_index < _size) {
        _index += leastsignificantbit(_index);
        _array[_index] += incremental;
    }
}
