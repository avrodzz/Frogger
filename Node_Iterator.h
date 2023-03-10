//
// Created by avrod on 10/6/2020.
//

#ifndef FROGGER_NODE_ITERATOR_H
#define FROGGER_NODE_ITERATOR_H

#include <iostream>
#include "Node.h"
#include <iterator>

// public std::iterator<std::random_access_iterator_tag, const T>

template <class T>
class Node_Iterator : public std::iterator<std::forward_iterator_tag, const T>{ //Child of STL
public:
    Node_Iterator(); //Iterator - a way to go through a container / list
    Node_Iterator(Node<T>* current);

    T& operator*() const; // Can change the value and be used to input and output

    Node_Iterator operator++(int); // Post Fix - x++ (forward iterator)
    Node_Iterator& operator++(); //Pre Fix - ++x (forward iterator)
    Node_Iterator operator--(int); //Post Fix (bi directional)
    Node_Iterator& operator--(); //Pre Fix
    bool operator!=(const Node_Iterator& iterObj) const;
    bool operator==(const Node_Iterator& iterObj) const;

    // RANDOM ACCESS FUNCTIONS - MIGHT WORK...
//    // Returns a reference to the item that is i spots forwards from p's current item.
////    T& operator[](unsigned int index);
////
////    // p += i, move position of current by a certain number of nodes
////    // Moves p forward i spots.
////    Node_Iterator& operator+=(unsigned int i);
////
////    // p -= i, move position of current by a certain number of nodes
////    // Moves p backward i spots.
////    Node_Iterator& operator-=(unsigned int i);
////
////    // +, (p + i) do not alter p - changes position
////    // This expression is an iterator that i spots after p (but p itself doesn't change)
////    template <class U>
////    friend Node_Iterator operator+(const Node_Iterator<U>& lhs, int i);
////
////    // -, (p - i) does not alter p - changes position
////    // This expression is an iterator that is i spots before p (but p itself doesn't change)
////    template <class U>
////    friend Node_Iterator operator-(const Node_Iterator<U>& lhs, int i);

//    template <class U>
//    friend Node_Iterator operator+(const Node_Iterator<U>& left,const Node_Iterator<U>& right);
//    template <class U>
//    friend Node_Iterator operator-(const Node_Iterator<U>& left,const Node_Iterator<U>& right);

private:
    Node<T>* current;
};

#include "Node_Iterator.cpp"

#endif //FROGGER_NODE_ITERATOR_H