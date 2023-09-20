// Made by @DaniDiazTech
#include <iostream>
#include <string>
#include "../DS-implementations/Queue/QueueLinkedList.h"
#include "../DS-implementations/Miscellaneous/Pair.h"

struct Move{
  int row, col;
  
  Move(int r, int c){
    row = r;
    col =c;
  }
  Move(){row = 0; col =0;};

  bool valid(int r, int c){
    int x= r + row;
    int y= c + col;
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
  }

  Pair<int, int> move(int r, int c){
    if (valid(r, c)){
      return Pair<int, int>(r + row, c + col);
    }
    else{
      return Pair<int, int>(-1,-1);
    }
  }
  
};


int main(){
  #if LOCAL
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
  #endif

  // fastinput
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);


  int vis[9][9];

  Move moves[8];
  moves[0] = Move(2, 1);
  moves[1] = Move(2, -1);

  moves[2] = Move(-2, 1);
  moves[3] = Move(-2, -1);
  
  moves[4] = Move(1, 2);
  moves[5] = Move(1, -2);

  moves[6] = Move(-1, 2);
  moves[7] = Move(-1, -2);

  std::string start, end;

  while (std::cin >> start){
    std::cin >> end; 
    for(int i =0 ;i < 8; i++){
      for(int j =0 ;j < 8; j++){
        vis[i][j] = 0;
      }
    }
    Pair<int, int> e(end[0] - 'a', (end[1] - '0') - 1);
    Pair<int, int> s(start[0] - 'a', (start[1] - '0') - 1);

    // coordinate, value 
    Queue<Pair<Pair<int,int>, int>> q;
    q.enqueue({s, 0});
    int mn = 1000;
    while (!q.empty()){
      auto top = q.dequeue();
      int x = top.first.first, y = top.first.second, val = top.second;
      if (x == e.first && y == e.second){
        mn = val;
        break;
      }
      for (int i =0; i < 8; i++){
        if (moves[i].valid(x,y)){
          Pair<int,int> p = moves[i].move(x,y);
          if (!vis[p.first][p.second]){
            vis[p.first][p.second] = 1;
            q.enqueue({p, val + 1});
          }
        }
      }
    }
    std::cout << "To get from " << start << " to " << end << " takes " << mn << " knight moves." << std::endl;
  }
}