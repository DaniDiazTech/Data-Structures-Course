#include <valarray>
#include <iostream>

#define ll long long

// Int min heap

/*
Memory complexity: O(n)
push(n): Pushes element into the heap. O(log n)
pop(): Removes and returns root element O(log n)
top(): Return root element
*/

const int N = 2 * 1e6;

// Last element is located at position size. 0 element is not used
ll bin[N];
int _size = 0;

void siftdown(int i){
  // gets minimum
  if ( 2 * i + 1 <= _size){
    if (bin[2 * i] < bin[2 * i + 1]){
      // swap right
      if ( bin[i] > bin[2 * i ]){
        std::swap(bin[i], bin[2 * i ]);
        siftdown( 2 * i  );
      }
    }
    else {
      if ( bin[i] > bin[2 * i + 1 ]){
        std::swap(bin[i], bin[2 * i + 1 ]);
        siftdown( 2 * i  + 1);
      }
    }
  }
  else if ( 2 * i <= _size){
    if ( bin[i] > bin[2 * i ]){
      std::swap(bin[i], bin[2 * i ]);
      siftdown( 2 * i );
    }
  }
}

void siftup(int i){
  if ( i <= 1 ) return;
  if (bin[i] < bin[i / 2]){
    std::swap(bin[i], bin[i / 2]);
    siftup(i / 2);
  }
}

void push(int n){
  // insert in leaf
  bin[++_size] = n;
  siftup(_size);
}

ll top(){
  return bin[1];
}

ll pop(){
  ll data = top();
  // swap with rightmost element
  std::swap(bin[1], bin[_size--]);
  siftdown(1);
  return data;
}

int size(){
  return _size;  
}

bool empty(){
  return size() == 0;
}

void print_heap(){
  std::cout << "HEAP:\n";
  for (int i = 1; i<=size();i++){
    std::cout << bin[i] << " ";
  }
  std::cout <<'\n';
}

void heapify(ll a[], int n){
  _size = n;

  // heapify
  for (int i = 1;i <= n; i++){
    bin[i] = a[i - 1];
  }
  for (int i = size(); i >= 1; i--){
    siftdown(i);
  }
  
}


int main(){
  // fastinput
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  #if LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
  #endif

  ll n, k; std::cin >> n >> k;
  ll a[n];
  for (int i =0 ;i < n; i++){
    std::cin >> a[i];
  }
  heapify(a, n);
  
  int cnt = 0;
  while (size() >= 2 && top() < k){
    ll first = pop();
    ll second = pop();
    push( (first + 2 * second)  );
    cnt++;
  }
  if (size() && top() >= k){
    std::cout << cnt;
  }
  else{
    std::cout << "-1";
  }
}
