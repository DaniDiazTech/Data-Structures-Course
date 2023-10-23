// Vector array implementation

// - `back()`: Returns the element at the back of the vector.
// - `push_back()`: Inserts an element at the back of the vector.
// - `pop_back()`: Takes out the element at the top of the stack and returns it.
// - `size()`: Returns an integer, the number of elements the stack currently stores.
// - `empty()`: You guessed it! Returns a boolean indicating if the stack is empty or not.

template<typename T> struct Vector{
  int _top, capacity;
  T* data;

  Stack(){
    _top = 0; 
    capacity = 16;
    data = new T[capacity];
  }

  bool empty(){
    return _top == 0;
  }

  int size(){
    return _top;
  }
  
  T back(){
    if (empty()){
      throw std::out_of_range("Stack is empty");
    }
    return data[_top - 1];
  }
  
  T& operator[](size_t  i){
    
    if (i < 0 || i >= size()){
        throw std::out_of_range("Out of range");
    }

    return data[i];

  }
  
  void push_back(T element){
    if (size() == capacity){
      // create new array
      capacity *= 2;
      T* new_arr = new T[capacity];
      // Copy elements from data to new array
      for (int i = 0; i < size(); i++){
        new_arr[i] = data[i];
      }

      std::swap(data, new_arr);
      delete [] new_arr;
    }
    data[_top++] = element; 
  }

  T pop_back(){
    if (empty()){
      throw std::out_of_range("Vector is empty");
    }
    return data[--_top];
  }
};