#pragma once
#include <iostream>

template <class K, class V>
class Pair {
private:
    K first;//Key of the pair
    V second;//Value of the pair

public:
    Pair();//Default constructor
    Pair(K first, V second);//Constructor with parameters

    K& getFirst();//Getter for key
    V& getSecond();//Getter for value
    void setFirst(const K& first);//Setter for key
    void setSecond(const V& second);//Setter for value

    bool operator<(const Pair<K, V>& other) const;//Comparison based on the key
    bool operator>(const Pair<K, V>& other) const;//Comparison based on the key
    bool operator==(const Pair<K, V>& other) const;//Equality check based on the key

    //Define the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
};

//Constructor and member function definitions
template <class K, class V>
Pair<K, V>::Pair() : first(K()), second(V()) {}  //Default constructor initializes to default values

template <class K, class V>
Pair<K, V>::Pair(K first, V second) : first(first), second(second) {}

template <class K, class V>
K& Pair<K, V>::getFirst() {
    return first;//Return reference to the key
}

template <class K, class V>
V& Pair<K, V>::getSecond() {
    return second;//Return reference to the value
}

template <class K, class V>
void Pair<K, V>::setFirst(const K& first) {
    this->first = first;//Set the key
}

template <class K, class V>
void Pair<K, V>::setSecond(const V& second) {
    this->second = second;//Set the value
}

template <class K, class V>
bool Pair<K, V>::operator<(const Pair<K, V>& other) const {
    return this->first < other.first;//Compare based on the key
}

template <class K, class V>
bool Pair<K, V>::operator>(const Pair<K, V>& other) const {
    return this->first > other.first;//Compare based on the key
}

template <class K, class V>
bool Pair<K, V>::operator==(const Pair<K, V>& other) const {
    return this->first == other.first;//Equality based on the key
}