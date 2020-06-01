//
//  main.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "hashmap_openaddressing_quadraticprobing.hpp"

int main() {
    qhashmap<int, int> hm;
    hm.insert(5, 8);
    hm.insert(21, 8);
    hm.insert(50, 8);
    hm.insert(54, 8);
    hm.insert(251, 8);
    hm.insert(560, 8);
    hm.insert(575, 8);
    hm.insert(2132, 8);
    hm.insert(5078, 8);
    hm.insert(865, 8);
    hm.insert(643, 8);
    hm.insert(234, 86);
    hm.insert(789, 8);
    hm.insert(762, 8);
    hm.insert(509, 8);
    
    hm.remove(234);
    
    hm[234] = 98;
    
    std::cout << hm.contains(234) << std::endl;
}
