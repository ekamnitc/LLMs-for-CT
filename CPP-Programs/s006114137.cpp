#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef complex<double> P;

int main() {
  int n, m; cin >> n >> m;
  vector<int> adj[n];

  for (int i = 0; i < m; i++) {
    int v, u; cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  int sd[n] = {1};
  queue<int> que;
  que.push(0);
  int c = 1;

  while (!que.empty()) {
    int v = que.front(); que.pop();

    for (int i = 0; i < adj[v].size(); i++) {
      if(!sd[adj[v][i]]) {
        que.push(adj[v][i]);
        sd[adj[v][i]] = c;
      }
    }

    if(que.empty()) {
      for (int i = 0; i < n; i++) {
        if(!sd[i]) {
          sd[i] = ++c;
          que.push(i);
          break;
        }
      }
    }

  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int s, t; cin >> s >> t;
    if(sd[s] == sd[t]) {
      cout << "yes" << endl;
    }
    else {
      cout << "no" << endl;
    }
  }
}