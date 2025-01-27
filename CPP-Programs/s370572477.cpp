#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N + 1);
  vector<int> par(N + 1), deg(N + 1);
  rep(i, 0, N + M - 1) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    deg[t]++;
  }
  queue<int> Q;
  rep(i, 1, N + 1) if (!deg[i]) Q.push(i);
  while(!Q.empty()) {
    int v = Q.front(); Q.pop();
    for(auto p : G[v]) {
      deg[p]--;
      par[p] = v;
      if(!deg[p]) Q.push(p);
    }
  }
  rep(i, 1, N + 1) cout << par[i] << endl;
  return 0;
}
