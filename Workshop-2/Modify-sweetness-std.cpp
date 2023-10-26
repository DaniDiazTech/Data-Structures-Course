// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n, k;
  cin >> n >> k;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i =0 ;i <n ; i++){
    ll x; cin >> x;
    pq.push(x);
  }
  int cnt = 0;
  while (pq.size() >= 2 && pq.top() < k){
    ll x = pq.top();
    pq.pop();
    ll y = pq.top();
    pq.pop();
    pq.push(x + 2 * y);
    cnt++;
  }
  if (!pq.empty() && pq.top() >= k){
    cout << cnt;
  }
  else cout << -1;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
