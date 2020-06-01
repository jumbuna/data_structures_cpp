//
//  dynamic_array.hpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef dynamic_array_hpp
#define dynamic_array_hpp

#include "exceptions.hpp"
#include <iostream>

template <class T>
struct dynamicarray {
    dynamicarray();
//    ~dynamicarray() {
//        delete []_array;
//    }
    T& operator[](int index);
    void clear();
    int indexof(T item);
    bool contains(T item);
    int size();
    int capacity();
    bool empty();
    void add(T item);
    void remove(T item);
    void removeat(int index);
private:
    T* _array;
    int _capacity, _length;
    void resize();
};

template <class T>
dynamicarray<T>::dynamicarray()
: _capacity(16), _length(0)
{
    _array = new T[_capacity];
}

template <class T>
void dynamicarray<T>::clear() {
    delete[] _array;
    _array = new T[16];
    _capacity = 16;
    _length = 0;
}

template <class T>
bool dynamicarray<T>::empty() {
    return _length == 0;
}

template <class T>
int dynamicarray<T>::size() {
    return _length;
}

template <class T>
int dynamicarray<T>::capacity() {
    return _capacity;
}

template <class T>
int dynamicarray<T>::indexof(T item) {
    for(int i = 0; i < _length; i++) {
        if(_array[i] == item) return i;
    }
    return -1;
}

template <class T>
bool dynamicarray<T>::contains(T item) {
    return indexof(item) != -1;
}

template <class T>
T& dynamicarray<T>::operator[](int index) {
    if(index >= _length) throw arrayexception("out of bound exception");
    return _array[index];
}

template <class T>
void dynamicarray<T>::add(T item) {
    //double size when _array is more than 3/4 full;
    if(!empty()) {
        if(_capacity/_length < 2) {
            _capacity *= 2;
            T* _narray = new T[_capacity];
            for(int i=0; i < _length; i++) {
                _narray[i] = _array[i];
            }
            delete [] _array;
            _array = _narray;
        }
    }
    _array[_length++] = item;
}

template <class T>
void dynamicarray<T>::removeat(int index) {
    if(empty()) throw arrayexception("array is empty");
    for(int i = index; i< _length; i++) {
        _array[i] = _array[i+1];
    }
    --_length;
    //decrease capacity by half when less than 1/4 of array is being utilized
    if(empty()) return;
    if(_capacity/_length > 4 && _capacity > 16) {
        resize();
    }
}

template <class T>
void dynamicarray<T>::remove(T item) {
    int index = indexof(item);
    if(index != -1) removeat(index);
}

template <class T>
void dynamicarray<T>::resize() {
    _capacity /= 2;
    T* _narray = new T[_capacity];
    for (int i=0; i < _length; i++) {
        _narray[i] = _array[i];
    }
    delete []  _array;
    _array = _narray;
}

#endif
