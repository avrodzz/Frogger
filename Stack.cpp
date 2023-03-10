//
// Created by avrod on 10/8/2020.
//

#ifndef FROGGER_STACK_CPP
#define FROGGER_STACK_CPP

#include "Stack.h"

template <class T>
Stack<T>::Stack(){

}
template <class T>
Stack<T>::Stack(const Stack<T>& stackObj){
//    std::cout << "------COPY CONSTRUCTOR------" << std::endl;
    *this = stackObj;
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stackObj){
//    std::cout << "------ASSIGNMENT OPERATOR------" << std::endl;
    const Node<T>* walker;
    for(walker = stackObj.stack.getHead(); walker != nullptr; walker = walker->getNext()){
        stack.insertAtEnd(walker->getData());
    }
    return *this;
}
template <class T>
Stack<T>::~Stack(){
    stack.clearList();
}
template <class T>
T Stack<T>::pop(){ //Do We Want It To be A Reference
    T value = stack.getHead()->getData();
    stack.deleteHead();
    return value;
}
template <class T>
void Stack<T>::push(const T& item){
    stack.insertAtBeginning(item);
}
template <class T>
bool Stack<T>::empty(){
    return stack.getSize() == 0; //Return true if empty, false if not empty
}
template <class T>
int Stack<T>::size() const{
    return stack.getSize();
}
template <class T>
T Stack<T>::top(){ //Return what value in at the top
    T value = stack.getHead()->getData();
    return value;
}
template <class T>
std::ostream& operator <<(std::ostream& outs, const Stack<T>& stackObj){
    return outs << stackObj.stack;
}
template <class T>
T Stack<T>::seek(unsigned int n){
    Node<T>* walker = stack.getHead();
    int count = 0;
    while(walker->getNext() != nullptr && count < n){
        walker = walker->getNext();
        count++;
    }
    return walker->getData();
}
template <class T>
typename Stack<T>::iterator Stack<T>::begin(){
    return stack.begin();
}
template <class T>
typename Stack<T>::iterator Stack<T>::end(){
    return stack.end();
}
template <class T>
typename Stack<T>::iterator Stack<T>::rBegin(){
    return stack.rBegin();
}
template <class T>
typename Stack<T>::iterator Stack<T>::rEnd(){
    return stack.rEnd();
}
template <class T>
typename Stack<T>::iterator Stack<T>::last(){
    return stack.last();
}

#endif