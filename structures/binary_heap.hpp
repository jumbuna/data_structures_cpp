//
//  binary_heap.hpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef binary_heap_hpp
#define binary_heap_hpp

#include "dynamic_array.hpp"

template <class T>
struct binaryheap {
    void add(T item);
    T pop();
    T peek();
    int size();
    void swim(int index);
    void sink(int index);
    bool empty();
    void clear();
    bool contains(T item);
private:
    dynamicarray<T> _array;
    int _leaf = 0;
};

template <class T>
void binaryheap<T>::add(T item) {
    _array.add(item);
    swim(_leaf++);
}

template <class T>
T binaryheap<T>::peek() {
    return _array[0];
}

template <class T>
T binaryheap<T>::pop() {
    --_leaf;
    T root = _array[0], leaf = _array[_leaf];
    _array[_leaf] = root;
    _array[0] = leaf;
    _array.removeat(_leaf);
    sink(0);
    return root;
}

template <class T>
int binaryheap<T>::size() {
    return _array.size();
}

template <class T>
bool binaryheap<T>::empty() {
    return _array.empty();
}

template <class T>
bool binaryheap<T>::contains(T item) {
    return _array.contains(item);
}

template <class T>
void binaryheap<T>::swim(int index) {
    if(index == 0) return;
    try {
        int parentindex;
        //check for parent by determining side
        if(index%2 == 0) parentindex = ((index-2)/2);
        else parentindex = ((index-1)/2);
        
        T child = _array[index], parent = _array[parentindex];
//        std::cout << child << "------" << parent << std::endl;
        if(parent  > child) {
            _array[index] = parent;
            _array[parentindex] = child;
            swim(parentindex);
        }
    }catch(arrayexception e) {
        return;
    }
}

template <class T>
void binaryheap<T>::sink(int index) {
    if(index >= _leaf) return;
    try {
        int leftchild = 2*index+1, rightchild = 2*index+2, pick;
        T lv = _array[leftchild], rv = _array[rightchild];
        if(lv > rv) pick = rightchild;
        else if (lv < rv) pick = leftchild;
        else pick = leftchild;
        T parent = _array[index], child = _array[pick];
        if(parent > child) {
            _array[index] = child;
            _array[pick] = parent;
            
            sink(pick);
        }
        
    } catch (...) {
        return;
    }
}

template <class T>
void binaryheap<T>::clear() {
    _array.clear();
    _leaf = 0;
}

#endif
