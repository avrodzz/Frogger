//
// Created by avrod on 10/13/2020.
//

#ifndef FROGGER_CONST_NODE_ITERATOR_CPP
#define FROGGER_CONST_NODE_ITERATOR_CPP

#include "Const_Node_Iterator.h"

template <class T>
Const_Node_Iterator<T>::Const_Node_Iterator(){

}
template <class T>
Const_Node_Iterator<T>::Const_Node_Iterator(Node<T>* current){

}
template <class T>
const T& Const_Node_Iterator<T>::operator*() const{
    return current->getData();
}
template <class T>
Const_Node_Iterator<T> Const_Node_Iterator<T>::operator++(int){
    Const_Node_Iterator<T> temp(current);
    current = current->getNext();
    return temp;
}
template <class T>
Const_Node_Iterator<T>& Const_Node_Iterator<T>::operator++(){
    current = current->getNext();
    return *this;
}
template <class T>
Const_Node_Iterator<T> Const_Node_Iterator<T>::operator--(int){
    Const_Node_Iterator<T> temp(current);
    current = current->getPrev();
    return temp;
}
template <class T>
Const_Node_Iterator<T>& Const_Node_Iterator<T>::operator--(){
    current = current->getPrev();
    return *this;
}
template <class T>
bool Const_Node_Iterator<T>::operator!=(const Const_Node_Iterator<T>& iterObj) const{
    return current != iterObj.current;
}
template <class T>
bool Const_Node_Iterator<T>::operator==(const Const_Node_Iterator<T>& iterObj) const{
    return current == iterObj.current;
}

#endif