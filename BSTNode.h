#pragma once
#include <iostream>
#include "Pair.h"

template <class T>
class BSTNode {
private:
    T item;//Now stores Pair<K, V>
    BSTNode<T>* left;
    BSTNode<T>* right;

public:
    BSTNode();//Default constructor
    BSTNode(const T& item);//Constructor

    void setItem(const T& item);// Set item
    T& getItem();//Get item
    void setLeft(BSTNode<T>* left);//Set left child
    void setRight(BSTNode<T>* right);//Set right child
    BSTNode<T>* getLeft();//Get left child
    BSTNode<T>* getRight();//Get right child

    void add(const T& item);//Add item recursively
    int count();//Count nodes in the subtree
};

template <class T>
BSTNode<T>::BSTNode() : left(nullptr), right(nullptr) {}

template <class T>
BSTNode<T>::BSTNode(const T& item) : item(item), left(nullptr), right(nullptr) {}

template <class T>
void BSTNode<T>::setItem(const T& item) {
    this->item = item;
}

template <class T>
T& BSTNode<T>::getItem() {
    return item;
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* left) {
    this->left = left;
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* right) {
    this->right = right;
}

template <class T>
BSTNode<T>* BSTNode<T>::getLeft() {
    return left;
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight() {
    return right;
}

//Add item to the tree recursively, comparing based on the key of Pair
template <class T>
void BSTNode<T>::add(const T& item) {
    if (item < this->item) {//Compare based on the key
        if (left == nullptr) {
            left = new BSTNode<T>(item);//Add to the left if null
        }
        else {
            left->add(item);//else recurse the method
        }
    }
    else {
        if (right == nullptr) {
            right = new BSTNode<T>(item);//Add to the right if null
        }
        else {
            right->add(item);//else recurse the method
        }
    }
}

//Count the number of nodes in the subtree
template <class T>
int BSTNode<T>::count() {
    int count = 1;
    if (left != nullptr) count += left->count();
    if (right != nullptr) count += right->count();
    return count;
}