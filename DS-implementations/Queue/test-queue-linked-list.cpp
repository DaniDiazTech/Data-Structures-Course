// Made by @DaniDiazTech
#include <iostream>
#include "QueueLinkedList.h"
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  Queue<int> q;
  for (int i =0 ;i < n; i++){
    q.enqueue(i);
  }
  for (int i =0 ;i < n; i++){
    q.dequeue();
  }
  return 0;
}