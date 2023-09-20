// Made by @DaniDiazTech
#include <iostream>
#include <string>
#include <queue>

// Implementation with STD queue
int main(){
  #if LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
  #endif
  // fastinput
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  int mx = 1e6 + 10;

  // Uses an array as map
  int mp[mx];
  int scene = 1;
  while (std::cin >> n){
    if (n == 0) break;
    std::cout << "Scenario #" << scene << std::endl;

    std::queue<int> teams[n];
    std::queue<int> cur;

    for (int i = 0 ; i < n; i++){
      int l;
      std::cin>> l;
      for (int j = 0; j < l; j++){
        int x; std::cin >> x;
        // membership of the team
        mp[x] = i;
      }
    }

    std::string s;
    while (std::cin >> s){
      if (s[0] == 'S'){
        break;
      }
      if (s[0] == 'E'){
        // enqueue
        int x; std::cin >>x;
        int team = mp[x];
        if (teams[team].empty()){
          cur.push(team);
        }
        teams[team].push(x);
      }
      else{
        // dequeue
        std::cout << teams[cur.front()].front() << std::endl;
      teams[cur.front()].pop();
        if (teams[cur.front()].empty()){
          cur.pop();
        }
      }
    }
    scene++;
    std::cout << std::endl;
  }
}
