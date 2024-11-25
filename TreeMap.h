#pragma once
#include "BinaryTree.h"  //Include BinaryTree.h for BinaryTree class
#include "Pair.h"  //Include Pair.h for Pair class

template <class K, class V>
class TreeMap {
private:
    BinaryTree<Pair<K, V>> tree;  //Binary tree to store pairs

public:
    TreeMap();//Constructor
    void put(const K& key, const V& value);//Insert a key-value pair
    V get(const K& key);//Get value for a key
    bool containsKey(const K& key);//Check if key exists
    bool remove(const K& key);//Remove a key-value pair
    int size();//Get the number of key-value pairs
    void clear();//Clear the TreeMap
    void printInOrder();//Print all key-value pairs in order
    void printPreOrder();//Print all key-value pairs in pre-order
    void printPostOrder();//Print all key-value pairs in post-order
    BinaryTree<K> keySet();
};

template <class K, class V>
TreeMap<K, V>::TreeMap() {
    //Constructor, BinaryTree is automatically initialized
}

template <class K, class V>
void TreeMap<K, V>::put(const K& key, const V& value) {
    Pair<K, V> pair(key, value);//Create a pair
    tree.add(pair);//Add pair to the tree
}

template <class K, class V>
V TreeMap<K, V>::get(const K& key) {
    Pair<K, V> pair(key, V());//Create a pair with the key and a default value
    Pair<K, V>& foundPair = tree.get(pair);//Get the pair from the tree
    return foundPair.second;//Return the value part of the pair
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(const K& key) {
    Pair<K, V> pair(key, V());//Create a pair with key
    try {
        tree.get(pair);//Try to get the pair from the tree
        return true;
    }
    catch (const std::runtime_error&) {
        return false;//If Key not found, catch error
    }
}

template <class K, class V>
bool TreeMap<K, V>::remove(const K& key) {
    Pair<K, V> pair(key, V());//Create a pair with key
    return tree.remove(pair);//Try to remove the pair from the tree
}

template <class K, class V>
int TreeMap<K, V>::size() {
    return tree.count();//Return the number of nodes in the tree
}

template <class K, class V>
void TreeMap<K, V>::clear() {
    tree.clear();//Clear the entire tree
}

template <class K, class V>
void TreeMap<K, V>::printInOrder() {
    tree.printInOrder();//Print in order
}

template <class K, class V>
void TreeMap<K, V>::printPreOrder() {
    tree.printPreOrder();//Print pre-order
}

template <class K, class V>
void TreeMap<K, V>::printPostOrder() {
    tree.printPostOrder();//Print post-order
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet() {
    BinaryTree<K> keysTree;//Create a new BinaryTree to store the keys

    //function to traverse the tree recursively
    std::function<void(BSTNode<Pair<K, V>>*)> traverse = [&](BSTNode<Pair<K, V>>* node) 
        {
        if (node != nullptr) {
            traverse(node->getLeft());//Visit left subtree
            keysTree.add(node->getItem().getFirst());//Add the key to keysTree
            traverse(node->getRight());//Visit right subtree
        }
        };

    traverse(tree.root);//Start traversal from the root of the binary tree
    return keysTree;//Return the BinaryTree containing the keys
}


