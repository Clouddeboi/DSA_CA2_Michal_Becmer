#pragma once
#include "BinaryTree.h"
#include "Pair.h"

template <class K, class V>
class TreeMap {
private:
    BinaryTree<Pair<K, V>> tree;//Binary tree to store pairs

public:
    TreeMap();//Constructor
    void put(const K& key, const V& value);//Insert a key-value pair
    V& get(const K& key);//Get value for a key (now returns a reference)
    bool containsKey(const K& key);//Check if key exists
    bool remove(const K& key);//Remove a key-value pair
    int size();//Get the number of key-value pairs
    void clear();//Clear the TreeMap
    void printInOrder();//Print all key-value pairs in order
    void printPreOrder();//Print all key-value pairs in pre-order
    void printPostOrder();//Print all key-value pairs in post-order
    BinaryTree<K> keySet();//Get a set of all keys in the TreeMap
    //void traverseInOrder(std::function<void(BSTNode<Pair<K, V>>*)> visit) const;

    //Added operator[] for direct access to elements
    V& operator[](const K& key);//Access or insert key-value pair
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
V& TreeMap<K, V>::get(const K& key) {
    Pair<K, V> pair(key, V());//Create a pair with the key and a default value
    Pair<K, V>& foundPair = tree.get(pair);//Get the pair from the tree
    return foundPair.getSecond();//Return the reference to the value part of the pair
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(const K& key) {
    Pair<K, V> pair(key, V());//Create a pair with the key
    try {
        tree.get(pair);//Try to get the pair from the tree
        return true;//If key exists, return true
    }
    catch (const std::logic_error&) {//Catch logic_error thrown by get() if key is not found
        return false;//If key not found, return false
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
    tree.printInOrder();//Print in order (in-order traversal)
}

template <class K, class V>
void TreeMap<K, V>::printPreOrder() {
    tree.printPreOrder();//Print pre-order (pre-order traversal)
}

template <class K, class V>
void TreeMap<K, V>::printPostOrder() {
    tree.printPostOrder();//Print post-order (post-order traversal)
}

template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet() {
    BinaryTree<K> keysTree;//Create a new BinaryTree to store the keys

    //Function to traverse the tree recursively
    std::function<void(BSTNode<Pair<K, V>>*)> traverse = [&](BSTNode<Pair<K, V>>* node)
        {
            if (node != nullptr) {//If the node is not null
                traverse(node->getLeft());//Visit left subtree
                keysTree.add(node->getItem().getFirst());//Add the key to keysTree
                traverse(node->getRight());//Visit right subtree
            }
        };

    traverse(tree.root);//Start traversal from the root of the binary tree
    return keysTree;//Return the BinaryTree containing the keys
}

template <class K, class V>
V& TreeMap<K, V>::operator[](const K& key) {
    //Try to get the value for the key, if it does not exist, insert with default value
    //This is so if the user tries to insert a value that doesn't exist, it will make a new key with the input
    //and print out an empty vector (since there is nothing in that field)
    try {
        return get(key);//Try to get the value using the get() method
    }
    catch (const std::logic_error&) {
        put(key, V());//Insert a new pair with default value if not found
        return get(key);//Return the newly inserted default value
    }
}