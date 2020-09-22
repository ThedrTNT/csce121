// SCLL.h
#ifndef SCLL_H
#define SCLL_H

#include <iostream>
#include "Node.h"

template <typename T>
class SortedCircularList {
  Node<T>* head;  
  Node<T>* tail;
public:
  SortedCircularList() : head(nullptr), tail(nullptr) {}
  void print(std::ostream& out=std::cout) const;
  // insert val into a sorted circular list
  void insertValue(const T& val);
};

// print function
template <typename T>
void SortedCircularList<T>::print(std::ostream& out) const {
   Node<T>* current=head;
   if (current!=nullptr) {
      out<<current->data<<" ";
      while(current->next != head)
   {
         current = current->next;   
         out<<current->data<<" ";
      }
   }
}

// WRITE THIS FUNCTION
template <typename T>
void SortedCircularList<T>::insertValue(const T& val)  {
    // TODO(student): insertValue
  Node<T>* newNode = new Node<T>(val);
  if(head == nullptr) {
    head = tail = newNode;
    return;
  }
  if(val <= head->data) {
    tail->next = newNode;
    newNode->next = head;
    head = newNode;
    return;
  }
  if(val >= tail->data) {
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
    return;
  }
  Node<T>* curr = head;
  //std::cout << "val: " << val << std::endl;
  //std::cout << "curr val: " << curr->data << std::endl;
  while(curr->next->data < val && curr->next != tail) {
    /*std::cout << "curr val: " << curr->data << std::endl;
    std::cout << (newNode->data < curr->next->data) << std::endl;*/
    curr = curr->next;
  }
  Node<T>* temp = curr->next;
  newNode->next = temp;
  curr->next = newNode;
}

#endif