//
//  hashmap_openaddressing_quadraticprobing.hpp
//  structures
//
//  Created by jumbuna on 01/06/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#pragma once

#include "hashmap_openaddressing_linearprobing.hpp"
template <class T, class U>
struct qhashmap: hashmap<T, U> {
    virtual int probefunction(int) override;
};

template <class T, class U>
int qhashmap<T,U>::probefunction(int _k) {
    return (_k*_k + _k)/2;
}
