//
// Created by avrod on 10/8/2020.
//


#ifndef FROGGER_QUEUE_CPP
#define FROGGER_QUEUE_CPP

#include "Queue.h"

template <class T>
Queue<T>::Queue(){
    // 1 // Push 1
    // 1 2 //Push 2
    // 1 2 3 //Push 3
    // 2 3 // Pop 1
}
template <class T>
Queue<T>::Queue(const Queue<T>& queueObj){
    std::cout << "------COPY CONSTRUCTOR------" << std::endl;
    *this = queueObj;
}
template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& queueObj){
    std::cout << "------ASSIGNMENT OPERATOR------" << std::endl;
    const Node<T>* walker;
    for(walker = queueObj.queue.getHead(); walker != nullptr; walker = walker->getNext()){
        queue.insertAtEnd(walker->getData());
    }
    return *this;
}
template <class T>
Queue<T>::~Queue(){
    queue.clearList();
}
template <class T>
T Queue<T>::pop(){
    T value = queue.getHead()->getData();
    queue.deleteHead();
    return value;
}
template <class T>
void Queue<T>::push(const T& item){
    queue.insertAtEnd(item);
}
template <class T>
bool Queue<T>::empty() const{
    return queue.getSize() == 0; //Return true if empty, false if not empty
}
template <class T>
int Queue<T>::size(){
    return queue.getSize();
}
template <class T>
T& Queue<T>::front() const{
    T& value = queue.getHead()->getData();
    return value;
}
template <class T>
std::ostream& operator <<(std::ostream& outs,const Queue<T>& queueObj){
    return outs << queueObj.queue;
}
template <class T>
T Queue<T>::seek(unsigned int n){
    Node<T>* walker = queue.getHead();
    int count = 0;
    while(walker->getNext() != nullptr && count < n){
        walker = walker->getNext();
        count++;
    }
    return walker->getData();
}
template <class T>
typename Queue<T>::iterator Queue<T>::begin(){
    return queue.begin();
}
template <class T>
typename Queue<T>::iterator Queue<T>::end(){
    return queue.end();
}
template <class T>
typename Queue<T>::iterator Queue<T>::rBegin(){
    return queue.rBegin();
}
template <class T>
typename Queue<T>::iterator Queue<T>::rEnd(){
    return queue.rEnd();
}
template <class T>
typename Queue<T>::iterator Queue<T>::last(){
    return queue.last();
}

#endif