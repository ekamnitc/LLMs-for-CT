#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

using Graph = V<V<int>>;
Graph g;
V<bool> seen;
int n, m;
int ans = 0, cnt = 0;

void dfs(int v) {
    seen[v] = true;
    cnt++;
    if(cnt == n) ans++;
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        dfs(next_v);
    }
    cnt--;
    seen[v] = false;
}

int main() {
    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    seen.resize(n);
    dfs(0);
    cout << ans << endl;


    return 0;
}
