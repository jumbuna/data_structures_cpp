//
//  stack.hpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include "double_linked_list.hpp"

template <class T>
struct stack {
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
void stack<T>::push(T item) {
    _list.addfront(item);
}

template <class T>
T stack<T>::pop() {
    return _list.removefront();
}

template <class T>
T stack<T>::peek() {
    return _list[0];
}

template <class T>
bool stack<T>::empty() {
    return  _list.empty();
}

template <class T>
bool stack<T>::contains(T item) {
    return  _list.contains(item);
}

template <class T>
void stack<T>::clear() {
    _list.clear();
}

template <class T>
int stack<T>::size() {
    return _list.size();
}

#endif
