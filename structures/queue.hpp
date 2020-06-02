//
//  queue.hpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include "double_linked_list.hpp"

template <class T>
struct queue {
    void push(T item);
    T pop();
    T peek();
    int size();
    bool empty();
    bool contains(T item);
    void clear();
private:
    doublelinkedlist<T> _list;
};

template <class T>
void queue<T>::push(T item) {
    _list.addback(item);
}

template <class T>
T queue<T>::pop() {
    return _list.removefront();
}

template <class T>
T queue<T>::peek() {
    return _list[0];
}

template <class T>
bool queue<T>::empty() {
    return  _list.empty();
}

template <class T>
bool queue<T>::contains(T item) {
    return  _list.contains(item);
}

template <class T>
void queue<T>::clear() {
    _list.clear();
}

template <class T>
int queue<T>::size() {
    return _list.size();
}

#endif
