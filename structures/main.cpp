////
////  main.cpp
////  structures
////
////  Created by jumbuna on 28/05/2020.
////  Copyright © 2020 jumbuna. All rights reserved.
////
//
//#include <iostream>
//#include "binary_search_tree.hpp"
//
//int main() {
//    
//    binarysearchtree<int> bt;
//    bt.add(30);
//    bt.add(400);
//    bt.add(800);
//    bt.add(2);
//    bt.add(3);
//    bt.add(9);
//    bt.add(23);
//    bt.add(47);
//    bt.add(81);
//    bt.add(99);
//    bt.add(66);
//    bt.add(21);
//    bt.add(17);
//    bt.add(29);
//    bt.add(46);
//    bt.add(10);
//    bt.add(90);
//    
//    std::cout << "size: " << bt.size() << std::endl;
//    std::cout << "contains 2: " << bt.contains(2) << std::endl;
//    std::cout << "contains 17: " << bt.contains(17) << std::endl;
//    bt.remove(17);
//    std::cout << "contains 17: " << bt.contains(17) << std::endl;
//    dynamicarray<int> da[4];
//    
//    da[0] = bt.preordertraversal();
//    da[1] = bt.inordertraversal();
//    da[2] = bt.postordertraversal();
//    da[3] = bt.levelordertraversal();
//    
//    for(int i = 0; i<4; i++) {
//        auto arr = da[i];
//        switch (i) {
//            case 0:
//                std::cout << "pre-order: ";
//                break;
//            case 1:
//                std::cout << "in-order: ";
//                break;
//            case 2:
//                std::cout << "post-order: ";
//                break;
//            default:
//                std::cout << "level-order: ";
//                break;
//        }
//        
//        for(int x = 0; x<arr.size(); x++) {
//            std::cout << arr[x] << ", ";
//        }
//        
//        std::cout << std::endl;
//    }
//}
//
