//
// Created by avrod on 10/6/2020.
//

#ifndef FROGGER_NODE_ITERATOR_CPP
#define FROGGER_NODE_ITERATOR_CPP

#include "Node_Iterator.h"

template <class T>
Node_Iterator<T>::Node_Iterator(){
    current = nullptr;
}
template <class T>
Node_Iterator<T>::Node_Iterator(Node<T>* current){
    this->current = current;
}
template <class T>
T& Node_Iterator<T>::operator*() const{
    return current->getData();
}
template <class T>
Node_Iterator<T> Node_Iterator<T>::operator++(int){
    Node_Iterator<T> temp(current);
    current = current->getNext();
    return temp;
}
template <class T>
Node_Iterator<T>& Node_Iterator<T>::operator++(){
    current = current->getNext();
    return *this;
}
template <class T>
Node_Iterator<T> Node_Iterator<T>::operator--(int){
    Node_Iterator<T> temp(current);
    current = current->getPrev();
    return temp;
}
template <class T>
Node_Iterator<T>& Node_Iterator<T>::operator--(){
    current = current->getPrev();
    return *this;
}
template <class T>
bool Node_Iterator<T>::operator!=(const Node_Iterator& iterObj) const{
    return current != iterObj.current;
}
template <class T>
bool Node_Iterator<T>::operator==(const Node_Iterator& iterObj) const{
    return current == iterObj.current;
}
//template <class T>
//T& Node_Iterator<T>::operator[](unsigned int index){
//    Node<T>* walker = current;
//    int count = 0;
//    while(walker->getNext() != nullptr && count < index){
//        walker = walker->getNext();
//        count++;
//    }
//    current = walker;
//    return *this;
//}
//template <class T>
//Node_Iterator<T>& Node_Iterator<T>::operator+=(unsigned int i){
//    Node<T>* walker = current;
//    int count = 0;
//    while(walker->getNext() != nullptr && count < i){
//        walker = walker->getNext();
//        count++;
//    }
//    current = walker;
//    return *this;
//}
//template <class T>
//Node_Iterator<T>& Node_Iterator<T>::operator-=(unsigned int i){
//    Node<T>* walker = current;
//    int count = 0;
//    while(walker->getPrev() != nullptr && count < i){
//        walker = walker->getPrev();
//        count++;
//    }
//    current = walker;
//    return *this;
//}
//template <class T>
//Node_Iterator<T> operator+(const Node_Iterator<T>& left, int num){
//    Node_Iterator<T> temp = left;
//    temp += num;
//    return temp;
//}
//template <class T>
//Node_Iterator<T> operator-(const Node_Iterator<T>& left, int num){
//    Node_Iterator<T> temp = left;
//    temp -= num;
//    return temp;
//}
//template<class U>
//Node_Iterator<U> operator+(const Node_Iterator<U>& left, const Node_Iterator<U>& right) {
//    return left.current + right.current;
//}
//template<class U>
//Node_Iterator<U> operator-(const Node_Iterator<U>& left, const Node_Iterator<U>& right) {
//    return left.current - right.current;
//}

#endif