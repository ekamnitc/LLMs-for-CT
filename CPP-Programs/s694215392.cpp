#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

using Graph = vector<vector<int>>; // グラフ

// トポロジカルソートする
void rec(int v, vector<vector<int>> const &G, vector<bool> &seen, vector<int> &order) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (seen[next]) continue; // 既に訪問済みなら探索しない
    rec(next, G, seen, order);
  }
  order.push_back(v);
}

int main() {
  int v,e;
  cin >> v >> e;
  vector<vector<int>> g(v);
  rep(i, e) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  vector<bool> seen(v, 0);
  vector<int> order;
  rep(i, v) {
    if (seen[i]) continue;
    rec(i, g, seen, order);
  }

  reverse(order.begin(), order.end());

  for (auto itr : order) cout << itr << "\n";
  cout << flush;
}
