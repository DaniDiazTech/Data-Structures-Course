// Made by @DaniDiazTech
#include <iostream>
#include <string>
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

template<typename X, typename Y> struct Pair{
  X first;
  Y second;
  Pair(){
  }

  Pair(X f, X s){
    first = f;
    second = s;
  }
};


int main(){
  #if LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
  #endif

  int n;
  int mx = 1e6 + 10;

  // Uses an array as map
  int mp[mx];
  int scene = 1;
  while (std::cin >> n){
    if (n == 0) break;
    std::cout << "Scenario #" << scene << std::endl;

    Queue<int> teams[n];
    Queue<int> cur;

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
          cur.enqueue(team);
        }
        teams[team].enqueue(x);
      }
      else{
        // dequeue
        std::cout << teams[cur.front()].dequeue() << std::endl;
        if (teams[cur.front()].empty()){
          cur.dequeue();
        }
      }
    }
    scene++;
    std::cout << std::endl;
  }
}
