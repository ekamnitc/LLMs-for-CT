#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
int n;
int ans;

int dfs(int u, int p) {
  int mx = 0, mx2 = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    int val = dfs(v, u) + 1;
    if (val > mx) {
      mx2 = mx;
      mx = val;
    } else if (val > mx2) {
      mx2 = val;
    }
  }
  ans = max(ans, mx + mx2 + 1);
  return mx;
}

int main() {

  cin >> n;
  for (int i = 0; i+1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, -1);

  cout << (ans % 3 != 2 ? "First" : "Second") << endl;

  return 0;
}

