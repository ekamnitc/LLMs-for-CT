#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int root[maxn];

int dsu_find (int u) {
    if (u == root[u])
        return u;
    return root[u] = dsu_find(root[u]);
}

void dsu_unite (int u, int v) {
    u = dsu_find(u), v = dsu_find(v);
    if (u != v) {
        if (rand() & 1)
            swap(u, v);
        root[u] = v;
    }
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        root[i] = i;
    vector < int > p(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        dsu_unite(x, y);
    }
    map < int, pair < set < int >, set < int > > > roadmap;
    for (int i = 1; i <= n; ++i) {
        roadmap[dsu_find(i)].first.insert(i);
        roadmap[dsu_find(i)].second.insert(p[i]);
    }
    int ans = 0;
    for (auto pr: roadmap) {
        for (auto x: pr.second.first) {
            if (pr.second.second.find(x) != pr.second.second.end())
                ++ans;
        }
    }
    cout << ans << '\n';
}
