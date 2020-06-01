//
//  main.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "hashmap_seperatechaining.hpp"

int main() {
    hashmap<int, int> intmap;
    intmap.insert(30, 500);
    intmap[40] = 800;
    intmap.insert({900, 500});
    
    intmap.remove(30);
    
    std::cout << intmap[40] << std::endl;
    std::cout << intmap.contains(30) << std::endl;
}


