// Made by @DaniDiazTech
#include <iostream>

// Implementation of AVLTree

/*
AVL methods
- Insert, Remove, Find, contains,  Balance: O(log n)
*/

// T needs to have > and < comparator operations
template<typename T> struct Node{
  T value;

  // Balance factor
  int bf;

  // Height of the node, if leaf 1
  int height;

  // Frequency of the value
  int frequency;

  Node<T> *left;
  Node<T> *right;

  // Initially a leaf
  Node(){
    left = right = nullptr;
    bf = 0;
    height = 1;
    frequency = 1;
  }

  Node(T el){
    left = right = nullptr;
    bf = 0;
    height = 1;
    frequency = 1;

    value = el;
  }
};

template<typename T> struct AVLTree{
  Node<T> *root;
  
  int _size;

  AVLTree(){
    _size = 0;
    root = nullptr;
  }

  // Hight of rooted tree
  int height(){
    if (root == nullptr) return 0;
    return root->height;
  }

  int size(){
    return _size;
  }

  bool empty(){
    return size() == 0;
  }

  // Returns node if found
  Node<T>* find(Node<T>* u , T value){
    if (u == nullptr) return nullptr;

    // Search in left subtree
    if (u->value > value){
      return find(u->left, value);
    }
    
    // Search in right subtree
    if (u->value < value){
      return find(u->right, value);
    }

    // Found element
    return u;
  }

  bool count(T value){
    Node<T>* u = find(root, value);
    if (u == nullptr) return 0;
    return u->frequency;
  }

  bool contains(T value){
    return count(value) > 0;
  }

  void update(Node<T>* u){
    int leftNodeHeight = (u->left == nullptr) ? 0: u->left->height;
    int rightNodeHeight = (u->right == nullptr) ? 0: u->right->height;

    u->height = 1 + (leftNodeHeight > rightNodeHeight ? leftNodeHeight : rightNodeHeight);
    u->bf = rightNodeHeight - leftNodeHeight;
  }

  Node<T>* leftLeftCase(Node<T>* u){
    return rightRotation(u);
  }

  Node<T>* leftRightCase(Node<T>* u){
    u->left = leftRotation(u->left);
    return leftLeftCase(u);
  }

  Node<T>* rightRightCase(Node<T>* u){
    return leftRotation(u);
  }

  Node<T>* rightLeftCase(Node<T>* u){
    u->right = rightRotation(u->right);
    return rightRightCase(u);
  }

  Node<T>* leftRotation(Node<T>* u){
    Node<T>* newParent = u->right;
    u->right = newParent->left;
    newParent->left = u;

    update(u);
    update(newParent);
    return newParent;
  }

  Node<T>* rightRotation(Node<T>* u){
    Node<T>* newParent = u->left; 
    u->left = newParent->right;
    newParent->right = u;

    update(u);
    update(newParent);

    return newParent;
  }

  Node<T>* balance(Node<T>* u){
    if (u->bf == -2){
      if ( u->left->bf <= 0){
        return leftLeftCase(u);
      }
      else{
        return leftRightCase(u);
      }
    }
    else if (u->bf == 2){
      if (u->right->bf >= 0){
        return rightRightCase(u);
      }
      else return rightLeftCase(u);
    }

    // No need to balance
    return u;
  }

  // Returns new node
  Node<T>* insert(Node<T>* u, T value){
    if (u == nullptr) return new Node<T>(value);

    // Insert in left subtree
    if (u->value > value){
      u->left =  insert(u->left, value);
    }
    else{
      // Insert in right subtree
      u->right = insert(u->right, value);
    }

    update(u);

    return balance(u);
  }

  // Insert value to the tree
  // Returns true if inserted in new leaf
  bool insert(T value){

    Node<T>* u = find(root, value);
    _size++;
    if (u == nullptr){
      // perform new insetion in a leaf
      root = insert(root, value);
      return true;
    }
    else{
      // Found and increment
      u->frequency++;
      return true;
    }
    return false;
  }

  // Removes a value from the AVL tree->
  Node<T>* remove(Node<T>* node, T elem) {
    // Explore left
    if (node->value > elem){
      node->left = remove(node->left, elem);
    }
    // Explore right
    else if (node->value < elem){
      node->right = remove(node->right, elem);
    }
    else{
      if (node->left == nullptr) {
        return node->right;

      } else if (node->right == nullptr) {
        return node->left;
      } else {

        // Choose to remove from left subtree
        if (node->left->height > node->right->height) {

          // Swap the value of the successor into the node->
          T successorValue = getMax(node->left);
          node->value = successorValue;

          // Find the largest node in the left subtree->
          node->left = remove(node->left, successorValue);

        } else {

          T successorValue = getMin(node->right);
          node->value = successorValue;
          node->right = remove(node->right, successorValue);
        }
      }
    }
    
    // Update balance factor and height values
    update(node);

    return balance(node);
  }



  bool remove(T value){
    Node<T>* u = find(root, value);

    if (u != nullptr){
      _size--;
      if (u->frequency > 1){
        u->frequency--;
        return true;
      }
      root = remove(root, value);
      return true;
    }
    return false;
  }

  T getMin(Node<T> *u){
    while (u->left != nullptr) u = u->left;
    return u->value;
  }

  T getMax(Node<T> *u){
    while (u->right != nullptr) u = u->right;
    return u->value;
  }

  T getMin(){
    return getMin(root);
  }

  T getMax(){
    return getMax(root);
  }

  void preOrder(Node<T> *u){
    if (u == nullptr) return;
    std::cout << u->value << ' ';
    preOrder(u->left);
    preOrder(u->right);
  }

  void inOrder(Node<T> *u){
    if (u == nullptr) return;
    inOrder(u->left);
    std::cout << u->value << ' ';
    inOrder(u->right);
  }
  void postOrder(Node<T> *u){
    if (u == nullptr) return;
    postOrder(u->left);
    postOrder(u->right);
    std::cout << u->value << ' ';
  }

  void printSorted(){
    inOrder(root);
    std::cout << '\n';
  }

  void printOrders(){
    preOrder(root);
    std::cout << '\n';
    inOrder(root);
    std::cout << '\n';
    postOrder(root);
    std::cout << '\n';
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

  // let b1 have all the elements including the median and before the median
  // let b2 have the element after the median
  AVLTree<int> b1, b2;

  int n, k;
  std::cin >> n >> k;
  int a[n];
  for (int i = 0;i < n; i++) std::cin >> a[i];

  // First window
  for (int i =0 ;i < k; i++){
    b1.insert(a[i]);
  }

  for (int i =0;i < k / 2; i++){
    int u = b1.getMax();
    b2.insert(u);
    b1.remove(u);
  }

  int b1size = (k + 1) / 2;
  // Keeping the invariant
  for (int i = 0; i <= n - k; i++){
    if (i > 0){
      // remove a i - 1, insert a i
      if (a[i - 1] > b1.getMax()){
        b2.remove(a[i - 1]);
      }
      else{
        b1.remove(a[i - 1]);
      }

      if (b1.empty() && !b2.empty()){
        int u = b2.getMin();
        b1.insert(u);
        b2.remove(u);
      }

      if (!b1.empty() && b1.getMax() < a[i + k - 1]){
        // insert in b2
        b2.insert(a[i + k - 1]);   
      }
      else b1.insert(a[i + k - 1]);

      // Balance
      while (b1.size() > b1size){
        int u = b1.getMax();
        b2.insert(u);
        b1.remove(u);
      }

      while(b1.size() < b1size){
        int u = b2.getMin();
        b1.insert(u);
        b2.remove(u);
      }
    }
    std::cout << b1.getMax() << ' ';
  }
  std::cout << '\n';
}
