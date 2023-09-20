// Made by @DaniDiazTech
#include <iostream>
#include "Node.h"

/// @brief  Double LinkedList

/// Methods
// push_back(el): O(1)
// push_front(el): O(1)
// pop_back(): O(1)
// pop_front(): O(1)
// size(): O(1)
// empty(): O(1)
// front(): O(1)
// back(): O(1)


/// @tparam T 
template<typename T> struct LinkedList{
  Node<T> *head ;
  Node<T> *tail;
  int _size;

  LinkedList(){
    head = tail =  nullptr;
    _size = 0;
  }

  int size(){
    return _size;
  }
  
  bool empty(){
    return size() == 0;
  }

  void push_back(T el){
    if (head == nullptr){
      push_front(el);
      return;
    }

    Node<T> *newNode = new Node<T>(el, nullptr, tail);

    tail ->next = newNode;

    tail = newNode;

    _size++;
  }

  void push_front(T el){
    Node<T> *newNode = new Node<T>(el, head);  

    if (head != nullptr){
      head->prev = newNode;
    }

    head = newNode;

    if (tail == nullptr){
      tail = head;
    }

    _size++;
  }

  T pop_front(){
    // Cannot pop head
    if (head == nullptr){
      throw std::out_of_range("Can't pop front of LinkedList");
    }

    // Access by reference
    T &to_return = head->element;

    head = head->next;

    if (head != nullptr){
      head->prev = nullptr;
    }
    else{
      tail = nullptr;
    }

    _size--;

    return to_return;
  }

  T pop_back(){
    if (tail == head){
      return pop_front();
    }

    // By reference not copy element over

    T &to_return = tail->element;
    tail = tail->prev;
    tail->next = nullptr;

    _size--;

    return to_return;
  }

  T front(){
    if (empty()){
      throw std::out_of_range("Can't access empty LinkedList");
    }
    return head->element;
  }

  T back(){
    if (empty()){
      throw std::out_of_range("Can't access empty LinkedList");
    }
    return tail->element;
  }
};
