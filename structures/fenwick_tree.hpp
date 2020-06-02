//
//  fenwick_tree.hpp
//  structures
//
//  Created by jumbuna on 02/06/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#pragma once

template <class T>
struct fenwicktree {
    fenwicktree(T*, int);
    ~fenwicktree();
    int leastsignificantbit(int&);
    T sum(int, int);
    void update(int, T);
    void reset();
private:
    T* _array;
    T* _oldarray;
    int _size;
    T _sum(int);
};

template <class T>
fenwicktree<T>::fenwicktree(T* arr, int size)
:_size(size+1)
{
    _oldarray = arr;
    _array = new T[_size]; //use std::calloc which initializes all element to 0
    for(int i = 0; i <= _size; i++)
        _array[i] = arr[i-1];
    for(int i = 1; i <= _size; i++) {
        int parent = i + leastsignificantbit(i);
        if(parent < _size)
            _array[parent] += _array[i];
    }
}
template <class T>
fenwicktree<T>::~fenwicktree() {
    delete [] _array;
}

template <class T>
void fenwicktree<T>::reset() {
    for(int i = 1; i < _size; i++) {
        _array[i] = 0;
    }
}

template <class T>
int fenwicktree<T>::leastsignificantbit(int& _i) {
    return (_i & (_i*-1));
}

template <class T>
T fenwicktree<T>::sum(int _start, int _stop) {
    
    return _sum(_stop) - _sum(--_start);
}

template <class T>
T fenwicktree<T>::_sum(int _index) {
    T sum = 0;
    sum += _array[_index];
    while(_index > 0) {
        _index -= leastsignificantbit(_index);
        sum += _array[_index];
    }
    return sum;
}

template <class T>
void fenwicktree<T>::update(int _index, T _value) {
    T incremental = _value - _oldarray[_index-1];
    _array[_index]+= incremental;
    while(_index < _size) {
        _index += leastsignificantbit(_index);
        _array[_index] += incremental;
    }
}
