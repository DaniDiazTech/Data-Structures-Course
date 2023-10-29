
/*
DSU (disjoint set) data structure
Solves connectivity problems and lets perform
calculations of commutative operations in disjoint set

get(u): returns id of u
union(u, v): merges nodes u and v
*/


struct DSU{
  int *par;
  int *rank;
  int *sz;

  // max n
  DSU(int n){
    par = new int[n];
    rank = new int[n];
    sz = new int[n];

    for (int i = 0 ;i < n; i++){
      par[i] = i;
      rank[i] = 0;
      sz[i] = 1;
    }
  }

  int get(int u){
    return par[u] = (par[u] == u ? u : get(par[u]));
  }

  void unionSet(int u, int v){
    int x = get(u);
    int y = get(v);
    if (x==y) return;
    if (rank[x] == rank[y]) rank[x]++; 
    if (rank[x] > rank[y]){
      par[y] = x;
      sz[x] += sz[y];
    }
    else{
      par[x] = y;
      sz[y] += sz[x];
    }
  }

  int size(int u){
    return sz[get(u)]; 
  }
};
