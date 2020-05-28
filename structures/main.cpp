//
//  main.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "queue.hpp"

int main() {
    
    std::cout.setf(std::ios::boolalpha);

    queue<int> stck;
    stck.push(10);
    stck.push(100);
    stck.push(500);
    stck.push(90);
    
    while(!stck.empty()) {
        std::cout << stck.peek() << std::endl;
        stck.pop();
    }
    
    std::cout << stck.size() << std::endl;
    
}

