#include "../LinkedList/LinkedList.h"

// Queue inherits from LinkedList implementation
// First in first out : FIFO principle

// Methods
// enqueue: O(1) 
// dequeue: O(1) -> returns
// front: O(1)
// size: O(1)
// empty: O(1)


template<typename T> struct Queue: LinkedList<T>{
  private:
    using LinkedList<T>::push_front;
    using LinkedList<T>::push_back;
    using LinkedList<T>::pop_front;
    using LinkedList<T>::pop_back;
    using LinkedList<T>::back;

  public:
    using LinkedList<T>::size;
    using LinkedList<T>::front;
    using LinkedList<T>::empty;
    
    Queue(){}; 
    void enqueue(T el){
      this->push_back(el);
    }
    T dequeue(){
      return this->pop_front();
    }
};