// Made by @DaniDiazTech
#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  queue<int> q;
  for (int i =0 ;i < n; i++){
    q.push(i);
  }
  for (int i =0 ;i < n; i++){
    q.pop();
  }
  return 0;
}