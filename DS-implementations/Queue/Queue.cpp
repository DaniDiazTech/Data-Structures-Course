#include <iostream>

// Queue implementation

// First in first out : FIFO principle


// Methods
// enqueue: O(1) (amortized)
// dequeue: O(1) -> returns
// front: O(1)
// size: O(1)
// empty: O(1)


template<typename T> struct Queue{
  // front in place, back off by one
  int _front, _back, _size, capacity;

  T *data;
  Queue(){
    _front = _back = _size = 0;
    capacity = 16;
    data = new T[capacity];
  }

  int size(){
    return _size;
  }

  bool empty(){
    return size() == 0;
  }

  // returns front element
  T front(){
    if (empty())
      throw "Can't access empty queue";
    return data[_front];  
  }
  
  // Removes and returns front element
  T dequeue(){
    if (empty())
      throw "Can't dequeue on empty queue";
    _size--; 
    return data[_front++];
  }

  // Inserts element in back
  void enqueue(T element){

    if (size()== capacity){
      // Resize array
      T* new_data = new T[capacity * 2];

      for (int i = 0; i < size(); i++){
        new_data[i] = data[(i + _front) % capacity];
      }

      _front = 0;
      _back = capacity;
      capacity *= 2;
      std::swap(new_data, data);
      delete [] new_data;
    }
    _size++;
    data[_back++] = element;
  }

};