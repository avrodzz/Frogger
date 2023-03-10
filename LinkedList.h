//
// Created by avrod on 9/22/2020.
//

#ifndef FROGGER_LINKEDLIST_H
#define FROGGER_LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "Node_Iterator.h"
#include "Const_Node_Iterator.h"

template <class T>
class LinkedList {
public:
    typedef Node_Iterator<T> iterator;
    typedef Const_Node_Iterator<T> const_iterator;

    LinkedList();

    //Big Three
    LinkedList(const LinkedList& linkList);
    LinkedList& operator=(const LinkedList& linkedList);
    ~LinkedList();

    // Regular Inserting
    void insertAtBeginning(const T& item);
    void insertAtEnd(const T& item);
    LinkedList& operator+=(const T& item);

    // Inserting Before/After A Particular Node
    void insertBefore(const T& before,const T& item);
    void insertAfter(const T& after, const T& item);

    // Delete A Node
    //  - Account for when the list is empty, when there is only one element
    //    in the list, and when we have multiple elements in the list.
    void remove(const T& item);

    void deleteHead();
    void deleteTail();

    // Check if the list is empty
    bool isEmpty();

    // Get the number of Nodes in the list
    int getSize() const;
    const Node<T>* getHead() const;
    Node<T>* getHead();
    const Node<T>* getTail() const;
    Node<T>* getTail();

    // Delete all Nodes in the list
    void clearList();

    template <class U>
    friend std::ostream& operator <<(std::ostream& outs,const LinkedList<U>& linkedList);

    //Iterator Functions
    // When You Are Iterating Forwards
    iterator begin(); //Points to the head of the list
    iterator end(); //Points to nullptr

    //When You Are Iterating Backwards
    iterator rBegin(); //Points to the tail of the list
    iterator rEnd(); //Points to nullptr

    iterator last(); //Points to the tail of the list

    //Const Iterator Functions
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator rBegin() const;
    const_iterator rEnd() const;
    const_iterator last() const;


private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    unsigned int size;

    void setSize(unsigned int size);

    // Find A Particular Node
    Node<T>* search(const T& item);

    // Find A Particular Node By Position (starting at 1)
//    Node<T>* search(const unsigned int position);
//    const Node<T>* search(const unsigned int position) const;

    //Add Node
    void addNode(Node<T>* node,const T& item);

    // Delete Node
    void deleteNode(Node<T>* node);
};

#include "LinkedList.cpp"

#endif //FROGGER_LINKEDLIST_H