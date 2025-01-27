#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll n, x, m;
    cin >> n >> x >> m;
    map<ll, ll> mv;
    ll lb = inf, ls = inf;
    rep(i, n) {
        if (mv.count(x) > 0) {
            lb = mv[x];
            ls = i - mv[x];
            break;
        }
        mv[x] = i;
        x = x * x % m;
    }
    ll ans = 0;
    for(auto &v : mv) {
        if (v.second < lb) {
            ans += v.first;
        }
        else {
            ans += v.first * ((n - v.second - 1) / ls + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
