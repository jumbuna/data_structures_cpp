//
//  double_linked_list.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef double_linked_list_hpp
#define double_linked_list_hpp

#include "exceptions.hpp"

//template <class T>


template <class T>
struct doublelinkedlist {
    void addfront(T item);
    void addback(T item);
    T removefront();
    T removeback();
    bool empty();
    void removeat(int index);
    int size();
    T get(int index);
    bool contains(T item);
    T operator[](int index);
    int indexof(T item);
    void clear();
private:
    struct node {
        node(T item);
        T _data;
        node* _next, *_previous;
    };
    node *_head = nullptr, *_tail = nullptr;
    int _size = 0;
};

template <class T>
doublelinkedlist<T>::node::node(T item)
:_data(item)
{}

template <class T>
void doublelinkedlist<T>::addfront(T item) {
    node* _newnode = new node(item);
    if(_size == 0) {
        _head = _tail = _newnode;
    }else{
        _newnode->_next = _head;
        _head->_previous = _newnode;
        _head = _newnode;
    }
    ++_size;
}

template <class T>
void doublelinkedlist<T>::addback(T item) {
    node* _newnode = new node(item);
    if(_size == 0) {
        _head = _tail = _newnode;
    }else{
        _tail->_next = _newnode;
        _newnode->_previous = _tail;
        _tail = _newnode;
    }
    ++_size;
}

template <class T>
T doublelinkedlist<T>::removeback() {
    if(_size == 0) throw arrayexception("list is empty");
    node* _nodeptr = _tail;
    if(_head != _tail) {
        _tail = _tail->_previous;
        _tail->_next = nullptr;
    }
    node _return = *_nodeptr;
    delete _nodeptr;
    --_size;
    return _return._data;
}

template <class T>
T doublelinkedlist<T>::removefront() {
    if(_size == 0) throw arrayexception("list is empty");
    node* _nodeptr = _head;
    if(_head != _tail) {
        _head = _head->_next;
        _head->_previous = nullptr;
    }
    node _return = *_nodeptr;
    delete _nodeptr;
    --_size;
    return _return._data;
}

template <class T>
bool doublelinkedlist<T>::empty() {
    return _size == 0;
}

template <class T>
int doublelinkedlist<T>::size() {
    return _size;
}

template <class T>
T doublelinkedlist<T>::get(int index) {
    if(index >= _size) throw arrayexception("out of bounds exception");
    node* _return = _head;
    for (int i=0; i < index; i++) {
        _return = _return->_next;
    }
    return _return->_data;
}

template <class T>
T doublelinkedlist<T>::operator[](int index) {
    return get(index);
}

template <class T>
int doublelinkedlist<T>::indexof(T item) {
    node* _node = _head;
    for (int i=0; i < _size; i++) {
        if(_node->_data == item) return i;
        else _node = _node->_next;
    }
    return -1;
}

template <class T>
bool doublelinkedlist<T>::contains(T item) {
    return indexof(item) != -1;
}

template <class T>
void doublelinkedlist<T>::removeat(int index) {
    if(index == 0) removefront();
    else if (index == _size-1) removeback();
    else {
        node* _node = _head;
        for(int i = 0; i < index; i++) {
            _node = _node->_next;
        }
        _node->_previous->_next = _node->_next;
        _node->_next->_previous = _node->_previous;
        delete _node;
    }
    --_size;
}

template <class T>
void doublelinkedlist<T>::clear() {
    while(_head != nullptr) {
        node _node = *_head;
        delete _head;
        _head = _node._next;
    }
    //_tail = nullptr;
    _size = 0;
}


#endif
