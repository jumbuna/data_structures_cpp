//
//  union_find.hpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef union_find_hpp
#define union_find_hpp

#include <iostream>

struct unionfind {
  
    unionfind(int size);
    void unify(int x, int y);
    int find(int x);
    bool connected(int x, int y);
    int components();
    bool full();
    void inspect();
    ~unionfind();
private:
    int _components, _size;
    int *_ids, *_sizes;
};

unionfind::unionfind(int size)
:_components(size), _size(size) {
    _ids = new int[_size];
    _sizes = new int[_size];
    
    for(int i=0; i < _size; i++) {
        _ids[i] = i;
        _sizes[i] = 1;
    }
}

unionfind::~unionfind() {
    delete [] _sizes;
    delete [] _ids;
}

bool unionfind::connected(int x, int y) {
    return find(x) == find(y);
}

void unionfind::unify(int x, int y) {
    int xroot = find(x), yroot = find(y);
    if (xroot == yroot) return;
    if(_sizes[xroot] > _sizes[yroot]) {
        _sizes[xroot] += _sizes[yroot];
        _ids[yroot] = xroot;
    }else{
        _sizes[yroot] += _sizes[xroot];
        _ids[xroot] = yroot;
    }
    --_components;
}

int unionfind::find(int x) {
    int root = x;
    while(root != _ids[root]) {
        root = _ids[_ids[root]];
        _ids[x] = root;
    }
    return root;
}

int unionfind::components() {
    return _components;
}

bool unionfind::full() {
    return connected(0, _size-1);
}

void unionfind::inspect() {
    for(int i = 0; i < _size; i++) {
        std::cout << _ids[i] << ", ";
    }
    std::cout << std::endl;
}
#endif
