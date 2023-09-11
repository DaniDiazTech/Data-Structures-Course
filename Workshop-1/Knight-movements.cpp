// Made by @DaniDiazTech
#include <iostream>
#include <string>


template<typename t1, typename t2>struct Pair{
  t1 first;
  t2 second;
  Pair(){}
  Pair(t1 f, t2 s){
    first = f;
    second = s;
  }
};

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


  int a[9][9];
  
  std::string start, end;
  while (std::cin >> start){
    std::cin >> end; 

  }
}