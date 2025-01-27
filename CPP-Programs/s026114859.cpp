#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int INF = 1001001001;

vector<int> to[100005], co[100005];


int main() {
    int n;
    cin >> n;
    rep(i,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        w %= 2;
        to[u].push_back(v); co[u].push_back(w);
        to[v].push_back(u); co[v].push_back(w);
    }
    vector<int> ans(n, INF);
    ans[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < to[v].size(); i++) {
            int u = to[v][i];
            int d = co[v][i];
            if (ans[u] != INF) continue;
            ans[u] = ans[v]^d;
            q.push(u);
        }
    }
    rep(i,n) printf("%d\n", ans[i]);
    return 0;
}