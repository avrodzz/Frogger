//
// Created by avrod on 9/22/2020.
//

#ifndef FROGGER_NODE_CPP
#define FROGGER_NODE_CPP

#include "Node.h"

template <class T>
Node<T>::Node(){

}
template <class T>
Node<T>::Node(T data){
    this->data = data;
}
template <class T>
const Node<T>* Node<T>::getNext() const{
    return next;
}
template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}
template <class T>
const Node<T>* Node<T>::getPrev() const{
    return prev;
}
template <class T>
Node<T>* Node<T>::getPrev(){
    return prev;
}
template <class T>
T& Node<T>::getData() {
    return data;
}
template <class T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}
template <class T>
void Node<T>::setPrev(Node<T>* prev){
    this->prev = prev;
}
template <class T>
void Node<T>::setData(T data){
    this->data = data;
}
template <class U>
std::ostream& operator <<(std::ostream& outs,const Node<U>& node){
    outs << node.data;
    return outs;
}

#endif