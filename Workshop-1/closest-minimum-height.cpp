// Made by @DaniDiazTech
// Need to copy and past DS implementations to send to online judge

#include <iostream>
// #include "../DS-implementations/Stack/StackArray.h"
#include "../DS-implementations/Stack/StackLinkedList.h"
#include "../DS-implementations/Miscellaneous/Pair.h"

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
  std::cout << std::endl;
}
