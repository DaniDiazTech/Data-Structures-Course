#include <iostream>
#include <stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  stack<int> s;
  for (int i =0 ;i < n; i++){
    s.push(i);
  }
}