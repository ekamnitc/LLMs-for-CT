#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

vector<vector<int>> G;

int main() {
  int n;
  cin >> n;

  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  priority_queue<int> que;
  for (int i = 0; i < n; i++) {
    int c; cin >> c;
    que.push(c);
  }

  queue<int> q;
  vector<int> visited(n, false);
  q.push(0);
  visited[0] = true;

  vector<int> answer(n);
  answer[0] = que.top();
  que.pop();

  int sum = 0;
  while(!q.empty()) {
    int from = q.front();
    q.pop();

    for (int i = 0; i < (int)G[from].size(); i++) {
      int to = G[from][i];
      if(visited[to]) continue;
      answer[to] = que.top();
      sum += que.top();
      que.pop();
      visited[to] = true;
      q.push(to);
    }
  }

  cout << sum << '\n';
  for (auto it : answer) {
    cout << it << " ";
  }
  cout << '\n';
}
