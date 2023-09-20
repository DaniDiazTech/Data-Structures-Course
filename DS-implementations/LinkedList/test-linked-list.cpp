#include <iostream>
#include "./LinkedList.h"

int main(){
  int n = 5;
  LinkedList<int> l;
  srand(time(NULL));
  for (int i =0 ;i < n; i++){
    l.push_back(i % 10);
  }
  for (int i =0 ;i < n; i++){
    l.push_front(i % 10);
  }
  while (!l.empty()){
    std::cout << l.pop_front() << std::endl;
    std::cout << l.pop_back() << std::endl;
  }
}
