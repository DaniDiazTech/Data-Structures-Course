#include <iostream>

// Implementation of stack (linear data structure)

// top: O(1)
// push: O(1) (Amortized)
// pop: O(1)
// empty: O(1)
// size: O(1)

template<typename T> struct Stack{
  int _top, capacity;
  T *data;

  // Constructor
  Stack(){
    _top = 0;
    // Initial capacity: 16
    capacity = 16;
    data = new T[capacity];
  }

  bool empty(){
    return _top == 0;
  }

  int size(){
    return _top;
  }

  T top(){
    if (!empty())
      return data[_top - 1];
    else
      throw "Can't access element of empty Stack";
  }

  T pop(){
    if (empty())
      throw "Can't pop empty stack";
    return data[--_top];
  }

  void push(T element){
    if (capacity == size()){
      // Resize array
      capacity *= 2;
      T *new_data = new T[capacity];

      // Copy elements from previous array
      for (int i = 0; i < size(); i++){
        new_data[i] = data[i]; 
      }

      std::swap(data, new_data);
      delete [] new_data;
    }

    data[_top++] = element;
  }
};

// Auxiliary struct
// Keeps two elements of X and Y type
template<typename X, typename Y> struct Pair{
  X first;
  Y second;
  Pair(X f, Y s){
    first = f;
    second = s;
  }
  Pair(){
  }
};

// Overall complexity O(n)
// Each element is inserted at most once, and popped once in the stack 
int main(){
  int n;
  std::cin >> n;

  // Pair: height, position
  Stack<Pair<int, int>> min_stack;

  // Insert identity element
  min_stack.push(Pair<int,int>(0, 0));

  for (int i =1 ; i <= n; i++){
    int x; std::cin >> x;

    while (min_stack.top().first >= x){
      min_stack.pop();
    }
    std::cout << min_stack.top().second << " ";
    min_stack.push(Pair<int, int>(x, i)); 
  }
}
