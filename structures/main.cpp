//
//  main.cpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "fenwick_tree.hpp"

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    fenwicktree fenwick(array, 30);
    std::cout << fenwick.sum(1, 30) << std::endl;
}
