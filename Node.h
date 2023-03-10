//
// Created by avrod on 9/22/2020.
//

#ifndef FROGGER_NODE_H
#define FROGGER_NODE_H

#include <iostream>

template <class T>
class Node {
public:
    Node();
    Node(T data);
    // Accessors (getters)
    // For getNext and getPrev, we need two implementations so that the pointers are not
    // accessed and altered without our permission
    const Node<T>* getNext() const;
    Node<T>* getNext();
    const Node<T>* getPrev() const;
    Node<T>* getPrev();

    T& getData();
    T getData() const{
        return data;
    };

    // Mutators (setters)
    void setNext(Node<T>* next);
    void setPrev(Node<T>* prev);
    void setData(T data);

    template <class U>
    friend std::ostream& operator <<(std::ostream& outs,const Node<U>& node);

private:
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    T data;
};

#include "Node.cpp"

#endif //FROGGER_NODE_H