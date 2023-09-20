#include <iostream>
// Use one stack or another
// #include "StackArray.h"
#include "StackLinkedList.h"

using namespace std;


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