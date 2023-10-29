#include <iostream>
#include "Node.h"

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
      std::cout << node->element << " ";
      printInOrder(node->right);
    }
  }

  void printInOrder(){
    printInOrder(root);
  }

};