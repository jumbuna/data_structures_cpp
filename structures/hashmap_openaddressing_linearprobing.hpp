//
//  hashmap_openaddressing_linearprobing.hpp
//  structures
//
//  Created by jumbuna on 01/06/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#pragma once

#include <utility>

template <class T, class U>
struct hashmap {
    hashmap();
    ~hashmap();
    int hashfunction(T);
    virtual int probefunction(int);
    void insert(T , U);
    void insert(std::pair<T, U>);
    void remove(T);
    U& operator[](T);
    bool empty();
    int size();
    bool contains(T);
private:
    T** _keyarray;
    U** _valuearray;
    int _size;
    const double _loadfactor = 0.667;
    int _threshold, _capacity;
    void resize();
    std::hash<T> hash_obj{};
};

template<class T, class U>
hashmap<T, U>::hashmap()
:_capacity(16)
{
    _threshold = _capacity*_loadfactor;
    _keyarray = new T*[_capacity];
    _valuearray = new U*[_capacity];
    
    for(int i = 0; i <_capacity; i++) {
        _keyarray[i] = nullptr;
        _valuearray[i] = nullptr;
    }
}

template<class T, class U>
void hashmap<T, U>::insert(T _key, U _value) {
    if(contains(_key)) {
        operator[](_key) = _value;
        return;
    }
    int hash = hashfunction(_key);
    for(int i=0; _keyarray[hash] != nullptr; i++) {
        if(_keyarray[hash] == NULL)
            break;
        hash += probefunction(i);
        hash %= _capacity;
    }
    
    T* _kp = new T(_key);
    U* _vp = new U(_value);
    _keyarray[hash] = _kp;
    _valuearray[hash] = _vp;
    ++_size;
    if(_size >= _threshold)
        resize();
}

template <class T, class U>
void hashmap<T, U>::insert(std::pair<T, U> _keypair) {
    insert(_keypair.first, _keypair.second);
}

template <class T, class U>
int hashmap<T,U>::hashfunction(T _key) {
    return hash_obj(_key) % _capacity;
}

template <class T, class U>
int hashmap<T,U>::probefunction(int _k) {
    return _k;
}

template <class T, class U>
bool hashmap<T,U>::contains(T _key) {
    int hash = hashfunction(_key);
    for(int i =0; _keyarray[hash] != nullptr; i++) {
        if(*(_keyarray[hash]) == _key)
            return true;
        else {
            hash += probefunction(i);
            hash %= _capacity;
        }
    }
    return false;
}

template <class T, class U>
bool hashmap<T,U>::empty() {
    return _size == 0;
}

template <class T, class U>
int hashmap<T,U>::size() {
    return _size;
}

template <class T, class U>
void hashmap<T,U>::remove(T _key) {
    if(!contains(_key))
        return;
    int hash = hashfunction(_key);
    for(int i = 0; _keyarray[hash] != nullptr; i++) {
        if(*(_keyarray[hash]) == _key)
            break;
        hash += probefunction(i);
        hash %= _capacity;
    }
    _keyarray[hash] = NULL;
    --_size;
}

template <class T, class U>
U& hashmap<T,U>::operator[](T _key) {
    int hash = hashfunction(_key);
    for(int i = 0; _keyarray[hash] != nullptr; i++) {
        if(*(_keyarray[hash]) == _key)
            return *(_valuearray[hash]);
        hash += probefunction(i);
        hash %= _capacity;
    }
    T* _kp = new T(_key);
    U* _vp = new U;
    _keyarray[hash] = _kp;
    _valuearray[hash] = _vp;
    ++_size;
    if(_size >= _threshold)
        resize();
    return *_vp;
}

template <class T, class U>
void hashmap<T,U>::resize() {
    _capacity *= 2;
    _threshold = _capacity*_loadfactor;
    
    T** _newkeyarr = new T*[_capacity];
    U** _newvalarr = new U*[_capacity];
    
    for(int i = 0; i <_capacity; i++) {
        _newkeyarr[i] = nullptr;
        _newvalarr[i] = nullptr;
    }
    
    for(int i = 0; i < (_capacity/2) ; i++) {
        if(_keyarray[i] == nullptr || _keyarray[i] == NULL)
            continue;
        T* key = _keyarray[i];
        int hash = hashfunction(*key);
        for(int j=0; _newkeyarr[hash] != nullptr; j++) {
            hash += probefunction(j);
            hash %= _capacity;
        }
        _newkeyarr[hash] = key;
        _newvalarr[hash] = _valuearray[i];
    }
    delete[] _valuearray;
    delete[] _keyarray;
    _valuearray = _newvalarr;
    _keyarray = _newkeyarr;
}

template <class T, class U>
hashmap<T, U>::~hashmap() {
    for(int i = 0; i < _capacity; i++) {
        if(_keyarray[i] != nullptr || _keyarray[i] != NULL) {
            delete _keyarray[i];
            delete _valuearray[i];
        }
    }
    delete [] _keyarray;
    delete [] _valuearray;
}
