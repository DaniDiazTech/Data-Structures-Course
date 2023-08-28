#include <iostream>
#include <stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int cnt = 0;
  for (int i =0 ;i < n; i++){
    for (int j =0 ; j < n; j++){
      cnt++;
    }
  }
  return 0;
}