#pragma once
#include <iostream>

using namespace std;

template <class K, class V>
class Pair {
private:
    K first; //Key of the pair
    V second;//Value of the pair

public:
    //Default constructor
    Pair();

    //Constructor with parameters
    Pair(K first, V second);

    //Getter for the key
    K& getFirst();

    //Getter for the value
    V& getSecond();

    //Setter for the key
    void setFirst(const K& first);

    //Setter for the value
    void setSecond(const V& second);

    //Comparison based on the key
    bool operator<(const Pair<K, V>& other) const;

    //Comparison based on the key
    bool operator>(const Pair<K, V>& other) const;

    //Equality check based on the key
    bool operator==(const Pair<K, V>& other) const;

    //Output stream operator for Pair
    friend ostream& operator<<(ostream& out, const Pair<K, V>& other) {
        out << other.first << other.second; //Print key and value
        return out;
    }
};

//Constructor and member function definitions

//Default constructor initializes to default values
template <class K, class V>
Pair<K, V>::Pair() : first(K()), second(V()) {}

//Constructor with parameters to initialize the pair
template <class K, class V>
Pair<K, V>::Pair(K first, V second) : first(first), second(second) {}

//Getter for the key
template <class K, class V>
K& Pair<K, V>::getFirst() {
    return first; //Return reference to the key
}

//Getter for the value
template <class K, class V>
V& Pair<K, V>::getSecond() {
    return second; //Return reference to the value
}

//Setter for the key
template <class K, class V>
void Pair<K, V>::setFirst(const K& first) {
    this->first = first; //Set the key
}

//Setter for the value
template <class K, class V>
void Pair<K, V>::setSecond(const V& second) {
    this->second = second; //Set the value
}

//Comparison based on the key (less than)
template <class K, class V>
bool Pair<K, V>::operator<(const Pair<K, V>& other) const {
    return this->first < other.first; //Compare based on the key
}

//Comparison based on the key (greater than)
template <class K, class V>
bool Pair<K, V>::operator>(const Pair<K, V>& other) const {
    return this->first > other.first; //Compare based on the key
}

//Equality check based on the key
template <class K, class V>
bool Pair<K, V>::operator==(const Pair<K, V>& other) const {
    return this->first == other.first; //Equality based on the key
}
