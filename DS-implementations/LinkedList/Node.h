template<typename T> struct Node{
  T element;

  Node *next;
  Node *prev;

  Node(){
    next = prev = nullptr;
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
    prev = par;
  }
};

