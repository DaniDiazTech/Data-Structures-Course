#include "../LinkedList/LinkedList.h"

// Queue inherits from LinkedList implementation
// First in first out : FIFO principle

// Methods
// enqueue: O(1) (amortized)
// dequeue: O(1) -> returns
// front: O(1)
// size: O(1)
// empty: O(1)


template<typename T> struct Queue: LinkedList<T>{
  Queue(){}; 
  void enqueue(T el){
    this->push_back(el);
  }
  T dequeue(){
    return this->pop_front();
  }
};