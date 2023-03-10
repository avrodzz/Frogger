//
// Created by avrod on 10/8/2020.
//

#ifndef FROGGER_QUEUE_H
#define FROGGER_QUEUE_H

#include <iostream>
#include "LinkedList.h"
#include <iterator>

template <class T>
class Queue {
public:
    typedef Node_Iterator<T> iterator;

    //Default Constructor
    Queue();

    //Big Three
    Queue(const Queue& queueObj);
    Queue& operator =(const Queue& queueObj);
    ~Queue();

    //Pops the element at the front of the queue
    T pop();

    //Pushes an elements to the back of the queue
    void push(const T& item);

    //Returns true if the stack is empty
    bool empty() const;

    //Returns the number of elements in the stack
    int size();

    //Returns the element that is at the front of the queue but does NOT pop it from the queue
    T& front() const;

    template <class U>
    friend std::ostream& operator <<(std::ostream& outs,const Queue<U>& queueObj);

    T seek(unsigned int n);
    // Precondition: n < size()
    // Postcondition: The return value is the item that is n from the top (with the top at n = 0,
    // the next at n = 1, and so on). The stack is not changed.

    //Iterator Functions
    iterator begin();
    iterator end();
    iterator rBegin();
    iterator rEnd();
    iterator last();

private:
    LinkedList<T> queue;
};

#include "Queue.cpp"

#endif //FROGGER_QUEUE_H