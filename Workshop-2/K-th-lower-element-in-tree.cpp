#include <iostream>

#define ll long long

// Keeps two elements of X and Y type
template<typename X, typename Y> struct Pair{
  X first;
  Y second;
  Pair(X f, Y s){
    first = f;
    second = s;
  }
  Pair(){
  }
};



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




/* Node implementation of BST
Each node has 2 childs that can be null
*/

template< typename T >
struct Node{
  T element;
  Node *left, *right, *parent;

  Node(T el){
    element = el;
    parent = left = right = nullptr;
  }


  // Creates node with parent reference 
  Node(T el, Node *par){
    element = el;
    parent = par;
    left = right = nullptr;
  }

};

/*
Binary Search Tree (BST) implementation.

Property: Let u be a node member of the BST.
All nodes v < u: go to the left of u
v > u: go to the right of u.

let h = height of the tree.

insert(x): Insert element x in the BST O(h)
search(x): Search key x O(h)
remove(x): Remove key x from tree O(h)
printInOrder(x): Goes through the tree recursively and prints in order
*/

template< typename T >
struct BST{
  Node<T> *root;
  int _size;

  BST(){
    root = nullptr;
    _size = 0;
  }
  
  int size(){
    return _size;
  }

  bool empty(){
    return root == nullptr;
  }

  Node<T>* insert(Node<T> *node, T x){

    if (!root){
      return root = new Node<T>(x);
    }

    if (!node){
      return new Node<T>(x);
    }

    if (x > node->element){
      // go right
      node->right = insert(node->right, x);
      node->right->parent = node;
    } 
    else if (x < node->element){
      // go left
      node->left = insert(node->left, x);
      node->left->parent = node;
    }

    return node;
  }


  void insert(T x){
    insert(root, x);
    _size++;
  }
  
  // Returns pointer to Node with the element or null

  Node<T>* search(Node<T> *node, int x){
    if (node == nullptr) return nullptr;

    if (x == node->element){
      return node;
    }
    if (x > node->element){
      // right
      return search(node->right, x);
    }
    else{
      // left
      return search(node->left, x);
    }
  }

  Node<T>* search(int x){
    return search(root, x);
  }


  Node<T>* remove(Node<T> *node, int x){
    if (root == nullptr ) return nullptr;

    if (x > node->element ){
      // right
      node->right = remove(node->right, x);
    }
    else if ( x > node->element ){
      // left
      node->right = remove(node->left, x);
    }
    else {
      // Node has to be removed
      if ( node->left == nullptr ){
        return node->right;
      }
      else if ( node->right == nullptr){
        return node->left;
      }

      // Left and right not null
      Node<T>* parentSucc = node; 

      Node<T>* succ = node->right;
      while (succ->left != nullptr){
        parentSucc = succ;
        succ = succ->left;
      }

      if (parentSucc != root){
        parentSucc->left= succ->right;
      }
      else{
        parentSucc->right = succ->right;
      }

      node->data = succ->data;

      delete succ;

      return node;
    }
    return nullptr;
  }

  void remove(int x){
    remove(root, x);
  }

  void printInOrder(Node<T> *node){
    if (node != nullptr){
      printInOrder(node->left);
      std::cout << node->element << "\n";
      printInOrder(node->right);
    }
  }

  void printInOrder(){
    printInOrder(root);
  }

  // Return sorted arary
  void Sort(Node<T> *node, Vector<T>&v){
    if (node != nullptr){
      Sort(node->left, v);
      v.push_back(node->element);
      Sort(node->right, v);
    }
  }

  void Sort(Vector<T> &v){
    Sort(root, v);
  }

  void traverseOrder(Node<T> *node, Vector<Node<T>*> &v){
    if (node != nullptr){
      traverseOrder(node->left, v);
      v.push_back(node);
      traverseOrder(node->right, v);
    }
  }
  // Returns  
  Vector<Node<T>*> inOrderNodes(){
    Vector<Node<T>*> v;
    traverseOrder(root, v);
    return v;
  }
};

int main(){
  // fastinput
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  #if LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
  #endif

  ll u;
  Vector<ll> v;
  while (std::cin >> u){
    v.push_back(u);
  }

  ll k = v.back();
  v.pop_back(); 
  BST<ll> tree;
  for (int i = 0;i < v.size(); i++){
    tree.insert(v[i]);
  }
  auto a  = tree.inOrderNodes();
  auto ans = a[k - 1];
  std::cout << ans->element << " " << (ans->parent == nullptr ? -1 : ans->parent->element) << '\n';
}
