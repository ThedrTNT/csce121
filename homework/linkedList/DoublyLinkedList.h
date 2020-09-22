#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//                         class template definition                        //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
class DoublyLinkedList {
public:
    /* uncomment the declarations as you implement them */
    DoublyLinkedList();
    DoublyLinkedList(T);
    DoublyLinkedList(const DoublyLinkedList<T>&);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
    ~DoublyLinkedList();
    unsigned int size() const { return sz; }
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void erase(unsigned int);
    void insert(T data, unsigned int idx);
    void clear();
    std::string to_str() const;
    // breaks encapsulation... gives operator== access to private data... not great approach, but makes the homework easier for you since we haven't talked about iterators :).
    // template<typename U> friend bool operator==(DoublyLinkedList<U> const&, DoublyLinkedList<U> const&);
private:
    // do not change ordering.
    Node<T> *head;
    Node<T> *tail;
    unsigned int sz;
};

//////////////////////////////////////////////////////////////////////////////
//                       helper function declarations                       //
//////////////////////////////////////////////////////////////////////////////
template<typename T> std::ostream& operator<<(std::ostream &, DoublyLinkedList<T> const&);

template<typename T> bool operator==(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

template<typename T> bool operator!=(DoublyLinkedList<T> const&, DoublyLinkedList<T> const&);

//////////////////////////////////////////////////////////////////////////////
//                     member template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    sz = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T data) {
    sz = 1;

    Node<T>* newNode = new Node<T>(data);
    head = newNode;
    tail = newNode;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& source) {
    if(source.head == nullptr) {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }
    else {
        head = new Node<T>(source.head->data);
        tail = head;
        sz = 1;
        Node<T>* curr = source.head->next;
        while(curr != nullptr) {
            push_back(curr->data);
            curr = curr->next;
        }
    }
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& source) {
    if (this != &source) {
        clear();
        if(source.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            sz = 0;
        }
        else {
            head = new Node<T>(source.head->data);
            tail = head;
            sz = 1;
            Node<T>* curr = source.head->next;
            while(curr != nullptr) {
                push_back(curr->data);
                curr = curr->next;
            }
        }
    }

    return *this;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
T& DoublyLinkedList<T>::front() {
    return head->data;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const{
    return head->data;
}

template<typename T>
T& DoublyLinkedList<T>::back() {
    return tail->data;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const{
    return tail->data;
}

template<typename T>
void DoublyLinkedList<T>::push_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (sz == 0) {
        tail = newNode;
        head = newNode;
        sz = 1;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    sz++;
}

template<typename T>
void DoublyLinkedList<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (sz == 0) {
        head = newNode;
        tail = newNode;
        sz++;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    sz++;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (sz <= 0) {
        return;
    }
    if (sz == 1) {
        clear();
        /*delete head;
        delete tail;
        tail = nullptr;
        head = nullptr;
        sz = 0;*/
        return;
    }
    Node<T>* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    tail = newTail;
    sz--;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (sz <= 0) {
        return;
    }
    if (sz == 1) {
        clear();
        return;
    }
    Node<T>* newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    head = newHead;
    sz--;
}

template<typename T>
void DoublyLinkedList<T>::erase(unsigned int idx) {
    if (idx >= sz || idx < 0) {
        return;
    }
    if (idx == 0) {
        pop_front();
        return;
    }
    if (idx == sz - 1) {
        pop_back();
        return;
    }

    Node<T>* curr = head;
    unsigned int count = 1;
    while (curr->next != nullptr && count < idx) {
        curr = curr->next;
        count++;
    }
    Node<T>* temp = curr;
    curr = curr->next;
    Node<T>* toDelete = curr;
    temp->next = curr->next;
    curr = curr->next;
    curr->prev = temp;

    delete toDelete;

    sz--;
}

template<typename T>
void DoublyLinkedList<T>::insert(T data, unsigned int idx) {
    if (idx >= sz || idx < 0) {
        return;
    }

    Node<T>* curr = head;
    Node<T>* newNode = new Node<T>(data);
    unsigned int count = 1;
    while(curr->next != nullptr && count < idx) {
        curr = curr->next;
        count++;
    }
    if (curr == tail) {
        push_back(data);
        return;
    }
    if (curr == head) {
        push_front(data);
        return;
    }
    //curr = curr->prev;
    newNode->next = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    curr = newNode->next;
    curr->prev = newNode;

    sz++;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        Node<T>* del = curr;
        curr = curr->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template<typename T>
std::string DoublyLinkedList<T>::to_str() const
{
    std::stringstream os;
    const Node<T> *curr = head;
    os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    os << "head: " << head << std::endl;
    os << "tail: " << tail << std::endl;
    os << "  sz: " << sz << std::endl;
    os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
    while (curr) {
        os << std::setw(16) << curr;
        os << std::setw(16) << curr->prev;
        os << std::setw(16) << curr->data;
        os << std::setw(16) << curr->next;
        os << std::endl;
        curr = curr->next;
    }
    os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
    return os.str();
}

//////////////////////////////////////////////////////////////////////////////
//                     helper template function definitions                 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
bool operator==(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
    // getting you started on this once... definition for this overloaded operator will go here.
    if (lhs.front() != rhs.front()) {
        return false;
    }
    if (lhs.back() != rhs.back()) {
        return false;
    }
    if (lhs.size() != rhs.size()) {
        return false;
    }
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T> const& rhs)
{
    os << rhs.to_str();
    return os;
}

template<typename T>
bool operator!=(DoublyLinkedList<T> const& lhs, DoublyLinkedList<T> const& rhs)
{
    return !(lhs == rhs);
}

#endif
