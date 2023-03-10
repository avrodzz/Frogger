//
// Created by avrod on 9/22/2020.
//

#ifndef FROGGER_LINKEDLIST_CPP
#define FROGGER_LINKEDLIST_CPP

#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& linkList){
//    std::cout << "------COPY CONSTRUCTOR------" << std::endl;
    *this = linkList;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& linkedList){
//    std::cout << "------ASSIGNMENT OPERATOR------" << std::endl;
    Node<T>* walker;
    for(walker = linkedList.head; walker != nullptr; walker = walker->getNext()){
        this->insertAtEnd(walker->getData());
    }
    this->setSize(linkedList.getSize());
    return *this;
}
template <class T>
LinkedList<T>::~LinkedList(){
    if(tail != nullptr){
        while(head != nullptr){
//            std::cout << "------DESTRUCTOR------" << std::endl;
            deleteHead();
        }
        size = 0;
        tail = nullptr;
    }
}
template <class T>
void LinkedList<T>::insertAtBeginning(const T& item){
    Node<T>* temp = new Node<T>;
    temp->setData(item);

    if(tail != nullptr){
        temp->setNext(head);
        head->setPrev(temp);
        head = temp;
    }
    else {
        head = temp;
        tail = temp;
    }
    size++;
}
template <class T>
void LinkedList<T>::insertAtEnd(const T& item){
    Node<T>* temp = new Node<T>;
    temp->setData(item);
    temp->setPrev(tail);

    if(tail != nullptr){
        tail->setNext(temp);
        tail = temp;
    }
    else{
        head = temp;
        tail = temp;
    }
    size++;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator+=(const T& item){
    insertAtEnd(item);
    return *this;
}
template <class T>
void LinkedList<T>::insertBefore(const T& before,const T& item){
    Node<T>* current = search(before);
    if(current != nullptr)
        addNode(current->getPrev(),item);
}
template <class T>
void LinkedList<T>::insertAfter(const T& after, const T& item){
    Node<T>* current = search(after);
    if(current != nullptr)
        addNode(current,item);
}
template <class T>
void LinkedList<T>::addNode(Node<T>* node,const T& item){
    Node<T>* temp = new Node<T>;
    temp->setData(item);
    Node<T>* walker = node;

    //Inserting After Last Node In the List
    if(walker->getNext() == nullptr){
        temp->setPrev(tail);
        tail->setNext(temp);
        tail = temp;
    }
    //Inserting After A Node that is not the last one
    else{
        Node<T>* nextNode = walker->getNext(); //Points to node after selected value
        temp->setPrev(walker);
        temp->setNext(nextNode);
        nextNode->setPrev(temp);
        walker->setNext(temp);
    }
    size++;
}
template <class T>
Node<T>* LinkedList<T>::search(const T& item){
    Node<T>* walker = head;
    while(walker != nullptr){
        if(walker->getData() == item){
            return walker;
        }
        walker = walker->getNext();
    }
    return nullptr; //Item not found in the list
}
//template <class T>
//Node<T>* LinkedList<T>::search(const unsigned int position){
//    Node<T>* walker = head;
//    for(int i = 1; (i < position) && (walker != nullptr); i++){
//        walker = walker->getNext();
//    }
//    return walker;
//}
//template <class T>
//const Node<T>* LinkedList<T>::search(const unsigned int position) const{
//    const Node<T>* walker = head;
//    for(int i = 1; (i < position) && (walker != nullptr); i++){
//        walker = walker->getNext();
//    }
//    return walker;
//}
template <class T>
void LinkedList<T>::deleteNode(Node<T>* node){
    Node<T>* walker = node;
    Node<T>* prevNode;
    Node<T>* nextNode;
    //Node that we want to delete is at the head of the list
    if(walker == head){
        if(walker->getNext() == nullptr){ //If there is one Node in the list
            head = nullptr;
            tail = nullptr;
        }
        else{
            nextNode = walker->getNext();
            nextNode->setPrev(nullptr);
            head = nextNode;
        }
    }
    //Node that we want to delete is at the tail of the list
    else if(walker == tail){
        prevNode = walker->getPrev();
        prevNode->setNext(nullptr);
        tail = prevNode;
    }
    //Node that we want to delete is somewhere in the middle of the list
    else if(walker != head && walker != tail){
        prevNode = walker->getPrev();
        prevNode->setNext(walker->getNext());
        walker->getNext()->setPrev(prevNode);
    }
    size--;
    delete walker;
}
template <class T>
void LinkedList<T>::remove(const T& item){
    Node<T>* current = search(item);
    if(current != nullptr)
        deleteNode(current);
}
template <class T>
void LinkedList<T>::deleteHead(){
    if(head != nullptr)
        deleteNode(head);
}
template <class T>
void LinkedList<T>::deleteTail(){
    if(tail != nullptr)
        deleteNode(tail);
}
template <class T>
bool LinkedList<T>::isEmpty(){
    return (tail == nullptr);
}
template <class T>
int LinkedList<T>::getSize() const{
    return size;
}
template <class T>
const Node<T>* LinkedList<T>::getHead() const{
    return head;
}
template <class T>
Node<T>* LinkedList<T>::getHead(){
    return head;
}
template <class T>
const Node<T>* LinkedList<T>::getTail() const{
    return tail;
}
template <class T>
Node<T>* LinkedList<T>::getTail(){
    return tail;
}
template <class T>
void LinkedList<T>::setSize(unsigned int size){
    this->size = size;
}
template <class T>
void LinkedList<T>::clearList(){
    if(tail != nullptr){
        while(head != nullptr){
//            std::cout << "------DESTRUCTOR------" << std::endl;
            deleteHead();
        }
        size = 0;
        tail = nullptr;
    }
}
template <class U>
std::ostream& operator <<(std::ostream& outs,const LinkedList<U>& linkedList){
    if(linkedList.head == nullptr) {
        outs << "No Items In This List";
        return outs;
    }
    else {
//        typename LinkedList<T>::iterator temp; //typename will fix all your problems
//        for(temp = linkedList.begin(); temp != linkedList.end(); ++temp){ //Iterators usually use prefix ++x
//            outs << *temp << ' ';
//        }
        for (Node<U>* walker = linkedList.head; walker != nullptr; walker = walker->getNext()) {
            outs << walker->getData() << ' ';
        }
        return outs;
    }
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin(){
    iterator temp (head);
    return temp;
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end(){
    iterator temp(nullptr);
    return temp;
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::rBegin(){
    iterator temp (tail);
    return temp;
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::rEnd(){
    iterator temp(nullptr);
    return temp;
}
template <class T>
typename LinkedList<T>::iterator LinkedList<T>::last(){
    iterator temp(tail);
    return temp;
}
template <class T>
typename LinkedList<T>::const_iterator LinkedList<T>::begin() const{
    const_iterator temp (head);
    return temp;
}
template <class T>
typename LinkedList<T>::const_iterator LinkedList<T>::end() const{
    const_iterator temp (nullptr);
    return temp;
}
template <class T>
typename LinkedList<T>::const_iterator LinkedList<T>::rBegin() const{
    const_iterator temp (tail);
    return temp;
}
template <class T>
typename LinkedList<T>::const_iterator LinkedList<T>::rEnd() const{
    const_iterator temp (nullptr);
    return temp;
}
template <class T>
typename LinkedList<T>::const_iterator LinkedList<T>::last() const{
    iterator temp(tail);
    return temp;
}

#endif