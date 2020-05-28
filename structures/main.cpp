//
//  main.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "union_find.hpp"

int main() {
    
    std::cout.setf(std::ios::boolalpha);
    
    unionfind uf(10);
    
    uf.unify(2, 3);
    uf.unify(3, 9);
    uf.unify(4, 8);
    uf.unify(2, 8);
    uf.unify(1, 6);
    uf.unify(7, 5);
    uf.unify(6, 5);
    uf.unify(0, 4);
    uf.unify(7, 2);
    
    uf.inspect();
}

