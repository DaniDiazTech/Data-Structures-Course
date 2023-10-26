#include <valarray>
#include <iostream>

// Int min heap

/*
Memory complexity: O(n)
push(n): Pushes element into the heap. O(log n)
pop(): Removes and returns root element O(log n)
top(): Return root element
*/

const int N = 2 * 1e5;

// Last element is located at position size. 0 element is not used
int bin[N];
int _size = 0;

void siftdown(int i){
  // gets minimum
  if ( 2 * i + 1 <= _size){
    if (bin[2 * i] < bin[2 * i + 1]){
      // swap right
      if ( bin[i] > bin[2 * i + 1]){
        std::swap(bin[i], bin[2 * i + 1]);
        siftdown( 2 * i + 1 );
      }
    }
    else {
      if ( bin[i] > bin[2 * i ]){
        std::swap(bin[i], bin[2 * i ]);
        siftdown( 2 * i );
      }
    }
  }
  else if ( 2 * i <= _size){
    if ( bin[i] > bin[2 * i ]){
      std::swap(bin[i], bin[2 * i ]);
      siftdown( 2 * i );
    }
  }
}

void siftup(int i){
  if ( i <= 1 ) return;
  if (bin[i] < bin[i / 2]){
    std::swap(bin[i], bin[i / 2]);
    siftup(i / 2);
  }
}

void push(int n){
  // insert in leaf
  bin[++_size] = n;
  siftup(_size);
}

int top(){
  return bin[1];
}

int pop(){
  int data = top();
  // swap with rightmost element
  std::swap(bin[1], bin[_size--]);
  siftdown(1);
  return data;
}

int size(){
  return _size;  
}

bool empty(){
  return size() == 0;
}

void print_heap(){
  std::cout << "HEAP:\n";
  for (int i = 1; i<=size();i++){
    std::cout << bin[i] << " ";
  }
  std::cout <<'\n';
}

void heapify(int a[], int n){
  _size = n;

  // heapify
  for (int i = 1;i <= n; i++){
    bin[i] = a[i - 1];
  }
  for (int i = size(); i >= 1; i--){
    siftdown(i);
  }
  
}