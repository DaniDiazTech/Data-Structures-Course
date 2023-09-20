template<typename T> struct Node{
  T element;

  Node *next;
  Node *parent;

  Node(){
    next = parent = nullptr;
  }

  Node(T el){
    Node();
    element = el;
  }

  Node(T el, Node *nxt){
    element = el;
    next = nxt;
  }

  Node(T el, Node *nxt, Node *par){
    element = el;
    next = nxt;
    parent = par;
  }
};

