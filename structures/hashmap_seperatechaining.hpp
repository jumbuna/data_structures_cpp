//
//  hashmap_seperatechaining.hpp
//  structures
//
//  Created by jumbuna on 01/06/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#pragma once

#include "double_linked_list.hpp"

template <class T, class U>
struct hashmap {
    hashmap();
    ~hashmap();
    void insert(T, U);
    void insert(std::pair<T, U>);
    void remove(T);
    U& operator[](T);
    bool contains(T);
    int size();
    bool empty();
private:
    struct node {
        node(T key, U* value)
        :_key(key), _value(value)
        {}
        T _key;
        U* _value;
        bool operator==(const node& other) {
            return this->_key == other._key;
        }
        bool operator==(T key) {
            return this->_key == key;
        }
    };
    int hashfunction(T);
    void resize();
    std::hash<T> hash_obj{};
    const double _loadfactor = 0.66;
    void __insert(int, node* );
    int _capacity = 16, _threshold = (_capacity*_loadfactor), _size = 0;
    doublelinkedlist<node*>** _array;
};

template <class T, class U>
hashmap<T, U>::hashmap()
{
    _array = new doublelinkedlist<node*>*[_capacity];
    for(int i= 0; i < _capacity; i++) {
        _array[i] = nullptr;
    }
}

template <class T, class U>
int hashmap<T, U>::hashfunction(T _key) {
    return hash_obj(_key) % _capacity;
}

template <class T, class U>
void hashmap<T,U>::insert(T _key, U _value) {
    if(contains(_key)) {
        this->operator[](_key) = _value;
    }
    U* _nu = new U(_value);
    node* _newnode = new node(_key, _nu);
    int hash = hashfunction(_key);
    if(_array[hash] == nullptr) {
        auto _dll = new doublelinkedlist<node*>;
        _dll->addfront(_newnode);
        _array[hash] = _dll;
    }else {
        doublelinkedlist<node*>* _dll = _array[hash];
        _dll->addback(_newnode);
    }
    ++_size;
    
    if(_size >= _threshold)
        resize();
}

template <class T, class U>
void hashmap<T,U>::insert(std::pair<T, U> _pair) {
    insert(_pair.first, _pair.second);
}

template <class T, class U>
bool hashmap<T,U>::contains(T _key) {
    size_t hash = hashfunction(_key);
    if(_array[hash] == nullptr)
        return false;
    auto _dll = _array[hash];
    for(int i = 0; i < _dll->size(); i++) {
        auto _node = _dll->get(i);
        if(*_node == _key)
            return true;
    }
    return false;
}

template <class T, class U>
int hashmap<T,U>::size() {
    return _size;
}

template <class T, class U>
void hashmap<T,U>::remove(T _key) {
    size_t hash = hashfunction(_key);
    if(_array[hash] == nullptr)
        return;
    else {
        auto _dll = _array[hash];
        for(int i=0; i < _dll->size(); i++) {
            node* _node = _dll->get(i);
            if(*_node == _key) {
                _dll->removeat(i);
                delete _node->_value;
                delete _node;
                --_size;
            }
        }
    }
}

template<class T, class U>
U& hashmap<T,U>::operator[](T _key) {
    size_t hash = hashfunction(_key);
    auto _dll = _array[hash];
    if(_dll != nullptr) {
        for(int i=0; i < _dll->size(); i++) {
            node* _node = _dll->get(i);
            if(*_node == _key) {
                return *(_node->_value);
            }
        }
    }
    U* pntr = new U;
    node* _newnode = new node(_key, pntr);
    __insert((int)hash, _newnode);
    return *(_newnode->_value);
}

template<class T, class U>
void hashmap<T,U>::__insert(int hash, node* _newnode) {
    if(_array[hash] == nullptr) {
        auto _dll = new doublelinkedlist<node*>;
        _dll->addfront(_newnode);
        _array[hash] = _dll;
    }else {
        doublelinkedlist<node*>* _dll = _array[hash];
        _dll->addback(_newnode);
    }
    ++_size;
    if(_size >= _threshold)
    resize();
}

template <class T, class U>
bool hashmap<T,U>::empty() {
    return _size == 0;
}

template <class T, class U>
void hashmap<T,U>::resize() {
    _capacity = _capacity*2;
    _threshold = _capacity*_loadfactor;
    
    auto _newdllpntarr = new doublelinkedlist<node*>*[_capacity];
    for(int i= 0; i < _capacity; i++) {
        _newdllpntarr[i] = nullptr;
    }
    
    for(int i = 0; i<(_capacity/2); i++)  {
        auto _olddll = _array[i];
        if(_olddll != nullptr) {
            for(int j=0; j < _olddll->size(); j++) {
                node* _node = _olddll->get(j);
                int hash = hashfunction(_node->_key);
                if(_newdllpntarr[hash] == nullptr) {
                    auto _dll = new doublelinkedlist<node*>;
                    _dll->addfront(_node);
                    _newdllpntarr[hash] = _dll;
                }
                else {
                    auto _dll = _newdllpntarr[hash];
                    _dll->addback(_node);
                }
            }
        }
    }
    
    delete[] _array;
    _array = _newdllpntarr;
}

template <class T, class U>
hashmap<T, U>::~hashmap() {
    for(int i=0; i < _size; i++) {
        auto _dll = _array[i];
        if(!_dll) continue;
        for(int j=0; j < _dll->size(); j++) {
            node* _node = _dll->get(j);
            delete _node->_value;
            delete _node;
        }
        delete _dll;
    }
    delete[] _array;
}
