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

// Queue implementation

// First in first out : FIFO principle


// Methods
// enqueue: O(1) (amortized)
// dequeue: O(1) -> returns
// front: O(1)
// size: O(1)
// empty: O(1)

template<typename T> struct Queue{
  // front in place, back off by one
  int _front, _back, _size, capacity;

  T *data;
  Queue(){
    _front = _back = _size = 0;
    capacity = 16;
    data = new T[capacity];
  }

  int size(){
    return _size;
  }

  bool empty(){
    return size() == 0;
  }

  // returns front element
  T front(){
    if (empty())
      throw "Can't access empty queue";
    return data[_front];  
  }
  
  // Removes and returns front element
  T dequeue(){
    if (empty())
      throw "Can't dequeue on empty queue";
    _size--; 
    T el = data[_front];
    _front = (_front + 1) % capacity;
    return el;
  }

  // Inserts element in back
  void enqueue(T element){

    if (size()== capacity){
      // Resize array
      T* new_data = new T[capacity * 2];

      for (int i = 0; i < size(); i++){
        new_data[i] = data[(i + _front) % capacity];
      }

      _front = 0;
      _back = capacity;
      capacity *= 2;
      std::swap(new_data, data);
      delete [] new_data;
    }
    _size++;
    data[_back] = element;
    _back = (_back + 1) % capacity;
  }

  void print_array(){
    for (int i = 0 ; i < capacity; i++){
      std::cout << data[i] << " ";
    }
    std::cout << std::endl;
  }

};



int main(){
  #if LOCAL
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
  #endif


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