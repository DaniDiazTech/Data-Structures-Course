#include "../LinkedList/LinkedList.h"

// Inherits from LinkedList (Double linked list)
// O(1) operations
// - `top()`: Returns the element at the top of the stack
// - `push()`: Inserts an element at the top of the stack.
// - `pop()`: Takes out the element at the top of the stack and returns it.
// - `size()`: Returns an integer, the number of elements the stack currently stores.
// - `empty()`: You guessed it! Returns a boolean indicating if the stack is empty or not.

template<typename T> struct Stack : LinkedList<T>{
  // Use top part of the linked list
  Stack(){}

  T top(){
    return this->front();
  }

  void push(T el){
    this->push_front(el);
  }

  T pop(){
    return this->pop_front();
  }

  int size(){
    return this->size();
  }

  bool empty(){
    return this->empty();
  }
};