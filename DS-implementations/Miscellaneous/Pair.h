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