// Made by @DaniDiazTech
#include <iostream>
#include "QueueArray.h"

int main(){
  Queue<int> q;
  q.enqueue(1);
  q.enqueue(1);
  q.enqueue(1);
  q.enqueue(1);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(2);
  std::cout << q.dequeue() << std::endl;
  q.enqueue(3);
  std::cout << q.dequeue() << std::endl;
  q.print_array();
  std::cout << q.dequeue() << std::endl;
}