// Made by @Danidiaztech
#include <iostream>

const int N = 2e5;
int pre[N], in[N];

void post(int pl, int pr, int inl, int inr){
  if (pl > pr || inl > inr) return;

  int u = pre[pl];
  int pos = -1;
  for (int i = inl; i <= inr; i++){
    if (in[i] == u){
      pos = i;
      break;
    }
  }
  
  post(pl + 1, pr, inl, pos - 1);
  post(pl + (pos - inl) + 1, pr, pos + 1, inr);

  std::cout << u << ' ';

}

int main(){

  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n; std::cin >> n ;
  for (int i = 0;i < n; i++){
    std::cin >> pre[i];
  }
  for (int i = 0;i < n; i++){
    std::cin >> in[i];
  }

  post(0, n - 1, 0, n - 1); 
  std::cout << '\n';

}