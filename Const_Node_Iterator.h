//
// Created by avrod on 10/13/2020.
//

#ifndef FROGGER_CONST_NODE_ITERATOR_H
#define FROGGER_CONST_NODE_ITERATOR_H

#include <iostream>
#include "Node.h"
#include <iterator>

template <class T>
class Const_Node_Iterator : public std::iterator<std::forward_iterator_tag, const T> {
public:
    Const_Node_Iterator(); //Iterator - a way to go through a container / list
    Const_Node_Iterator(Node<T>* current);

    const T& operator*() const;

    Const_Node_Iterator operator++(int); // Post Fix - x++ (forward iterator)
    Const_Node_Iterator& operator++(); //Pre Fix - ++x (forward iterator)
    Const_Node_Iterator operator--(int); //Post Fix (bi directional)
    Const_Node_Iterator& operator--(); //Pre Fix
    bool operator!=(const Const_Node_Iterator& iterObj) const;
    bool operator==(const Const_Node_Iterator& iterObj) const;

//    T& operator[](unsigned int index);
//
//    Const_Node_Iterator operator+=(unsigned int i);
//
//    Const_Node_Iterator operator-=(unsigned int i);
//
//    template <class U>
//    friend Const_Node_Iterator operator+(Const_Node_Iterator<U> lhs, int i);
//
//    template <class U>
//    friend Const_Node_Iterator operator-(Const_Node_Iterator<U> lhs, int i);

private:
    const Node<T>* current;
};

#include "Const_Node_Iterator.cpp"


#endif //FROGGER_CONST_NODE_ITERATOR_H
