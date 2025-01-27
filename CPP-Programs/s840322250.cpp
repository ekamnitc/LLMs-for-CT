#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const int MAX = 111;

int N;
vector<pair<double, double>> vec;

ld solve() {
    vector<tuple<ld, ll, ll>> order;
    REP (i, N) order.PB(MT(atan2(vec[i].first, vec[i].second), vec[i].first, vec[i].second));
    sort(ALL(order));
    ll res = 0;
    REP (left, N) {
        ll x = 0, y = 0;
        FOR (right, left, left+N) {
            x += get<1>(order[right%N]);
            y += get<2>(order[right%N]);
            res = max(res, x*x + y*y);
        }
    }
    return sqrt(res);
}

int main() {
    cin >> N;
    REP (i, N) {
        int x, y; cin >> x >> y;
        vec.PB(MP(x, y));
    }
    cout << setprecision(15) << solve() << endl;
}