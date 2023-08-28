#include <iostream>
using namespace std;

template<typename T> struct Stack{
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
  
  T top(){
    if (empty()){
      throw "Stack is empty!";
    }
    return data[_top - 1];
  }
  
  void push(T element){
    if (size() == capacity){
      // create new array
      capacity *= 2;
      T* new_arr = new T[capacity];
      // Copy elements from data to new array
      for (int i = 0; i < size(); i++){
        new_arr[i] = data[i];
      }

      swap(data, new_arr);
      delete [] new_arr;
    }
    data[_top++] = element; 
  }

  T pop(){
    if (empty()){
      throw "Stack is empty!";
    }
    return data[--_top];
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  Stack<int> s;
  for (int i =0 ;i < n; i++){
    s.push(i);
  }
  return 0;
}