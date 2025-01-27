#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    REP(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> path;
    vector<bool> used(n);
    auto dfs = [&](auto &&self, ll v, ll p) -> void {
        path.push_back(v);
        used[v] = true;
        for(auto to: g[v]) {
            if(!used[to]) {
                self(self, to, v);
                break;
            }
        }
    };

    vector<ll> ans;
    ll idx0 = 0, idx1 = g[0][0];
    used[idx0] = used[idx1] = true;

    dfs(dfs, idx0, -1);
    reverse(ALL(path));
    ans = path;

    path.clear();
    dfs(dfs, idx1, -1);
    for(auto i: path) ans.push_back(i);

    cout << ans.size() << "\n";
    REP(i, ans.size()) cout << ans[i]+1 << (i+1==ans.size() ? '\n' : ' ');

    return 0;
}