//
//  priority_queue.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef priority_queue_hpp
#define priority_queue_hpp

#include "binary_heap.hpp"

template <class T>
struct priorityqueue {
    void enqueue(T item);
    T dequeue();
    T peek();
    int size();
    bool empty();
    void clear();
    bool contains(T item);
private:
    binaryheap<T> _heap;
};

template <class T>
void priorityqueue<T>::enqueue(T item) {
    _heap.add(item);
}

template <class T>
T priorityqueue<T>::dequeue() {
    return _heap.pop();
}

template <class T>
T priorityqueue<T>::peek() {
    return _heap.peek();
}

template <class T>
int priorityqueue<T>::size() {
    return _heap.size();
}

template <class T>
bool priorityqueue<T>::empty() {
    return _heap.empty();
}

template <class T>
void priorityqueue<T>::clear() {
    _heap.clear();
}

template <class T>
bool priorityqueue<T>::contains(T item) {
    return _heap.contains(item);
}

#endif
