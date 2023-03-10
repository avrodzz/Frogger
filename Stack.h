//
// Created by avrod on 10/8/2020.
//

#ifndef FROGGER_STACK_H
#define FROGGER_STACK_H

#include <iostream>
#include "LinkedList.h"
#include <iterator>

template <class T>
class Stack {
public:
    typedef Node_Iterator<T> iterator;

    //Default Constructor
    Stack();

    //Big Three
    Stack(const Stack& stackObj);               //COPY CONSTRUCTOR
    Stack& operator=(const Stack& stackObj);    //ASSIGNMENT OPERATOR
    ~Stack();                                   //DESTRUCTOR

    //Pops the element at the top of the stack
    T pop();

    //Pushes an elements to the top of the stack
    void push(const T& item);

    //Returns true if the stack is empty
    bool empty();

    //Returns the number of elements in the stack
    int size() const;

    //Returns the element that is at the top of the stack but does NOT pop it from the stack
    T top();

    template <class U>
    friend std::ostream& operator <<(std::ostream& outs, const Stack<U>& stackObj);

    T seek(unsigned int n);

    //Iterator Functions
    iterator begin();
    iterator end();
    iterator rBegin();
    iterator rEnd();
    iterator last();

private:
    LinkedList<T> stack;
};

#include "Stack.cpp"

#endif //FROGGER_STACK_H