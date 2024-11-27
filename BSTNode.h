#pragma once
#include "Pair.h"  //Include the Pair class
#include <vector>

template <typename T>
class BSTNode {
public:
    Pair<char, std::vector<T>> data;  //Data member of type Pair (char, vector<T>)
    BSTNode* left;  //Left child of the node
    BSTNode* right;  //Right child of the node

    BSTNode(char firstLetter);  //Constructor to initialize the node with a key
    void add(const T& item, char firstLetter);  //Method to add an item to the tree
    void setItem(const Pair<char, std::vector<T>>& item);  //Setter for data
    Pair<char, std::vector<T>>& getItem();  //Getter for data
    BSTNode* getLeft();  //Getter for the left child
    BSTNode* getRight();  //Getter for the right child
    void setLeft(BSTNode* leftChild);  //Setter for the left child
    void setRight(BSTNode* rightChild);  //Setter for the right child
    int count() const;  // Count the number of nodes in this subtree
};

// Implementation of count() in BSTNode
template <typename T>
int BSTNode<T>::count() const {
    int leftCount = (left == nullptr) ? 0 : left->count();  // Recursively count left subtree
    int rightCount = (right == nullptr) ? 0 : right->count();  // Recursively count right subtree
    return 1 + leftCount + rightCount;  // Count this node and add the counts of left and right
}

//Constructor to initialize the node with a first letter
template <typename T>
BSTNode<T>::BSTNode(char firstLetter) : data(firstLetter, std::vector<T>()) {
    left = nullptr;  //Left child is initially nullptr
    right = nullptr;  //Right child is initially nullptr
}

template <typename T>
void BSTNode<T>::add(const T& item, char firstLetter) {
    if (data.getFirst() == firstLetter) {  // Use the getter to access 'first'
        data.getSecond().push_back(item);  // Add the item to the vector if the first letter matches
    }
    else if (firstLetter < data.getFirst()) {  // Use the getter to access 'first'
        if (left == nullptr) {
            left = new BSTNode<T>(firstLetter);  // Create a new left node if needed
        }
        left->add(item, firstLetter);  // Recur on the left subtree
    }
    else {
        if (right == nullptr) {
            right = new BSTNode<T>(firstLetter);  // Create a new right node if needed
        }
        right->add(item, firstLetter);  // Recur on the right subtree
    }
}

//Setter for the data of the node
template <typename T>
void BSTNode<T>::setItem(const Pair<char, std::vector<T>>& item) {
    data = item;  //Set the node's data to the given item
}

//Getter for the data of the node
template <typename T>
Pair<char, std::vector<T>>& BSTNode<T>::getItem() {
    return data;  //Return the node's data
}

//Getter for the left child of the node
template <typename T>
BSTNode<T>* BSTNode<T>::getLeft() {
    return left;  //Return the left child
}

//Getter for the right child of the node
template <typename T>
BSTNode<T>* BSTNode<T>::getRight() {
    return right;  //Return the right child
}

//Setter for the left child of the node
template <typename T>
void BSTNode<T>::setLeft(BSTNode* leftChild) {
    left = leftChild;  //Set the left child
}

//Setter for the right child of the node
template <typename T>
void BSTNode<T>::setRight(BSTNode* rightChild) {
    right = rightChild;  //Set the right child
}
