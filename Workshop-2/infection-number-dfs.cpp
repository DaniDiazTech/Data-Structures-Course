// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
// U D L R 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


// Vector array implementation

// - `back()`: Returns the element at the back of the vector.
// - `push_back()`: Inserts an element at the back of the vector.
// - `pop_back()`: Takes out the element at the top of the stack and returns it.
// - `size()`: Returns an integer, the number of elements the stack currently stores.
// - `empty()`: You guessed it! Returns a boolean indicating if the stack is empty or not.

template<typename T> struct Vector{
  int _top, capacity;
  T* data;

  Vector(){
    _top = 0; 
    capacity = 16;
    data = new T[capacity];
  }

  bool empty(){
    return _top == 0;
  }

  int size(){
    return _top;
  }
  
  T back(){
    if (empty()){
      throw std::out_of_range("Stack is empty");
    }
    return data[_top - 1];
  }
  
  T& operator[](size_t  i){
    
    if (i < 0 || i >= size()){
        throw std::out_of_range("Out of range");
    }

    return data[i];

  }
  
  void push_back(T element){
    if (size() == capacity){
      // create new array
      capacity *= 2;
      T* new_arr = new T[capacity];
      // Copy elements from data to new array
      for (int i = 0; i < size(); i++){
        new_arr[i] = data[i];
      }

      std::swap(data, new_arr);
      delete [] new_arr;
    }
    data[_top++] = element; 
  }

  T pop_back(){
    if (empty()){
      throw std::out_of_range("Vector is empty");
    }
    return data[--_top];
  }
  
  void clear(){
    _top = 0; 
    capacity = 16;
    data = new T[capacity];
  }
};

const int N = 30005;

Vector<int> g[N];
int vis[N];

int n, m;

int dfs(int u){
    vis[u] = 1;
    int cnt = 1;
    
    for (int i = 0 ; i < g[u].size(); i++){
        int  x = g[u][i];
        if (vis[x]) continue;
        cnt += dfs(x);
    }
    
    return cnt;
}


int32_t main() {
    
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    
    while (cin >> n){
        if ( n == 0 ) break;
        cin >> m;
        for (int i = 0 ; i <= n; i++){
            g[i].clear();
            vis[i] = 0 ;
        }
        
        for (int i = 0 ; i < m; i++){
            int k; cin >> k;
            int l;
            if (k > 0) cin >>l ;
            for (int j = 0 ; j < k - 1; j++){
                int x; cin >> x;
                g[l].push_back(x);
                g[x].push_back(l);
            }
        }
        
        cout << dfs(0)  << '\n';
    }
    
    
    return 0;
}