#pragma once
#include <iostream>
#include <vector> // Include vector for the vector specialization of the << operator

template <class K, class V>
class Pair {
private:
    K first;  // Key of the pair
    V second;  // Value of the pair

public:
    Pair();  // Default constructor
    Pair(K first, V second);  // Constructor with parameters

    const K& getFirst() const;  // Getter for key (const reference)
    const V& getSecond() const;  // Getter for value (const reference)
    void setFirst(const K& first);  // Setter for key
    void setSecond(const V& second);  // Setter for value

    bool operator<(const Pair<K, V>& other) const;  // Comparison based on the key
    bool operator>(const Pair<K, V>& other) const;  // Comparison based on the key
    bool operator==(const Pair<K, V>& other) const;  // Equality comparison

    friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
};

template <class K, class V>
Pair<K, V>::Pair() : first(K()), second(V()) {}

template <class K, class V>
Pair<K, V>::Pair(K first, V second) : first(first), second(second) {}

template <class K, class V>
const K& Pair<K, V>::getFirst() const {
    return first;
}

template <class K, class V>
const V& Pair<K, V>::getSecond() const {
    return second;
}

template <class K, class V>
void Pair<K, V>::setFirst(const K& first) {
    this->first = first;
}

template <class K, class V>
void Pair<K, V>::setSecond(const V& second) {
    this->second = second;
}

template <class K, class V>
bool Pair<K, V>::operator<(const Pair<K, V>& other) const {
    return first < other.first;
}

template <class K, class V>
bool Pair<K, V>::operator>(const Pair<K, V>& other) const {
    return first > other.first;
}

template <class K, class V>
bool Pair<K, V>::operator==(const Pair<K, V>& other) const {
    return first == other.first && second == other.second;
}

// Specialization for Pair<int, std::string> to ensure equality check works as expected
template <>
bool Pair<int, std::string>::operator==(const Pair<int, std::string>& other) const {
    return first == other.first && second == other.second;
}

// Specialization for printing Pair<char, std::vector<T>> in a custom format
template <typename T>
std::ostream& operator<<(std::ostream& os, const Pair<char, std::vector<T>>& p) {
    os << "[" << p.getFirst() << ": [";
    for (size_t i = 0; i < p.getSecond().size(); ++i) {
        os << p.getSecond()[i];
        if (i < p.getSecond().size() - 1) os << ", ";
    }
    os << "]]";
    return os;
}

// Define the << operator for std::vector<Pair<int, std::string>>
std::ostream& operator<<(std::ostream& os, const std::vector<Pair<int, std::string>>& vec) {
    os << "["; // Begin output for the vector
    for (size_t i = 0; i < vec.size(); ++i) {
        os << "(" << vec[i].getFirst() << ", " << vec[i].getSecond() << ")";
        if (i < vec.size() - 1) os << ", ";  // Add a separator except for the last element
    }
    os << "]"; // End output for the vector
    return os;
}
