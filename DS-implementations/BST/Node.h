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