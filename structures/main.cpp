//
//  main.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "stack.hpp"

int main() {
    
    std::cout.setf(std::ios::boolalpha);
    stack<int> stack;
    stack.push(500);
    stack.push(500);
    stack.push(500);
    stack.push(500);
    stack.push(500);
    stack.push(500);
    stack.push(500);
    stack.push(500);
    
    stack.clear();
    
    std::cout << stack.empty() << std::endl;
}

