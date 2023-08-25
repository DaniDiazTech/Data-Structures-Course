#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Vector{
  int size = 16;
  int index;
  T objects;
};


template<typename T> struct Stack{
  int _top;
  Vector<T> data;
  Stack(){
    _top = 0; 
  }

  void push(T element){
    data[_top++] = element; 
  }

  T pop(){
    if (empty()){
      throw "Stack is empty!";
    }
    return data[--_top];
  }

  T top(){
    if (empty()){
      throw "Stack is empty!";
    }
    return data[_top - 1];
  }

  bool empty(){
    return _top == 0;
  }

  int size(){
    return _top;
  }
};


int main(){
  Stack<int> s;
}