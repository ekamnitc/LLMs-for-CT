#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll mod = 1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

using Edge = pair<int,int>;
using Graphy = vector<vector<Edge> >;

int n;
Graphy g;

void dfs(int v, int p, int pc, vector<int> &res) {
  int c = 1;
  if (c == pc) c++;
  for (auto e : g[v]) {
    if (e.first == p) continue;
    res[e.second] = c;
    dfs(e.first, v, c, res);
    c++;
    if (c == pc) c++;
  }
}

int main() {
  cin >> n;
  g.assign(n, vector<Edge>());
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b,i);
    g[b].emplace_back(a,i);
  }
  int mc = 0;
  rep(i,n) {
    mc = max(mc,(int)g[i].size());
  }
  vector<int> res(n-1,-1);

  dfs(0,-1,-1,res);

  cout << mc << endl;
  for (auto u : res) cout << u << endl;

  return 0;
}
