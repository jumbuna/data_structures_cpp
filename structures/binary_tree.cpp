//
//  binary_tree.cpp
//  structures
//
//  Created by jumbuna on 29/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#include <iostream>
#include "dynamic_array.hpp"

template <class T>
struct binarysearchtree {
    void add(T);
    void remove(T);
    bool contains(T);
    void clear();
    dynamicarray<T> preordertraversal();
    dynamicarray<T> inordertraversal();
    dynamicarray<T> postordertraversal();
private:
    struct node {
        node(T _data)
        : data(_data)
        {
            parent = left = right = nullptr;
        }
        T leftdata() {
            if(left == nullptr)
                throw 2;
            else
                return left->data;
        }
        T rightdata() {
            if(right == nullptr)
                throw 2;
            else
                return right->data;
        }
        T data;
        node *parent, *left, *right;
    };
    int count = 0;
    node* root = nullptr;
    void* digright(node*);
    void* digleft(node*);
    void __preordertraversal(node* , dynamicarray<T>*&);
    void __inordertraversal(node* , dynamicarray<T>*&);
    void __post_ordertraversal(node* , dynamicarray<T>*&);
    void __level_ordertraversal(node* , dynamicarray<T>*&);
};

template<class T>
void binarysearchtree<T>::add(T item) {
    if(contains(item)) return;
    ++count;
    node* _node = new node(item);
    if(!root) {
        root = _node;
        return;
    }
    node* _temp = root;
    while(_temp != nullptr) {
        if(_temp->data > item)
            if(_temp->left == nullptr)
                break;
            else
                _temp = _temp->left;
        else
            if(_temp->right == nullptr)
                break;
            else
            _temp = _temp->right;
    }
    _node->parent = _temp;
    
    if(_temp->data > item)
        _temp->left = _node;
    else
        _temp->right = _node;
}

template<class T>
bool binarysearchtree<T>::contains(T item) {
    if(root == nullptr) return false;
    node* _temp = root;
    
    while(_temp != nullptr) {
        if(_temp->data == item)
            return true;
        else
            if(_temp->data > item)
                _temp = _temp->left;
            else
                _temp = _temp->right;
    }
    return false;
}

template <class T>
void binarysearchtree<T>::remove(T item) {
    if(!contains(item)) return;
    --count;
    node* _temp = root;
    while (_temp != nullptr) {
        if(_temp->data == item)
            break;
        else
            if(_temp->data > item)
                _temp = _temp->left;
            else
                _temp = _temp->right;
    }
    node* _parent = _temp->parent;
//    if(_temp->data > _parent->data)
//        _parent->right = nullptr;
//    else
//        _parent->left = nullptr;
    
    if(_temp->left == nullptr && _temp->right == nullptr) {
        delete _temp;
        return;
    }
    if(_temp->left != nullptr ^ _temp->right != nullptr) {
        if(_temp->left != nullptr) {
            if(_temp->data > _parent->data)
                _parent->right = _temp->left;
            else
                _parent->left = _temp->right;
        }else {
            if(_temp->data > _parent->data)
                _parent->right = _temp->right;
            else
                _parent->left = _temp->right;
        }
        delete _temp;
        return;
    }
    else {
        node* _swap = (node*) digleft(_temp->right);
        node* _swapparent = _swap->parent;
        _swapparent->left = nullptr;
        _temp->data = _swap->data;
        delete _swap;
    }
    
}

template <class T>
void* binarysearchtree<T>::digleft(node *_root) {
    node* _temp = _root;
    while (_temp->left != nullptr) {
        _temp = _temp->left;
    }
    return _temp;
}

template <class T>
void binarysearchtree<T>::__preordertraversal(node* _root, dynamicarray<T>*& array) {
    if(_root == nullptr) return;
//    if(!array->contains(_root->data))
//        array->add(_root->data);
//    if(_root->left != nullptr)
//        array->add(_root->leftdata());
//    if(_root->right != nullptr)
//        array->add(_root->rightdata());
    array->add(_root->data);
    __ordertraversal(_root->left, array);
    __ordertraversal(_root->right, array);
}

template <class T>
void binarysearchtree<T>::__inordertraversal(node* _root, dynamicarray<T>*& array) {
    if(_root == nullptr) return;
    __inordertraversal(_root->left, array);
    array->add(_root->data);
    __inordertraversal(_root->right, array);
}

template <class T>
void binarysearchtree<T>::__post_ordertraversal(node* _root, dynamicarray<T>*& array) {
    if(_root == nullptr) return;
    __post_ordertraversal(_root->left, array);
    __post_ordertraversal(_root->right, array);
    array->add(_root->data);
}

template <class T>
dynamicarray<T> binarysearchtree<T>::preordertraversal() {
    dynamicarray<T>* ba = new dynamicarray<T>;
    __ordertraversal(root, ba);
    dynamicarray<T> _return = *ba;
    return _return;
}

template <class T>
dynamicarray<T> binarysearchtree<T>::inordertraversal() {
    dynamicarray<T>* ba = new dynamicarray<T>;
    __inordertraversal(root, ba);
    dynamicarray<T> _return = *ba;
    ba = nullptr;
    return _return;
}

template <class T>
dynamicarray<T> binarysearchtree<T>::postordertraversal() {
    dynamicarray<T>* ba = new dynamicarray<T>;
    __post_ordertraversal(root, ba);
    dynamicarray<T> _return = *ba;
    ba = nullptr;
    return _return;
}

int main() {
    binarysearchtree<int> bt;
    bt.add(10);
    bt.add(5);
    bt.add(9);
    bt.add(1);
    bt.add(11);
    bt.add(14);
    
    bt.remove(14);
    bt.remove(5);
    bt.remove(11);
    
//    std::cout << bt.contains(3) <<std::endl;
//    std::cout << bt.contains(9) <<std::endl;
//    std::cout << bt.contains(11) <<std::endl;
//    std::cout << bt.contains(5) <<std::endl;
//    std::cout << bt.contains(10) <<std::endl;
    auto da = bt.inordertraversal();
    for(int i = 0; i <da.size(); i++) {
        std::cout << da[i] << ", ";
    }
    
    std::cout << std::endl;
}
